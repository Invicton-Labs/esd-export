/**
 * This source code ("the Software") is provided by Bridgetek Pte Ltd
 * ("Bridgetek") subject to the licence terms set out
 *   http://brtchip.com/BRTSourceCodeLicenseAgreement/ ("the Licence Terms").
 * You must read the Licence Terms before downloading or using the Software.
 * By installing or using the Software you agree to the Licence Terms. If you
 * do not agree to the Licence Terms then do not download or use the Software.
 *
 * Without prejudice to the Licence Terms, here is a summary of some of the key
 * terms of the Licence Terms (and in the event of any conflict between this
 * summary and the Licence Terms then the text of the Licence Terms will
 * prevail).
 *
 * The Software is provided "as is".
 * There are no warranties (or similar) in relation to the quality of the
 * Software. You use it at your own risk.
 * The Software should not be used in, or for, any medical device, system or
 * appliance. There are exclusions of Bridgetek liability for certain types of loss
 * such as: special loss or damage; incidental loss or damage; indirect or
 * consequential loss or damage; loss of income; loss of business; loss of
 * profits; loss of revenue; loss of contracts; business interruption; loss of
 * the use of money or anticipated savings; loss of information; loss of
 * opportunity; loss of goodwill or reputation; and/or loss of, damage to or
 * corruption of data.
 * There is a monetary cap on Bridgetek's liability.
 * The Software may have subsequently been amended by another user and then
 * distributed by that other user ("Adapted Software").  If so that user may
 * have additional licence terms that apply to those amendments. However, Bridgetek
 * has no liability in relation to those amendments.
 */

#include "EVE_Util.h"
#include "EVE_Platform.h"
#include "EVE_HalImpl.h"


#if (defined(_WIN32) || defined(__linux__))

/* Interactive platform selection */
static const char *s_HostDisplayNames[EVE_HOST_NB] = {
	"<Unknown>",

	"BT8XX Emulator",
	"FT4222",
	"MPSSE",
	"Embedded",
};

#define EVE_SELECT_CHIP_NB 15


#endif

/**********************
** INTERACTIVE SETUP **
**********************/

#if (defined(_WIN32) || defined(__linux__))

void EVE_Util_selectDeviceInteractive(EVE_CHIPID_T *chipId, size_t *deviceIdx)
{
	char buf[1024];
	EVE_DeviceInfo info;
	int selectedDeviceIdx;
	size_t deviceCount;
	size_t i;

SELECTDEVICE:
	deviceCount = EVE_Hal_list();
	size_t realDeviceCount = 0;
	for (i = 0; i < deviceCount; ++i)
	{
		EVE_Hal_info(&info, i);
		if (info.Host)
		{
			++realDeviceCount;
			*deviceIdx = i;
		}
	}
	if (realDeviceCount > 1)
	{
		buf[0] = '\0';
		printf("Select a device:\n");
		for (i = 0; i < deviceCount; ++i)
		{
			EVE_Hal_info(&info, i);
			if (info.Host)
				printf("- [%d] %s (%s, %s)\n", (unsigned int)i, info.DisplayName, s_HostDisplayNames[info.Host], info.SerialNumber);
		}
		fgets(buf, sizeof(buf), stdin);
#ifdef _WIN32
		if (sscanf_s(buf, "%i", &selectedDeviceIdx) != 1)
#else
		if (sscanf(buf, "%i", &selectedDeviceIdx) != 1)
#endif
			goto SELECTDEVICE;
		*deviceIdx = selectedDeviceIdx;
		EVE_Hal_info(&info, *deviceIdx);
		if (!info.Host)
			goto SELECTDEVICE;
		printf("\n");
	}
	else if (realDeviceCount > 0)
	{
		EVE_Hal_info(&info, *deviceIdx);
		printf("%s (%s, %s)\n", info.DisplayName, s_HostDisplayNames[info.Host], info.SerialNumber);
	}
	else
	{
		*deviceIdx = -1;
		*chipId = EVE_SUPPORT_CHIPID;
		return;
	}

	*chipId = EVE_SUPPORT_CHIPID;
}


#endif

#if defined(_WIN32) || defined(__linux__)
void EVE_Util_selectFlashFileInteractive(eve_tchar_t *flashPath, size_t flashPathSize, bool *updateFlash, bool *updateFlashFirmware, const EVE_HalParameters *params, const eve_tchar_t *flashFile)
{
	size_t flashPathSz;
#ifdef _WIN32
	errno_t ferr;
#endif
	FILE *f = NULL;

SELECTFLASH:
	*updateFlash = false;
	*updateFlashFirmware = false;
	if (flashFile)
	{
		uint8_t buffer[4096];
		{
			/* Query user if they want to update the flash file on the device */
			printf("Upload flash image (y/n, or press ENTER to skip):\n");
			buffer[0] = '\0';
			fgets((char *)buffer, sizeof(buffer), stdin);
			/* Fast string to bool, reliably defined for strings starting
			with 0, 1, t, T, f, F, y, Y, n, N, anything else is undefined. */
			*updateFlash = (buffer[0] == '1' || (buffer[0] & 0xD2) == 0x50);
			printf("\n");
			if (*updateFlash)
			{
				printf("Upload flash firmware (y/n, or press ENTER to skip):\n");
				buffer[0] = '\0';
				fgets((char *)buffer, sizeof(buffer), stdin);
				*updateFlashFirmware = (buffer[0] == '1' || (buffer[0] & 0xD2) == 0x50);
				printf("\n");
			}
		}
		/* When uploading, or under emulator when the default flash is specified,
		offer to confirm which flash file will be used. */
		if (*updateFlash
		)
		{
			/* Query user for any changes to the flash file name */
#ifdef _WIN32
			printf("Select flash file %s(or press ENTER to use %s%ls%s):\n",
			    *updateFlashFirmware ? "with firmware " : "",
			    flashFile[0] ? "\"" : "", /* Quote */
			    flashFile[0] ? flashFile : L"no flash",
			    flashFile[0] ? "\"" : ""); /* Quote */
#else
			printf("Select flash file %s(or press ENTER to use %s%s%s):\n",
			    *updateFlashFirmware ? "with firmware " : "",
			    flashFile[0] ? "\"" : "", /* Quote */
			    flashFile[0] ? flashFile : "no flash",
			    flashFile[0] ? "\"" : ""); /* Quote */
#endif

#ifdef _WIN32
			fgetws(flashPath, MAX_PATH, stdin);
#else
			fgets(flashPath, MAX_PATH, stdin);
#endif
			if (flashPath[0] == '\r' || flashPath[0] == '\n')
				flashPath[0] = '\0';
#ifdef _WIN32
			flashPathSz = wcslen(flashPath);
#else
			flashPathSz = strlen(flashPath);
#endif
			while (flashPathSz && (flashPath[flashPathSz - 1] == '\r' || flashPath[flashPathSz - 1] == '\n'))
			{
				/* Trim flash path */
				flashPath[flashPathSz - 1] = '\0';
				--flashPathSz;
			}

			if (flashFile[0] == '\0' && flashPath[0] == '\0')
			{
				/* No flash */
				printf("\n");
				return;
			}

			/* Check if this file can be opened */
#ifdef _WIN32
			ferr = _wfopen_s(&f, flashPath[0] ? flashPath : flashFile, L"rb");
#else
			f = fopen(flashPath[0] ? flashPath : flashFile, "rb");
#endif
			if (
#ifdef _WIN32
			    ferr ||
#endif
			    !f)
			{
				printf("File \"%ls\" cannot be opened\n", flashPath[0] ? flashPath : flashFile);
				goto SELECTFLASH;
			}
			fseek(f, 0, SEEK_END);
			fclose(f);
			f = NULL;
			printf("\n");
		}
		if (*updateFlash
		)
		{
			if (!flashPath[0])
			{
#ifdef _WIN32
				wcscpy_s(flashPath, flashPathSize, flashFile);
#else
				strncpy(flashPath, flashFile, flashPathSize - 1);
				flashPath[flashPathSize - 1] = '\0';
#endif
			}
		}
	}
}
#endif


#if defined(_WIN32) || defined(__linux__)
#pragma warning(push)
#pragma warning(disable : 6262) // Large stack due to buffer
EVE_HAL_EXPORT void EVE_Util_uploadFlashFileInteractive(EVE_HalContext *phost, const eve_tchar_t *flashPath, bool updateFlashFirmware)
{
	ptrdiff_t flashSize;
	FILE *f = NULL;
	uint8_t buffer[64 * 4096];
	uint8_t rbuffer[64 * 4096];
#ifdef _WIN32
	errno_t err = 0;
#endif

	/* Upload flash */

	EVE_BootupParameters bootupParams;
	printf("Preparing to upload flash...\n");

	/* Open flash file and get size */
#ifdef _WIN32
	err = _wfopen_s(&f, flashPath, L"rb");
#else
	f = fopen(flashPath, "rb");
#endif

	if (
#ifdef _WIN32
	    err ||
#endif
	    !f)
	{
		printf("Flash file cannot be opened\n");
	}
	else
	{

		fseek(f, 0, SEEK_END);
		flashSize = ftell(f);
		fseek(f, 0, SEEK_SET);

		/* Get the default bootup parameters for the device */
		EVE_Util_bootupDefaults(phost, &bootupParams);

		if (EVE_Util_bootup(phost, &bootupParams))
		{
			/* Get the default bootup parameters for the device */
			EVE_ConfigParameters configParams;
			EVE_Util_configDefaults(phost, &configParams, EVE_DISPLAY_DEFAULT);

			/* No display */
#if EVE_SUPPORT_CHIPID_TO(EVE_BT820)
			configParams.PCLK = 0;
#endif

			/* Boot up */
			if (EVE_Util_config(phost, &configParams))
			{
				do
				{
					uint32_t flashStatus;
					uint32_t flashDeviceSize;
					size_t remainingBytes;
					uint32_t flashAddr;

					if (!EVE_Hal_supportFlash(phost))
					{
						printf("This device doesn't support flash\n");
						break;
					}

					flashStatus = EVE_Hal_rd32(phost, REG_FLASH_STATUS);
					if (flashStatus == FLASH_STATUS_DETACHED)
					{
						EVE_Cmd_wr32(phost, CMD_FLASHATTACH);
						if (!EVE_Cmd_waitFlush(phost)) /* Wait for command completion */
						{
							printf("Coprocessor fault\n");
							break;
						}
					}

					flashStatus = EVE_Hal_rd32(phost, REG_FLASH_STATUS);
					if (flashStatus < FLASH_STATUS_BASIC)
					{
						printf("Flash could not be attached\n");
						break;
					}

					if (updateFlashFirmware)
					{
						printf("Upload flash firmware from image...\n");
						if (fread(buffer, 4096, 1, f) != 1)
						{
							printf("Could not read file\n");
							break;
						}
						EVE_Hal_wrMem(phost, 0, buffer, 4096);
						EVE_Cmd_startFunc(phost);
						EVE_Cmd_wr32(phost, CMD_FLASHUPDATE);
						EVE_Cmd_wr32(phost, 0);
						EVE_Cmd_wr32(phost, 0);
						EVE_Cmd_wr32(phost, 4096);
						EVE_Cmd_endFunc(phost);
						if (!EVE_Cmd_waitFlush(phost)) /* Wait for command completion */
						{
							printf("Coprocessor fault\n");
							break;
						}
					}
					else
					{
						if (fseek(f, 4096, SEEK_CUR))
						{
							printf("Could not seek file\n");
						}
					}

					if (flashStatus == FLASH_STATUS_BASIC)
					{
						uint32_t resAddr;
						printf("Enter fast flash mode\n");
						EVE_Cmd_startFunc(phost);
						if (EVE_CHIPID >= EVE_BT820)
							EVE_Cmd_wr32(phost, CMD_STOP); // WORKAROUND: CMD_FLASHFAST uses same area as spinner, force disable it
						EVE_Cmd_wr32(phost, CMD_FLASHFAST);
						resAddr = EVE_Cmd_moveWp(phost, 4); /* Get the address where the coprocessor will write the result */
						EVE_Cmd_endFunc(phost);
						if (!EVE_Cmd_waitFlush(phost)) /* Wait for command completion */
						{
							printf("Coprocessor fault\n");
							break;
						}
						EVE_Hal_rd32(phost, RAM_CMD + resAddr); /* Fetch result */
					}

					flashStatus = EVE_Hal_rd32(phost, REG_FLASH_STATUS);
					if (flashStatus < FLASH_STATUS_FULL)
					{
						printf("Flash could not enter fast mode. Has the correct firmware been uploaded?\n");
						break;
					}

					flashDeviceSize = EVE_Hal_rd32(phost, REG_FLASH_SIZE) * 1024 * 1024;
					if (flashDeviceSize < flashSize)
					{
						printf("Not enough space on flash, need %i bytes, have %i bytes\n", (int)flashSize, (int)flashDeviceSize);
						break;
					}

					remainingBytes = flashSize - 4096;
					flashAddr = 4096;

					printf("Upload flash from image...\n");
					eve_assert(sizeof(buffer) >= 4096);

					while (remainingBytes)
					{
						/* Read from file */
						size_t el;
						size_t sz;
						if (remainingBytes < 4096)
						{
							el = fread(buffer, 1, remainingBytes, f);
							sz = 4096;
							remainingBytes = 0;
						}
						else
						{
							el = fread(buffer, 4096, min(remainingBytes, sizeof(buffer)) / 4096, f);
							sz = el * 4096;
							remainingBytes -= sz;
						}
						if (!el)
						{
							printf("\nFailed to read file\n");
							break;
						}
						printf("B");

						/* Write to flash */
					REWRITE:
						EVE_Hal_wrMem(phost, 0, buffer, (uint32_t)sz);
						EVE_Cmd_startFunc(phost);
						EVE_Cmd_wr32(phost, CMD_FLASHUPDATE);
						EVE_Cmd_wr32(phost, flashAddr);
						EVE_Cmd_wr32(phost, 0);
						EVE_Cmd_wr32(phost, (uint32_t)sz);
						EVE_Cmd_endFunc(phost);
						if (!EVE_Cmd_waitFlush(phost)) /* Wait for command completion */
						{
							printf("\nCoprocessor fault\n");
							break;
						}
						printf("R");

						/* Verify using CMD_FLASHREAD */
						EVE_Hal_startTransfer(phost, EVE_TRANSFER_WRITE, 0);
						for (size_t i = 0; i < sz; ++i)
							EVE_Hal_transfer8(phost, 0x0F);
						EVE_Hal_endTransfer(phost);
						EVE_Cmd_startFunc(phost);
						EVE_Cmd_wr32(phost, CMD_FLASHREAD);
						EVE_Cmd_wr32(phost, 0);
						EVE_Cmd_wr32(phost, flashAddr);
						EVE_Cmd_wr32(phost, (uint32_t)sz);
						EVE_Cmd_endFunc(phost);
						if (!EVE_Cmd_waitFlush(phost)) /* Wait for command completion */
						{
							printf("\nCoprocessor fault\n");
							break;
						}
						EVE_Hal_rdMem(phost, rbuffer, 0, (uint32_t)sz);
						for (size_t i = 0; i < sz; ++i)
						{
							if (buffer[i] != rbuffer[i])
							{
								printf("\nVerification failed\n");
								goto REWRITE;
							}
						}
						printf("T");

						flashAddr += (uint32_t)sz;
					}

					if (!remainingBytes)
					{
						printf("\nFlash upload is ready\n");
					}
					printf("\n");
				} while (false); /* breakable scope */
			}
			else
			{
				printf("Failed to bootup the device\n");
			}

			/* Shutdown */
			EVE_Util_shutdown(phost);
		}
		else
		{
			printf("Failed to bootup the device\n");
		}
	}
	printf("\n");

	if (f)
	{
		fclose(f);
	}
}
#pragma warning(pop)
#endif

bool EVE_Util_openDeviceInteractive(EVE_HalContext *phost, const eve_tchar_t *flashFile)
{
	EVE_CHIPID_T chipId;
	size_t deviceIdx;
	bool opened;

	EVE_HalParameters params = { 0 };
#if defined(_WIN32) || defined(__linux__)
	bool updateFlash = false;
	bool updateFlashFirmware = false;
	eve_tchar_t flashPath[MAX_PATH];
	flashPath[0] = '\0';
#endif

	/* Interactive device selection */
	EVE_Util_selectDeviceInteractive(&chipId, &deviceIdx);

	/* Fetch the default parameters for a device. Set the expected chip id.
	Pass the device index, or -1 to select the first device */
	EVE_Hal_defaultsEx(&params, deviceIdx);

#if defined(_WIN32) || defined(__linux__)
	if (chipId >= EVE_BT815 || (chipId <= 0 && flashFile && flashFile[0]))
		EVE_Util_selectFlashFileInteractive(flashPath, sizeof(flashPath) / sizeof(flashPath[0]), &updateFlash, &updateFlashFirmware, &params, flashFile);
#endif


	opened = EVE_Hal_open(phost, &params);

	if (!opened)
		return false;

#if defined(_WIN32) || defined(__linux__)
	if (updateFlash && flashPath[0])
		EVE_Util_uploadFlashFileInteractive(phost, flashPath, updateFlashFirmware);
#endif

	return true;
}

/* Calls EVE_Util_bootup and EVE_Util_config using the default parameters.
Falls back to no interactivity on FT9XX platform */
EVE_HAL_EXPORT bool EVE_Util_bootupConfigInteractive(EVE_HalContext *phost, EVE_DISPLAY_T display)
{
	EVE_DISPLAY_T selectedDisplay;
	EVE_BootupParameters bootup;
	EVE_ConfigParameters config;

	EVE_Util_bootupDefaults(phost, &bootup);
	if (!EVE_Util_bootup(phost, &bootup))
	{
		return false;
	}

	EVE_Util_selectDisplayInteractive(&selectedDisplay);
	if (!selectedDisplay)
		selectedDisplay = display;

	EVE_Util_configDefaults(phost, &config, selectedDisplay);
	if (!EVE_Util_config(phost, &config))
	{
		EVE_Util_shutdown(phost);
		return false;
	}

	// FIXME: This should be in EVE_Util_bootup or EVE_Util_config, not in interactive bootup

	return true;
}

/* end of file */

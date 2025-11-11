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

/*

Defines EVE hardware values.

This header is separated and included last
in case of conflicts with other libraries.

Expects BT_82X_ENABLE, BT_81XA_ENABLE, BT_81X_ENABLE, BT_88X_ENABLE, FT_81X_ENABLE, or FT_80X_ENABLE
to be defined. If not, multi target compilation is assumed.

*/

#ifndef EVE_GPU_DEFS__H
#define EVE_GPU_DEFS__H

#ifndef ESD_ENUM
#define ESD_ENUM(name, ...)
#define ESD_END()
#endif


/* Definitions used for FT800 coprocessor command buffer */
#define EVE_DL_COUNT (EVE_CHIPID >= EVE_BT820 ? 4096UL : 2048UL)
#define EVE_DL_SIZE (4 * EVE_DL_COUNT) /* 8kB/16kB Display List buffer size */
#define EVE_CMD_FIFO_COUNT (EVE_CHIPID >= EVE_BT820 ? 4096UL : 1024UL)
#define EVE_CMD_FIFO_SIZE (4 * EVE_CMD_FIFO_COUNT) /* 4kB/16kB coprocessor FIFO size */
#define EVE_CMD_FIFO_MASK (EVE_CMD_FIFO_SIZE - 1)
#define EVE_CMD_FIFO_ALIGNMENT_MASK (EVE_CMD_FIFO_SIZE - ((4) - 1))

#define EVE_DL_COUNT_MAX (2048UL)
#define EVE_CMD_FIFO_COUNT_MAX (1024UL)
#define EVE_DL_SIZE_MAX (4 * EVE_DL_COUNT_MAX) /* 8kB/16kB Display List buffer size */
#define EVE_CMD_FIFO_SIZE_MAX (4 * EVE_CMD_FIFO_COUNT_MAX) /* 4kB/16kB coprocessor FIFO size */
#define EVE_CMD_FAULT(rp) (rp & 0x3)

#define EVE_FLASH_WRITE_ALIGN (256)
#define EVE_FLASH_UPDATE_ALIGN (4096)
#define EVE_FLASH_READ_ALIGN (64)
#define EVE_FLASH_FIRMWARE_SIZE (4096)

typedef uint8_t eve_tag_t; /* 8-bit display list TAG */
#define EVE_TAG_MASK (0xFFUL) /* 8-bit TAG mask */

/**************
** Addresses **
**************/

#define RAM_G 0UL
#define ROM_CHIPID 786432UL
#define RAM_ERR_REPORT (EVE_CHIPID >= EVE_BT820 ? 2130724864UL : 0x309800UL)
#define RAM_G_RESERVED (EVE_CHIPID >= EVE_BT820 ? 0x280000UL : 0UL)



#define RAM_G_SIZE_MAX (1024 * 1024L)
#define RAM_G_SIZE RAM_G_SIZE_MAX
#define RAM_G_AVAILABLE RAM_G_SIZE_MAX



#define EVE_HAL_REG_ID 3153920UL
#define EVE_HAL_REG_CPURESET 3153952UL
#define EVE_HAL_REG_J1_INT 3154084UL
#define EVE_HAL_REG_CMD_READ 3154168UL
#define EVE_HAL_REG_TOUCH_TRANSFORM_A 3154256UL
#define EVE_HAL_REG_CRC 3154296UL
#define EVE_HAL_REG_TRIM 3154304UL
#define EVE_HAL_REG_CTOUCH_TOUCH2_XY 3154316UL
#define EVE_HAL_REG_DATESTAMP 3155300UL
#define EVE_HAL_REG_CMDB_SPACE 3155316UL
#define EVE_HAL_REG_TRACKER 3182592UL

#define RAM_DL 3145728UL
#define ROMFONT_TABLEADDRESS 3145724UL

#define LOW_FREQ_BOUND 58800000L // 98% of 60Mhz

#define SCISSOR_XY_SHIFT 11
#define SCISSOR_XY_MASK 2047UL
#define SCISSOR_SIZE_SHIFT 12
#define SCISSOR_SIZE_MASK 4095UL



#define PALETTE_ADDR_MASK 4194303UL
#define TAG_DL_MASK (255UL)
#define BITMAP_HANDLE_MASK (31UL)
#define BITMAP_LAYOUT_H_STRIDE_MASK (3UL)


#define BITMAP_ADDR_MASK (16777215UL)



#define EVE_HAL_REG_HCYCLE (EVE_HAL_REG_CPURESET + 12UL)
#define EVE_HAL_REG_PCLK_POL (EVE_HAL_REG_CPURESET + 76UL)
#define EVE_HAL_REG_TAG_X (EVE_HAL_REG_CPURESET + 84UL)
#define EVE_HAL_REG_VOL_SOUND (EVE_HAL_REG_CPURESET + 100UL)
#define EVE_HAL_REG_J1_COLD (EVE_HAL_REG_CPURESET + 128UL)
#define EVE_HAL_REG_INT_FLAGS (EVE_HAL_REG_J1_INT + 4UL)
#define EVE_HAL_REG_CTOUCH_TOUCH0_XY (EVE_HAL_REG_CMD_READ + 44UL)
#define EVE_HAL_REG_CTOUCH_TOUCH1_XY (EVE_HAL_REG_CMD_READ + 36UL)
#define EVE_HAL_REG_CTOUCH_TOUCH3_XY (EVE_HAL_REG_CTOUCH_TOUCH2_XY + 4UL)
#define EVE_HAL_REG_TOUCH_TAG_XY (EVE_HAL_REG_CMD_READ + 48UL)
#define EVE_HAL_REG_EJPG_READY (EVE_HAL_REG_CTOUCH_TOUCH2_XY + 8UL)
#define EVE_HAL_REG_EJPG_DEBUG (EVE_HAL_REG_CTOUCH_TOUCH2_XY + 976UL)
#define EVE_HAL_REG_CMDB_WRITE (EVE_HAL_REG_CMDB_SPACE + 4UL)
#define EVE_HAL_REG_ESPIM_DUMMY (EVE_HAL_REG_CMDB_SPACE + 112UL)
#define EVE_HAL_REG_FLASH_DTR (EVE_HAL_REG_CMDB_SPACE + 168UL)
#define EVE_HAL_REG_PLAY_CONTROL (EVE_HAL_REG_TRACKER + 40UL)



/* When nothing is touched, the touch tag will report zero. */
#define EVE_TAG_RELEASED (0)

/* This tag is conventionally used for rendering anything that doesn't have a touch tag,
 * to distinguish nothing being touched from background touch.
 * @note Kept at 255 for compatbility with BT81X, even though BT82X range is 24-bit.
 */
#define EVE_TAG_NONE (255)															   
#define RAM_TOP (RAM_DL + 16384UL)
#define RAM_CMD (EVE_CHIPID >= EVE_BT820 ? 2130706432UL : (RAM_DL + 32768UL))
#define RAM_J1RAM (EVE_CHIPID >= EVE_BT820 ? 2130722816UL : (RAM_DL + 36864UL))
#define RAM_ROMSUB (EVE_CHIPID >= EVE_BT820 ? 2130868224UL : (EVE_CHIPID == EVE_FT800 ? 1884160UL : (RAM_DL + 40960UL)))
#define RAM_JTBOOT (EVE_CHIPID >= EVE_BT820 ? 2130726912UL : (RAM_DL + 45056UL))
#define RAM_BIST (RAM_DL + 524288UL)
#define RAM_COMPOSITE (RAM_DL + 794624UL)

#define RAM_REG (EVE_HAL_REG_ID + 0UL)
#define REG_ID (EVE_HAL_REG_ID + 0UL)
#define REG_FRAMES (REG_ID + 4UL)
#define REG_CLOCK (REG_ID + 8UL)
#define REG_FREQUENCY (REG_ID + 12UL)
#define REG_RENDERMODE (REG_ID + 16UL)
#define REG_SNAPY (REG_ID + 20UL)
#define REG_SNAPSHOT (REG_ID + 24UL)
#define REG_SNAPFORMAT (REG_ID + 28UL)

#define REG_CPURESET (EVE_HAL_REG_CPURESET + 0UL)
#define REG_TAP_CRC (REG_CPURESET + 4UL)
#define REG_TAP_MASK (REG_CPURESET + 8UL)
#define REG_HCYCLE (EVE_HAL_REG_HCYCLE + 0UL)
#define REG_HOFFSET (REG_HCYCLE + 4UL)
#define REG_HSIZE (REG_HCYCLE + 8UL)
#define REG_HSYNC0 (REG_HCYCLE + 12UL)
#define REG_HSYNC1 (REG_HCYCLE + 16UL)
#define REG_VCYCLE (REG_HCYCLE + 20UL)
#define REG_VOFFSET (REG_HCYCLE + 24UL)
#define REG_VSIZE (REG_HCYCLE + 28UL)
#define REG_VSYNC0 (REG_HCYCLE + 32UL)
#define REG_VSYNC1 (REG_HCYCLE + 36UL)
#define REG_DLSWAP (REG_HCYCLE + 40UL)
#define REG_ROTATE (REG_HCYCLE + 44UL)
#define REG_OUTBITS (REG_HCYCLE + 48UL)
#define REG_DITHER (REG_HCYCLE + 52UL)
#define REG_SWIZZLE (REG_HCYCLE + 56UL)
#define REG_CSPREAD (REG_HCYCLE + 60UL)

#define REG_PCLK_POL (EVE_HAL_REG_PCLK_POL + 0UL)
#define REG_PCLK (REG_PCLK_POL + 4UL)

#define REG_TAG_X (EVE_HAL_REG_TAG_X + 0UL)
#define REG_TAG_Y (REG_TAG_X + 4UL)
#define REG_TAG (REG_TAG_X + 8UL)
#define REG_VOL_PB (REG_TAG_X + 12UL)

#define REG_VOL_SOUND (EVE_HAL_REG_VOL_SOUND + 0UL)
#define REG_SOUND (REG_VOL_SOUND + 4UL)
#define REG_PLAY (REG_VOL_SOUND + 8UL)
#define REG_GPIO_DIR (REG_VOL_SOUND + 12UL)
#define REG_GPIO (REG_VOL_SOUND + 16UL)
#define REG_GPIOX_DIR (REG_VOL_SOUND + 20UL)
#define REG_GPIOX (REG_VOL_SOUND + 24UL)

#define REG_J1_COLD (EVE_HAL_REG_J1_COLD + 0UL)

#define REG_J1_INT (EVE_HAL_REG_J1_INT + 0UL)

#define REG_INT_FLAGS (EVE_HAL_REG_INT_FLAGS + 0UL)
#define REG_INT_EN (REG_INT_FLAGS + 4UL)
#define REG_INT_MASK (REG_INT_FLAGS + 8UL)
#define REG_PLAYBACK_START (REG_INT_FLAGS + 12UL)
#define REG_PLAYBACK_LENGTH (REG_INT_FLAGS + 16UL)
#define REG_PLAYBACK_READPTR (REG_INT_FLAGS + 20UL)
#define REG_PLAYBACK_FREQ (REG_INT_FLAGS + 24UL)
#define REG_PLAYBACK_FORMAT (REG_INT_FLAGS + 28UL)
#define REG_PLAYBACK_LOOP (REG_INT_FLAGS + 32UL)
#define REG_PLAYBACK_PLAY (REG_INT_FLAGS + 36UL)
#define REG_PWM_HZ (REG_INT_FLAGS + 40UL)
#define REG_PWM_DUTY (REG_INT_FLAGS + 44UL)
#define REG_MACRO_0 (REG_INT_FLAGS + 48UL)
#define REG_MACRO_1 (REG_INT_FLAGS + 52UL)
#define REG_CYA0 (REG_INT_FLAGS + 56UL)
#define REG_CYA1 (REG_INT_FLAGS + 60UL)
#define REG_BUSYBITS (REG_INT_FLAGS + 64UL)
#define REG_ROMSUB_SEL (REG_INT_FLAGS + 72UL)
#define REG_RAM_FOLD (REG_INT_FLAGS + 76UL)

#define REG_CMD_READ (EVE_HAL_REG_CMD_READ + 0UL)
#define REG_CMD_WRITE (REG_CMD_READ + 4UL)
#define REG_CMD_DL (REG_CMD_READ + 8UL)
#define REG_TOUCH_MODE (REG_CMD_READ + 12UL)
#define REG_CTOUCH_EXTENDED (REG_CMD_READ + 16UL)
#define REG_TOUCH_ADC_MODE (REG_CMD_READ + 16UL)
#define REG_EHOST_TOUCH_X (REG_CMD_READ + 20UL)
#define REG_TOUCH_CHARGE (REG_CMD_READ + 20UL)
#define REG_TOUCH_SETTLE (REG_CMD_READ + 24UL)
#define REG_EHOST_TOUCH_ID (REG_CMD_READ + 28UL)
#define REG_TOUCH_OVERSAMPLE (REG_CMD_READ + 28UL)
#define REG_EHOST_TOUCH_Y (REG_CMD_READ + 32UL)
#define REG_TOUCH_RZTHRESH (REG_CMD_READ + 32UL)

#define REG_CTOUCH_TOUCH0_XY (EVE_HAL_REG_CTOUCH_TOUCH0_XY + 0UL)
#define REG_TOUCH_SCREEN_XY (REG_CTOUCH_TOUCH0_XY + 0UL)
#define REG_CTOUCH_TOUCH1_XY (EVE_HAL_REG_CTOUCH_TOUCH1_XY + 0UL)
#define REG_TOUCH_RAW_XY (REG_CTOUCH_TOUCH1_XY + 0UL)
#define REG_CTOUCH_TOUCHA_XY (REG_CTOUCH_TOUCH1_XY + 0UL)
#define REG_CTOUCH_TOUCH2_XY (EVE_HAL_REG_CTOUCH_TOUCH2_XY + 0UL)
#define REG_TOUCH_DIRECT_XY (REG_CTOUCH_TOUCH2_XY + 0UL)
#define REG_CTOUCH_TOUCHB_XY (REG_CTOUCH_TOUCH2_XY + 0UL)

#define REG_CTOUCH_TOUCH3_XY (EVE_HAL_REG_CTOUCH_TOUCH3_XY + 0UL)
#define REG_TOUCH_DIRECT_Z1Z2 (REG_CTOUCH_TOUCH3_XY + 0UL)
#define REG_CTOUCH_TOUCHC_XY (REG_CTOUCH_TOUCH3_XY + 0UL)

#define REG_TOUCH_TAG_XY (EVE_HAL_REG_TOUCH_TAG_XY + 0UL)
#define REG_TOUCH_TAG (REG_TOUCH_TAG_XY + 4UL)
#define REG_TOUCH_TAG1_XY (REG_TOUCH_TAG_XY + 8UL)
#define REG_TOUCH_TAG1 (REG_TOUCH_TAG_XY + 12UL)
#define REG_TOUCH_TAG2_XY (REG_TOUCH_TAG_XY + 16UL)
#define REG_TOUCH_TAG2 (REG_TOUCH_TAG_XY + 20UL)
#define REG_TOUCH_TAG3_XY (REG_TOUCH_TAG_XY + 24UL)
#define REG_TOUCH_TAG3 (REG_TOUCH_TAG_XY + 28UL)
#define REG_TOUCH_TAG4_XY (REG_TOUCH_TAG_XY + 32UL)
#define REG_TOUCH_TAG4 (REG_TOUCH_TAG_XY + 36UL)

#define REG_CTOUCH_TOUCH4_Y (REG_TOUCH_TAG_XY - 8UL)
#define REG_CTOUCH_IDS (REG_TOUCH_TAG_XY - 8UL)
#define REG_TOUCH_RZ (REG_TOUCH_TAG_XY - 8UL)

#define REG_TOUCH_TAG_XY (EVE_HAL_REG_TOUCH_TAG_XY + 0UL)
#define REG_TOUCH_TAG (REG_TOUCH_TAG_XY + 4UL)
#define REG_TOUCH_TAG1_XY (REG_TOUCH_TAG_XY + 8UL)
#define REG_TOUCH_TAG1 (REG_TOUCH_TAG_XY + 12UL)
#define REG_TOUCH_TAG2_XY (REG_TOUCH_TAG_XY + 16UL)
#define REG_TOUCH_TAG2 (REG_TOUCH_TAG_XY + 20UL)
#define REG_TOUCH_TAG3_XY (REG_TOUCH_TAG_XY + 24UL)
#define REG_TOUCH_TAG3 (REG_TOUCH_TAG_XY + 28UL)
#define REG_TOUCH_TAG4_XY (REG_TOUCH_TAG_XY + 32UL)
#define REG_TOUCH_TAG4 (REG_TOUCH_TAG_XY + 36UL)

#define REG_TOUCH_TRANSFORM_A (EVE_HAL_REG_TOUCH_TRANSFORM_A + 0UL)
#define REG_TOUCH_TRANSFORM_B (REG_TOUCH_TRANSFORM_A + 4UL)
#define REG_TOUCH_TRANSFORM_C (REG_TOUCH_TRANSFORM_A + 8UL)
#define REG_TOUCH_TRANSFORM_D (REG_TOUCH_TRANSFORM_A + 12UL)
#define REG_TOUCH_TRANSFORM_E (REG_TOUCH_TRANSFORM_A + 16UL)
#define REG_TOUCH_TRANSFORM_F (REG_TOUCH_TRANSFORM_A + 20UL)
#define REG_TOUCH_CONFIG (REG_TOUCH_TRANSFORM_A + 24UL)
#define REG_ANALOG (REG_TOUCH_TRANSFORM_A + 28UL)
#define REG_CTOUCH_GESTURE (REG_TOUCH_TRANSFORM_A + 28UL)
#define REG_CTOUCH_TOUCH4_X (REG_TOUCH_TRANSFORM_A + 28UL)
#define REG_PATCHED_TOUCH_FAULT (REG_TOUCH_TRANSFORM_A + 28UL)
#define REG_EHOST_TOUCH_ACK (REG_TOUCH_TRANSFORM_A + 32UL)
#define REG_PATCHED_ANALOG (REG_TOUCH_TRANSFORM_A + 32UL)
#define REG_TOUCH_FAULT (REG_TOUCH_TRANSFORM_A + 32UL)
#define REG_BIST_EN (EVE_CHIPID == EVE_FT800 ? 1058132UL : (REG_TOUCH_TRANSFORM_A + 36UL))

#define REG_CRC (EVE_HAL_REG_CRC + 0UL)
#define REG_SPI_EARLY_TX (REG_CRC + 4UL)

#define REG_TRIM (EVE_HAL_REG_TRIM + 0UL)
#define REG_ANA_COMP (REG_TRIM + 4UL)
#define REG_SPI_WIDTH (REG_TRIM + 8UL)
#define REG_EJPG_READY (EVE_HAL_REG_EJPG_READY + 0UL)
														
#define REG_EJPG_BUSY (REG_EJPG_READY + 4UL)
#define REG_EJPG_DAT (REG_EJPG_READY + 8UL)
												   
#define REG_EJPG_OPTIONS (REG_EJPG_READY + 12UL)
#define REG_EJPG_DST (REG_EJPG_READY + 16UL)
#define REG_EJPG_W (REG_EJPG_READY + 20UL)
#define REG_EJPG_H (REG_EJPG_READY + 24UL)
#define REG_EJPG_FORMAT (REG_EJPG_READY + 28UL)
#define REG_EJPG_RI (REG_EJPG_READY + 32UL)
#define REG_EJPG_TQ (REG_EJPG_READY + 36UL)
#define REG_EJPG_TDA (REG_EJPG_READY + 40UL)
#define REG_EJPG_Q (REG_EJPG_READY + 44UL)
#define REG_EJPG_HT (REG_EJPG_READY + 172UL)
#define REG_EJPG_DCC (REG_EJPG_READY + 428UL)
#define REG_EJPG_ACC (REG_EJPG_READY + 452UL)
#define REG_EJPG_SCALE (REG_EJPG_READY + 964UL)

#define REG_EJPG_DEBUG (EVE_HAL_REG_EJPG_DEBUG + 0UL)
#define REG_RASTERY (REG_EJPG_DEBUG + 4UL)

#define REG_DATESTAMP (EVE_HAL_REG_DATESTAMP + 0UL)

#define REG_CMDB_WRITE (EVE_HAL_REG_CMDB_WRITE + 0UL)

#define REG_CMDB_SPACE (EVE_HAL_REG_CMDB_SPACE + 0UL)
#define REG_ADAPTIVE_FRAMERATE (REG_CMDB_SPACE + 8UL)
#define REG_SPIM_DIR (REG_CMDB_SPACE + 12UL)
#define REG_SPIM (REG_CMDB_SPACE + 16UL)
#define REG_ESPIM_READSTART (REG_CMDB_SPACE + 20UL)
#define REG_ESPIM_SEQ (REG_CMDB_SPACE + 24UL)
#define REG_ESPIM_ADD (REG_CMDB_SPACE + 40UL)
#define REG_ESPIM_COUNT (REG_CMDB_SPACE + 44UL)
#define REG_ESPIM_WINDOW (REG_CMDB_SPACE + 48UL)

#define REG_ESPIM_DUMMY (EVE_HAL_REG_ESPIM_DUMMY + 0UL)
#define REG_ESPIM_TRIG (REG_ESPIM_DUMMY + 4UL)
#define REG_PLAYBACK_PAUSE (REG_ESPIM_DUMMY + 8UL)
#define REG_FLASH_STATUS (REG_ESPIM_DUMMY + 12UL)
#define REG_FULLBUSYBITS (REG_ESPIM_DUMMY + 16UL)
#define REG_SHA1KEY (REG_ESPIM_DUMMY + 32UL)

#define REG_UNDERRUN (REG_ESPIM_DUMMY + 40UL)
#define REG_AH_HCYCLE_MAX (REG_ESPIM_DUMMY + 44UL)
#define REG_PCLK_FREQ (REG_ESPIM_DUMMY + 48UL)
#define REG_PCLK_2X (REG_ESPIM_DUMMY + 52UL)

#define REG_FLASH_DTR (EVE_HAL_REG_FLASH_DTR + 0UL)
												  
#define REG_ESPIM_DTR (REG_FLASH_DTR + 4UL)
											  
#define REG_HSF_HSIZE (REG_FLASH_DTR + 8UL)
#define REG_HSF_FT1 (REG_FLASH_DTR + 12UL)
#define REG_HSF_FSCALE (REG_FLASH_DTR + 16UL)
#define REG_HSF_F00 (REG_FLASH_DTR + 20UL)
#define REG_HSF_F02 (REG_FLASH_DTR + 24UL)
#define REG_HSF_F03 (REG_FLASH_DTR + 28UL)
#define REG_HSF_F10 (REG_FLASH_DTR + 32UL)
#define REG_HSF_F11 (REG_FLASH_DTR + 36UL)
#define REG_HSF_F12 (REG_FLASH_DTR + 40UL)
#define REG_HSF_F13 (REG_FLASH_DTR + 44UL)

#define REG_TRACKER (EVE_HAL_REG_TRACKER + 0UL)
#define REG_TRACKER_1 (REG_TRACKER + 4UL)
#define REG_TRACKER_2 (REG_TRACKER + 8UL)
#define REG_TRACKER_3 (REG_TRACKER + 12UL)
#define REG_TRACKER_4 (REG_TRACKER + 16UL)
#define REG_MEDIAFIFO_READ (REG_TRACKER + 20UL)
#define REG_MEDIAFIFO_WRITE (REG_TRACKER + 24UL)
#define REG_MEDIAFIFO_BASE (REG_TRACKER + 28UL)
#define REG_MEDIAFIFO_SIZE (REG_TRACKER + 32UL)
#define REG_FLASH_SIZE (REG_TRACKER + 36UL)
#define REG_ANIM_ACTIVE (REG_TRACKER + 44UL)
#define REG_DF_TUNED (REG_TRACKER + 48UL)

#define REG_PLAY_CONTROL (EVE_HAL_REG_PLAY_CONTROL + 0UL)

#define REG_CTOUCH_TOUCHD_X REG_CTOUCH_TOUCH4_X
#define REG_CTOUCH_TOUCHD_Y REG_CTOUCH_TOUCH4_Y


/* Default clock frequencies as configured by HAL */
#define EVE_FREQUENCY_DEFAULT (48000000UL)


#define EVE_GPUDEFS_IMPLEMENT EVE_HAL_REG_ID,                \
	                          EVE_HAL_REG_CPURESET,          \
	                          EVE_HAL_REG_HCYCLE,            \
	                          EVE_HAL_REG_PCLK_POL,          \
	                          EVE_HAL_REG_TAG_X,             \
	                          EVE_HAL_REG_VOL_SOUND,         \
	                          EVE_HAL_REG_J1_COLD,           \
	                          EVE_HAL_REG_J1_INT,            \
	                          EVE_HAL_REG_INT_FLAGS,         \
	                          EVE_HAL_REG_CMD_READ,          \
	                          EVE_HAL_REG_CTOUCH_TOUCH0_XY,  \
	                          EVE_HAL_REG_CTOUCH_TOUCH1_XY,  \
	                          EVE_HAL_REG_CTOUCH_TOUCH2_XY,  \
	                          EVE_HAL_REG_CTOUCH_TOUCH3_XY,  \
	                          EVE_HAL_REG_TOUCH_TAG_XY,      \
	                          EVE_HAL_REG_TOUCH_TRANSFORM_A, \
	                          EVE_HAL_REG_CRC,               \
	                          EVE_HAL_REG_TRIM,              \
	                          EVE_HAL_REG_EJPG_READY,        \
	                          EVE_HAL_REG_EJPG_DEBUG,        \
	                          EVE_HAL_REG_DATESTAMP,         \
	                          EVE_HAL_REG_CMDB_WRITE,        \
	                          EVE_HAL_REG_CMDB_SPACE,        \
	                          EVE_HAL_REG_ESPIM_DUMMY,       \
	                          EVE_HAL_REG_FLASH_DTR,         \
	                          EVE_HAL_REG_TRACKER,           \
	                          EVE_HAL_REG_PLAY_CONTROL,      \
	                          RAM_DL,                        \
	                          ROMFONT_TABLEADDRESS,          \
	                          RAM_G_SIZE_MAX,                \
	                          LOW_FREQ_BOUND,                \
	                          BITMAP_ADDR_MASK,              \
	                          PALETTE_ADDR_MASK,             \
	                          SCISSOR_SIZE_SHIFT,            \
	                          TAG_DL_MASK,                   \
	                          BITMAP_HANDLE_MASK,            \
	                          BITMAP_LAYOUT_H_STRIDE_MASK


/*************
** Commands **
*************/

// clang-format off

// FT800
#define CMD_DLSTART 4294967040UL
#define CMD_SWAP 4294967041UL
#define CMD_INTERRUPT 4294967042UL
#define CMD_BGCOLOR (EVE_CHIPID >= EVE_BT820 ? 4294967047UL : 4294967049UL)
#define CMD_FGCOLOR (EVE_CHIPID >= EVE_BT820 ? 4294967048UL : 4294967050UL)
#define CMD_GRADIENT (EVE_CHIPID >= EVE_BT820 ? 4294967049UL : 4294967051UL)
#define CMD_TEXT (EVE_CHIPID >= EVE_BT820 ? 4294967050UL : 4294967052UL)
#define CMD_BUTTON (EVE_CHIPID >= EVE_BT820 ? 4294967051UL : 4294967053UL)
#define CMD_KEYS (EVE_CHIPID >= EVE_BT820 ? 4294967052UL : 4294967054UL)
#define CMD_PROGRESS (EVE_CHIPID >= EVE_BT820 ? 4294967053UL : 4294967055UL)
#define CMD_SLIDER (EVE_CHIPID >= EVE_BT820 ? 4294967054UL : 4294967056UL)
#define CMD_SCROLLBAR (EVE_CHIPID >= EVE_BT820 ? 4294967055UL : 4294967057UL)
#define CMD_TOGGLE (EVE_CHIPID >= EVE_BT820 ? 4294967056UL : 4294967058UL)
#define CMD_GAUGE (EVE_CHIPID >= EVE_BT820 ? 4294967057UL : 4294967059UL)
#define CMD_CLOCK (EVE_CHIPID >= EVE_BT820 ? 4294967058UL : 4294967060UL)
#define CMD_CALIBRATE (EVE_CHIPID >= EVE_BT820 ? 4294967059UL : 4294967061UL)
#define CMD_SPINNER (EVE_CHIPID >= EVE_BT820 ? 4294967060UL : 4294967062UL)
#define CMD_STOP (EVE_CHIPID >= EVE_BT820 ? 4294967061UL : 4294967063UL)
#define CMD_MEMCRC (EVE_CHIPID >= EVE_BT820 ? 4294967062UL : 4294967064UL)
#define CMD_REGREAD (EVE_CHIPID >= EVE_BT820 ? 4294967063UL : 4294967065UL)
#define CMD_MEMWRITE (EVE_CHIPID >= EVE_BT820 ? 4294967064UL : 4294967066UL)
#define CMD_MEMSET (EVE_CHIPID >= EVE_BT820 ? 4294967065UL : 4294967067UL)
#define CMD_MEMZERO (EVE_CHIPID >= EVE_BT820 ? 4294967066UL : 4294967068UL)
#define CMD_MEMCPY (EVE_CHIPID >= EVE_BT820 ? 4294967067UL : 4294967069UL)
#define CMD_APPEND (EVE_CHIPID >= EVE_BT820 ? 4294967068UL : 4294967070UL)
#define CMD_SNAPSHOT (EVE_CHIPID >= EVE_BT820 ? 4294967069UL : 4294967071UL)
#define CMD_BITMAP_TRANSFORM (EVE_CHIPID >= EVE_BT820 ? 4294967071UL : 4294967073UL)
#define CMD_INFLATE 4294967074UL
#define CMD_GETPTR (EVE_CHIPID >= EVE_BT820 ? 4294967072UL : 4294967075UL)
#define CMD_LOADIMAGE (EVE_CHIPID >= EVE_BT820 ? 4294967073UL : 4294967076UL)
#define CMD_GETPROPS (EVE_CHIPID >= EVE_BT820 ? 4294967074UL : 4294967077UL)
#define CMD_LOADIDENTITY (EVE_CHIPID >= EVE_BT820 ? 4294967075UL : 4294967078UL)
#define CMD_TRANSLATE (EVE_CHIPID >= EVE_BT820 ? 4294967076UL : 4294967079UL)
#define CMD_SCALE (EVE_CHIPID >= EVE_BT820 ? 4294967077UL : 4294967080UL)
#define CMD_ROTATE (EVE_CHIPID >= EVE_BT820 ? 4294967078UL : 4294967081UL)
#define CMD_SETMATRIX (EVE_CHIPID >= EVE_BT820 ? 4294967079UL : 4294967082UL)
#define CMD_SETFONT 4294967083UL
#define CMD_TRACK (EVE_CHIPID >= EVE_BT820 ? 4294967080UL : 4294967084UL)
#define CMD_DIAL (EVE_CHIPID >= EVE_BT820 ? 4294967081UL : 4294967085UL)
#define CMD_NUMBER (EVE_CHIPID >= EVE_BT820 ? 4294967082UL : 4294967086UL)
#define CMD_SCREENSAVER (EVE_CHIPID >= EVE_BT820 ? 4294967083UL : 4294967087UL)
#define CMD_SKETCH (EVE_CHIPID >= EVE_BT820 ? 4294967084UL : 4294967088UL)
#define CMD_LOGO (EVE_CHIPID >= EVE_BT820 ? 4294967085UL : 4294967089UL)
#define CMD_COLDSTART (EVE_CHIPID >= EVE_BT820 ? 4294967086UL : 4294967090UL)
#define CMD_GETMATRIX (EVE_CHIPID >= EVE_BT820 ? 4294967087UL : 4294967091UL)
#define CMD_GRADCOLOR (EVE_CHIPID >= EVE_BT820 ? 4294967088UL : 4294967092UL)

// FT801

// FT810
#define CMD_SETROTATE (EVE_CHIPID >= EVE_BT820 ? 4294967089UL : 4294967094UL)
#define CMD_SNAPSHOT2 4294967095UL
// #define CMD_SNAPSHOT2 (EVE_CHIPID >= EVE_BT820 ? 4294967090UL : 4294967095UL) // Removed in BT820
#define CMD_SETBASE (EVE_CHIPID >= EVE_BT820 ? 4294967091UL : 4294967096UL)
#define CMD_MEDIAFIFO (EVE_CHIPID >= EVE_BT820 ? 4294967092UL : 4294967097UL)
#define CMD_PLAYVIDEO (EVE_CHIPID >= EVE_BT820 ? 4294967093UL : 4294967098UL)
#define CMD_SETFONT2 (EVE_CHIPID >= EVE_BT820 ? 4294967094UL : 4294967099UL)
#define CMD_SETSCRATCH (EVE_CHIPID >= EVE_BT820 ? 4294967095UL : 4294967100UL)
#define CMD_ROMFONT (EVE_CHIPID >= EVE_BT820 ? 4294967097UL : 4294967103UL)
#define CMD_VIDEOSTART (EVE_CHIPID >= EVE_BT820 ? 4294967098UL : 4294967104UL)
#define CMD_VIDEOFRAME (EVE_CHIPID >= EVE_BT820 ? 4294967099UL : 4294967105UL)
#define CMD_SYNC (EVE_CHIPID >= EVE_BT820 ? 4294967100UL : 4294967106UL)
#define CMD_SETBITMAP (EVE_CHIPID >= EVE_BT820 ? 4294967101UL : 4294967107UL)

// BT815
#define CMD_ANIMFRAME (EVE_CHIPID >= EVE_BT820 ? 4294967134UL : 4294967130UL)
#define CMD_ANIMSTART (EVE_CHIPID >= EVE_BT820 ? 4294967135UL : 4294967123UL)
#define CMD_FLASHERASE (EVE_CHIPID >= EVE_BT820 ? 4294967102UL : 4294967108UL)
#define CMD_FLASHWRITE (EVE_CHIPID >= EVE_BT820 ? 4294967103UL : 4294967109UL)
#define CMD_FLASHREAD (EVE_CHIPID >= EVE_BT820 ? 4294967104UL : 4294967110UL)
#define CMD_FLASHUPDATE (EVE_CHIPID >= EVE_BT820 ? 4294967105UL : 4294967111UL)
#define CMD_FLASHDETACH (EVE_CHIPID >= EVE_BT820 ? 4294967106UL : 4294967112UL)
#define CMD_FLASHATTACH (EVE_CHIPID >= EVE_BT820 ? 4294967107UL : 4294967113UL)
#define CMD_FLASHFAST (EVE_CHIPID >= EVE_BT820 ? 4294967108UL : 4294967114UL)
#define CMD_FLASHSPIDESEL (EVE_CHIPID >= EVE_BT820 ? 4294967109UL : 4294967115UL)
#define CMD_FLASHSPITX (EVE_CHIPID >= EVE_BT820 ? 4294967110UL : 4294967116UL)
#define CMD_FLASHSPIRX (EVE_CHIPID >= EVE_BT820 ? 4294967111UL : 4294967117UL)
#define CMD_FLASHSOURCE (EVE_CHIPID >= EVE_BT820 ? 4294967112UL : 4294967118UL)
#define CMD_CLEARCACHE (EVE_CHIPID >= EVE_BT820 ? 4294967113UL : 4294967119UL)
#define CMD_INFLATE2 (EVE_CHIPID >= EVE_BT820 ? 4294967114UL : 4294967120UL)
#define CMD_ROTATEAROUND (EVE_CHIPID >= EVE_BT820 ? 4294967115UL : 4294967121UL)
#define CMD_RESETFONTS (EVE_CHIPID >= EVE_BT820 ? 4294967116UL : 4294967122UL)
#define CMD_ANIMSTOP (EVE_CHIPID >= EVE_BT820 ? 4294967117UL : 4294967124UL)
#define CMD_ANIMXY (EVE_CHIPID >= EVE_BT820 ? 4294967118UL : 4294967125UL)
#define CMD_ANIMDRAW (EVE_CHIPID >= EVE_BT820 ? 4294967119UL : 4294967126UL)
#define CMD_GRADIENTA (EVE_CHIPID >= EVE_BT820 ? 4294967120UL : 4294967127UL)
#define CMD_FILLWIDTH (EVE_CHIPID >= EVE_BT820 ? 4294967121UL : 4294967128UL)
#define CMD_APPENDF (EVE_CHIPID >= EVE_BT820 ? 4294967122UL : 4294967129UL)
#define CMD_NOP (EVE_CHIPID >= EVE_BT820 ? 4294967123UL : 4294967131UL)
#define CMD_VIDEOSTARTF 4294967135UL

// BT817
#define CMD_CALIBRATESUB (EVE_CHIPID >= EVE_BT820 ? 4294967126UL : 4294967136UL)
#define CMD_TESTCARD (EVE_CHIPID >= EVE_BT820 ? 4294967127UL : 4294967137UL)
#define CMD_HSF 4294967138UL	 
#define CMD_APILEVEL 4294967139UL 
#define CMD_GETIMAGE (EVE_CHIPID >= EVE_BT820 ? 4294967128UL : 4294967140UL)
#define CMD_WAIT (EVE_CHIPID >= EVE_BT820 ? 4294967129UL : 4294967141UL)
#define CMD_RETURN (EVE_CHIPID >= EVE_BT820 ? 4294967130UL : 4294967142UL)
#define CMD_CALLLIST (EVE_CHIPID >= EVE_BT820 ? 4294967131UL : 4294967143UL)
#define CMD_NEWLIST (EVE_CHIPID >= EVE_BT820 ? 4294967132UL : 4294967144UL)
#define CMD_ENDLIST (EVE_CHIPID >= EVE_BT820 ? 4294967133UL : 4294967145UL)
#define CMD_PCLKFREQ 4294967146UL
#define CMD_FONTCACHE 4294967147UL
#define CMD_FONTCACHEQUERY 4294967148UL
#define CMD_ANIMFRAMERAM (EVE_CHIPID >= EVE_BT820 ? 4294967134UL : 4294967149UL)
#define CMD_ANIMSTARTRAM (EVE_CHIPID >= EVE_BT820 ? 4294967135UL : 4294967150UL)
#define CMD_RUNANIM (EVE_CHIPID >= EVE_BT820 ? 4294967136UL : 4294967151UL)
#define CMD_FLASHPROGRAM (EVE_CHIPID >= EVE_BT820 ? 4294967140UL : 4294967152UL)

// BT820


// clang-format on

/*****************
** Display List **
*****************/

#define VERTEX2F(x, y) ((1UL << 30) | (((x)&32767UL) << 15) | (((y)&32767UL) << 0))
#define VERTEX2II(x, y, handle, cell) ((2UL << 30) | (((x)&511UL) << 21) | (((y)&511UL) << 12) | (((handle)&31UL) << 7) | (((cell)&127UL) << 0))
#define BITMAP_SOURCE(addr) ((1UL << 24) | ((addr) < 0 ? (((addr) & (BITMAP_ADDR_MASK >> 1))) : ((addr)&BITMAP_ADDR_MASK)))
#define BITMAP_SOURCE2(flash_or_ram, addr) ((1UL << 24) | ((flash_or_ram) << 23) | (((addr) & (BITMAP_ADDR_MASK >> 1)) << 0))
#define CLEAR_COLOR_RGB(red, green, blue) ((2UL << 24) | (((red)&255UL) << 16) | (((green)&255UL) << 8) | (((blue)&255UL) << 0))
#define TAG(s) ((3UL << 24) | (((s)&TAG_DL_MASK) << 0))
#define COLOR_RGB(red, green, blue) ((4UL << 24) | (((red)&255UL) << 16) | (((green)&255UL) << 8) | (((blue)&255UL) << 0))
#define BITMAP_HANDLE(handle) ((5UL << 24) | (((handle)&BITMAP_HANDLE_MASK) << 0))
#define CELL(cell) ((6UL << 24) | (((cell)&127UL) << 0))
#define BITMAP_LAYOUT(format, linestride, height) ((7UL << 24) | (((format)&31UL) << 19) | (((linestride)&1023UL) << 9) | (((height)&511UL) << 0))
#define BITMAP_SIZE(filter, wrapx, wrapy, width, height) ((8UL << 24) | (((filter)&1UL) << 20) | (((wrapx)&1UL) << 19) | (((wrapy)&1UL) << 18) | (((width)&511UL) << 9) | (((height)&511UL) << 0))
#define ALPHA_FUNC(func, ref) ((9UL << 24) | (((func)&7UL) << 8) | (((ref)&255UL) << 0))
#define STENCIL_FUNC(func, ref, mask) ((10UL << 24) | (((func)&7UL) << 16) | (((ref)&255UL) << 8) | (((mask)&255UL) << 0))
#define BLEND_FUNC(src, dst) ((11UL << 24) | (((src)&7UL) << 3) | (((dst)&7UL) << 0))
#define STENCIL_OP(sfail, spass) ((12UL << 24) | (((sfail)&7UL) << 3) | (((spass)&7UL) << 0))
#define POINT_SIZE(size) ((13UL << 24) | (((size)&8191UL) << 0))
#define LINE_WIDTH(width) ((14UL << 24) | (((width)&4095UL) << 0))
#define CLEAR_COLOR_A(alpha) ((15UL << 24) | (((alpha)&255UL) << 0))
#define COLOR_A(alpha) ((16UL << 24) | (((alpha)&255UL) << 0))
#define CLEAR_STENCIL(s) ((17UL << 24) | (((s)&255UL) << 0))
#define CLEAR_TAG(s) ((18UL << 24) | (((s)&TAG_DL_MASK) << 0))
#define STENCIL_MASK(mask) ((19UL << 24) | (((mask)&255UL) << 0))
#define TAG_MASK(mask) ((20UL << 24) | (((mask)&1UL) << 0))
#define BITMAP_TRANSFORM_C(c) ((23UL << 24) | (((c)&16777215UL) << 0))
#define BITMAP_TRANSFORM_F(f) ((26UL << 24) | (((f)&16777215UL) << 0))
#define BITMAP_TRANSFORM_A_EXT(p, v) ((21UL << 24) | (((p)&1UL) << 17) | (((v)&131071UL) << 0))
#define BITMAP_TRANSFORM_B_EXT(p, v) ((22UL << 24) | (((p)&1UL) << 17) | (((v)&131071UL) << 0))
#define BITMAP_TRANSFORM_D_EXT(p, v) ((24UL << 24) | (((p)&1UL) << 17) | (((v)&131071UL) << 0))
#define BITMAP_TRANSFORM_E_EXT(p, v) ((25UL << 24) | (((p)&1UL) << 17) | (((v)&131071UL) << 0))
#define BITMAP_TRANSFORM_A(a) BITMAP_TRANSFORM_A_EXT(0, a)
#define BITMAP_TRANSFORM_B(b) BITMAP_TRANSFORM_B_EXT(0, b)
#define BITMAP_TRANSFORM_D(d) BITMAP_TRANSFORM_D_EXT(0, d)
#define BITMAP_TRANSFORM_E(e) BITMAP_TRANSFORM_E_EXT(0, e)
#define SCISSOR_XY(x, y) ((27UL << 24) | (((x)&SCISSOR_XY_MASK) << SCISSOR_XY_SHIFT) | (((y)&SCISSOR_XY_MASK) << 0))
#define SCISSOR_SIZE(width, height) ((28UL << 24) | (((width)&SCISSOR_SIZE_MASK) << SCISSOR_SIZE_SHIFT) | (((height)&SCISSOR_SIZE_MASK) << 0))
#define CALL(dest) ((29UL << 24) | (((dest)&65535UL) << 0))
#define JUMP(dest) ((30UL << 24) | (((dest)&65535UL) << 0))
#define BEGIN(prim) ((31UL << 24) | (((prim)&15UL) << 0))
#define COLOR_MASK(r, g, b, a) ((32UL << 24) | (((r)&1UL) << 3) | (((g)&1UL) << 2) | (((b)&1UL) << 1) | (((a)&1UL) << 0))
#define CLEAR(c, s, t) ((38UL << 24) | (((c)&1UL) << 2) | (((s)&1UL) << 1) | (((t)&1UL) << 0))
#define VERTEX_FORMAT(frac) ((39UL << 24) | (((frac)&7UL) << 0))
#define BITMAP_LAYOUT_H(linestride, height) ((40UL << 24) | (((linestride)&BITMAP_LAYOUT_H_STRIDE_MASK) << 2) | (((height)&3UL) << 0))
#define BITMAP_SIZE_H(width, height) ((41UL << 24) | (((width)&3UL) << 2) | (((height)&3UL) << 0))
#define PALETTE_SOURCE(addr) ((42UL << 24) | (((addr)&PALETTE_ADDR_MASK) << 0))
#define VERTEX_TRANSLATE_X(x) ((43UL << 24) | (((x)&131071UL) << 0))
#define VERTEX_TRANSLATE_Y(y) ((44UL << 24) | (((y)&131071UL) << 0))
#define NOP() ((45UL << 24))
#define BITMAP_EXT_FORMAT(format) ((46UL << 24) | (((format)&65535UL) << 0))
#define BITMAP_SWIZZLE(r, g, b, a) ((47UL << 24) | (((r)&7UL) << 9) | (((g)&7UL) << 6) | (((b)&7UL) << 3) | (((a)&7UL) << 0))
#define INT_FRR() ((48UL << 24))
#define INT_PALDAT() ((48UL << 24))
#define BITMAP_SOURCEH(addr) ((49UL << 24) | (((addr)&255UL) << 0))
#define PALETTE_SOURCEH(addr) ((50UL << 24) | (((addr)&255UL) << 0))
#define BITMAP_ZORDER(o) ((51UL << 24) | (((o)&255UL) << 0))
#define REGION(y, h, dest) ((52UL << 24) | (((y)&63UL) << 18) | (((h)&63UL) << 12) | (((dest)&4095UL) << 0))
#define SYS_PSEUDO_BASE(p) ((53UL << 24) | (((p)&2047UL) << 0))
#define END() ((33UL << 24))
#define SAVE_CONTEXT() ((34UL << 24))
#define RESTORE_CONTEXT() ((35UL << 24))
#define RETURN() ((36UL << 24))
#define MACRO(m) ((37UL << 24) | (((m)&1UL) << 0))
#define DISPLAY() ((0UL << 24))
#define BITMAP_SOURCE_H(addr) BITMAP_SOURCEH(addr)
#define PALETTE_SOURCE_H(addr) PALETTE_SOURCEH(addr)

/************
** Options **
************/

#ifdef POINTS
#undef POINTS
#endif

#define DLSWAP_DONE 0UL
#define DLSWAP_LINE 1UL
#define DLSWAP_FRAME 2UL

ESD_ENUM(Ft_CoPro_Opt, Type = uint16_t, Include = "EVE_Hal.h", Flags)
#define OPT_3D 0UL
#define OPT_RGB565 0UL
#define OPT_MONO 1UL
#define OPT_NODL 2UL
#define OPT_NOTEAR 4UL
#define OPT_FULLSCREEN 8UL
#define OPT_MEDIAFIFO 16UL
#define OPT_SOUND 32UL
#define OPT_FLASH 64UL
#define OPT_OVERLAY 128UL
#define OPT_FLAT 256UL
#define OPT_SIGNED 256UL
#define OPT_DITHER 256UL
#define OPT_CENTERX 512UL
#define OPT_CENTERY 1024UL
#define OPT_CENTER 1536UL
#define OPT_FORMAT 4096UL
#define OPT_NOBACK 4096UL
#define OPT_FILL 8192UL
#define OPT_NOHM 16384UL
#define OPT_NOPOINTER 16384UL
#define OPT_NOSECS 32768UL
#define OPT_NOHANDS 49152UL
#define OPT_NOTICKS 8192UL
#define OPT_RIGHTX 2048UL

// BT820
#define OPT_4BIT 2UL
#define OPT_BASELINE 32768UL
#define OPT_CASESENSITIVE 2UL
#define OPT_COMPLETEREG 4096UL
#define OPT_DIRECT 2048UL
#define OPT_DIRSEP_UNIX 8UL
#define OPT_DIRSEP_WIN 4UL
#define OPT_FS 8192UL
#define OPT_HALFSPEED 4UL
#define OPT_IS_MMC 16UL
#define OPT_IS_SD 32UL
#define OPT_NOKERN 16384UL
#define OPT_QUARTERSPEED 8UL
#define OPT_SFNLOWER 1UL
#define OPT_SIMULATION 1UL
#define OPT_TRUECOLOR 512UL
#define OPT_YCBCR 1024UL
#define OTP_CFG 2139097348UL
#define OTP_CTL 2139097344UL
#define OTP_LOCK 2139097356UL
#define OTP_PRG_TIMING0 2139097360UL
#define OTP_PRG_TIMING1 2139097364UL
#define OTP_PRG_TIMING2 2139097368UL
#define OTP_PRG_TIMING3 2139097372UL
#define OTP_RBUFFER0 2139097408UL
#define OTP_RBUFFER1 2139097412UL
#define OTP_RBUFFER2 2139097416UL
#define OTP_RBUFFER3 2139097420UL
#define OTP_RD_TIMING 2139097376UL
#define OTP_STATUS 2139097352UL
#define OTP_WBUFFER0 2139097392UL
#define OTP_WBUFFER1 2139097396UL
#define OTP_WBUFFER2 2139097400UL
#define OTP_WBUFFER3 2139097404UL
ESD_END()

#define ANIM_ONCE 0UL
#define ANIM_LOOP 1UL
#define ANIM_HOLD 2UL

#define COMPRESSED_RGBA_ASTC_4x4_KHR 37808UL
#define COMPRESSED_RGBA_ASTC_5x4_KHR 37809UL
#define COMPRESSED_RGBA_ASTC_5x5_KHR 37810UL
#define COMPRESSED_RGBA_ASTC_6x5_KHR 37811UL
#define COMPRESSED_RGBA_ASTC_6x6_KHR 37812UL
#define COMPRESSED_RGBA_ASTC_8x5_KHR 37813UL
#define COMPRESSED_RGBA_ASTC_8x6_KHR 37814UL
#define COMPRESSED_RGBA_ASTC_8x8_KHR 37815UL
#define COMPRESSED_RGBA_ASTC_10x5_KHR 37816UL
#define COMPRESSED_RGBA_ASTC_10x6_KHR 37817UL
#define COMPRESSED_RGBA_ASTC_10x8_KHR 37818UL
#define COMPRESSED_RGBA_ASTC_10x10_KHR 37819UL
#define COMPRESSED_RGBA_ASTC_12x10_KHR 37820UL
#define COMPRESSED_RGBA_ASTC_12x12_KHR 37821UL

#define FLASH_DEFAULT_SHA1KEY 0xf589cf07

#define KEEP 1UL
#define REPLACE 2UL
#define INCR 3UL
#define DECR 4UL
#define INVERT 5UL

#define ZERO 0UL
#define ONE 1UL
#define SRC_ALPHA 2UL
#define DST_ALPHA 3UL
#define ONE_MINUS_SRC_ALPHA 4UL
#define ONE_MINUS_DST_ALPHA 5UL

#define RED 2UL
#define GREEN 3UL
#define BLUE 4UL
#define ALPHA 5UL

#define NEVER 0UL
#define LESS 1UL
#define LEQUAL 2UL
#define GREATER 3UL
#define GEQUAL 4UL
#define EQUAL 5UL
#define NOTEQUAL 6UL
#define ALWAYS 7UL

#define ARGB1555 0UL
#define L1 1UL
#define L4 2UL
#define L8 3UL
#define RGB332 4UL
#define ARGB2 5UL
#define ARGB4 6UL
#define RGB565 7UL
#define PALETTED 8UL
#define TEXT8X8 9UL
#define TEXTVGA 10UL
#define BARGRAPH 11UL
#define PALETTED565 14UL
#define PALETTED4444 15UL
#define PALETTED8 16UL
#define L2 17UL
#define GLFORMAT 31UL

#define FLASH_STATUS_INIT 0UL
#define FLASH_STATUS_DETACHED 1UL
#define FLASH_STATUS_BASIC 2UL
#define FLASH_STATUS_FULL 3UL

#define NEAREST 0UL
#define BILINEAR 1UL

#define LINEAR_SAMPLES 0UL
#define ULAW_SAMPLES 1UL
#define ADPCM_SAMPLES 2UL

#define BITMAPS 1UL
#define POINTS 2UL
#define LINES 3UL
#define LINE_STRIP 4UL
#define EDGE_STRIP_R 5UL
#define EDGE_STRIP_L 6UL
#define EDGE_STRIP_A 7UL
#define EDGE_STRIP_B 8UL
#define RECTS 9UL

#define FTPOINTS POINTS

#define TOUCHMODE_OFF 0UL
#define TOUCHMODE_ONESHOT 1UL
#define TOUCHMODE_FRAME 2UL
#define TOUCHMODE_CONTINUOUS 3UL

#define BORDER 0UL
#define REPEAT 1UL

#define ADC_SINGLE_ENDED 0UL
#define ADC_DIFFERENTIAL 1UL

#define CTOUCH_MODE_COMPATIBILITY 1UL
#define CTOUCH_MODE_EXTENDED 0UL

#define INT_SWAP 1UL
#define INT_TOUCH 2UL
#define INT_TAG 4UL
#define INT_SOUND 8UL
#define INT_L8C 12UL
#define INT_VGA 13UL
#define INT_G8 18UL
#define INT_PLAYBACK 16UL
#define INT_CMDEMPTY 32UL
#define INT_CMDFLAG 64UL
#define INT_CONVCOMPLETE 128UL
#define INT_UNDERRUN 256UL





// Address where register area starts
#define EVE_REG_BASE RAM_DL

// Address for ROM font 16 to 34
static inline uint32_t EVE_Hal_romFontAddress(EVE_HalContext *phost, uint32_t romFont)
{
	{
		const uint32_t romFontTableAddr = EVE_Hal_rd32(phost, ROMFONT_TABLEADDRESS);
		const uint32_t romFontAddr = romFontTableAddr + (EVE_GPU_FONT_TABLE_SIZE * (romFont - 16));
		return romFontAddr;
	}
}

#endif /* #ifndef EVE_GPU_DEFS__H */

/* end of file */

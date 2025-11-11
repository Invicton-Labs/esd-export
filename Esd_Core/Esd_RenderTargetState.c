
#include "Esd_RenderTargetState.h"

#include "Esd_Context.h"

// Persistent state in RAM_G, stored after bitmap buffer
// - Backup of the previous display list (plus CMD_NEWLIST and CMD_ENDLIST)
// - Backup of REG_RE_ROTATE
// - Readout of REG_TOUCH_TAG after render engine completes this render target
#define ESD_RT_STATE_SIZE (EVE_DL_SIZE + 16)
#define ESD_RT_STATE_OFFSET_DL (0)
#define ESD_RT_STATE_OFFSET_ROTATE (EVE_DL_SIZE + 8)
#define ESD_RT_STATE_OFFSET_TAG (EVE_DL_SIZE + 12)

/* TODO: If drawing a render target outside of RENDER ESD state, then we can bypass the state backup mechanisms */
/* Then set a special flag or set to RENDER state temporarily */

/* TODO: Add a separate render pass for processing render targets separately without requiring context backups */

ESD_CORE_EXPORT uint32_t Esd_RenderTarget_DlStart(Esd_BitmapInfo *info, Esd_RenderTargetState *state, int16_t offsetX, int16_t offsetY)
{
	return GA_INVALID;
}

ESD_CORE_EXPORT void Esd_RenderTarget_DisplaySwap(Esd_BitmapInfo *info, Esd_RenderTargetState *state)
{
}

ESD_CORE_EXPORT eve_tag_t Esd_RenderTarget_TouchTag(Esd_BitmapInfo *info)
{
}

/* end of file */

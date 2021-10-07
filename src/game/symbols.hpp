#pragma once

#define WEAK __declspec(selectany)

namespace game
{
	WEAK symbol<gentity_s> g_entities{ 0x21EF7C0, 0x21C13C0 };
	WEAK symbol<level_locals_t> level_locals{ 0x2366B80, 0x2338780 };
	WEAK symbol<scrVmPub_t> scrVmPub{ 0x2E1A5D0, 0x2DEA8D0 };

	WEAK symbol<void(scriptInstance_t)> Scr_AddArray{ 0x62D3F0, 0x4BB540 };
	WEAK symbol<void(scriptInstance_t, unsigned short)> Scr_AddArrayStringIndexed{ 0x618C90, 0x4212F0 };
	WEAK symbol<void(scriptInstance_t, gentity_s*)> Scr_AddEntity{ 0x4C20F0, 0x5D8F80 };
	WEAK symbol<void(scriptInstance_t, float)> Scr_AddFloat{ 0x579130, 0x503480 };
	WEAK symbol<void(scriptInstance_t, int)> Scr_AddInt{ 0x57AFF0, 0x643A40 };
	WEAK symbol<void(scriptInstance_t, const char*)> Scr_AddString{ 0x4F1650, 0x6A7A70 };
	WEAK symbol<void(scriptInstance_t, float*)> Scr_AddVector{ 0x4C1A40, 0x4FAB00 };
	WEAK symbol<gentity_s* (scriptInstance_t, int)> Scr_GetEntity{ 0x48F250, 0x489100 };
	WEAK symbol<float(scriptInstance_t, int)> Scr_GetFloat{ 0x633400, 0x625EE0 };
	WEAK symbol<int(scriptInstance_t, int)> Scr_GetInt{ 0x45D840, 0x49A060 };
	WEAK symbol<int(scriptInstance_t)> Scr_GetNumParam{ 0x42E990, 0x680EA0 };
	WEAK symbol<const char*(scriptInstance_t, int)> Scr_GetString{ 0x67C6A0, 0x488110 };
	WEAK symbol<void(scriptInstance_t, int, float*)> Scr_GetVector{ 0x4CBCC0, 0x4BB100 };
	WEAK symbol<void(scriptInstance_t)> Scr_MakeArray{ 0x64A960, 0x4C0E70 };
	WEAK symbol<void(gentity_s*, unsigned short, int)> Scr_Notify{ 0x644AB0, 0x495420 };
	WEAK symbol<void(const char*)> Scr_NotifyLevel{ 0x486DE0, 0x691150 };
	WEAK symbol<void(unsigned int, unsigned int, unsigned short, int)> Scr_NotifyNum{ 0x578690, 0x664770 };

	WEAK symbol<const char* (unsigned int)> SL_ConvertToString{ 0x422D10, 0x0 };
	WEAK symbol<unsigned short(const char*, int)> SL_GetString{ 0x602C40, 0x4601E0 };
}
#include <stdafx.hpp>

gentity_s* g_entities = reinterpret_cast<gentity_s*>(0x21EF7C0);

void(__cdecl* Scr_AddEntity)(scriptInstance_t, gentity_s*) = (decltype(Scr_AddEntity))0x4C20F0;
void(__cdecl* Scr_AddFloat)(scriptInstance_t, float) = (decltype(Scr_AddFloat))0x579130;
void(__cdecl* Scr_AddInt)(scriptInstance_t, int) = (decltype(Scr_AddInt))0x57AFF0;
void(__cdecl* Scr_AddString)(scriptInstance_t, const char*) = (decltype(Scr_AddString))0x4F1650;
void(__cdecl* Scr_AddVector)(scriptInstance_t, float*) = (decltype(Scr_AddVector))0x4C1A40;

int(__cdecl* Scr_GetNumParam)(scriptInstance_t) = (decltype(Scr_GetNumParam))0x42E990;

gentity_s* (__cdecl* Scr_GetEntity)(scriptInstance_t, int) = (decltype(Scr_GetEntity))0x48F250;
float(__cdecl* Scr_GetFloat)(scriptInstance_t, int) = (decltype(Scr_GetFloat))0x633400;
int(__cdecl* Scr_GetInt)(scriptInstance_t, int) = (decltype(Scr_GetInt))0x45D840;
const char* (__cdecl* Scr_GetString)(scriptInstance_t, int) = (decltype(Scr_GetString))0x67C6A0;
void(__cdecl* Scr_GetVector)(scriptInstance_t, int, float*) = (decltype(Scr_GetVector))0x4CBCC0;
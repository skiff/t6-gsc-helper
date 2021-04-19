#pragma once

#define SELECT(mp, zm) (game::is_mp() ? mp : zm)

namespace game
{
	enum gamemode
	{
		none,
		multiplayer,
		zombies
	};

	extern gamemode current;

	extern gentity_s* g_entities;

	extern void(__cdecl* Scr_AddEntity)(scriptInstance_t inst, gentity_s* entity);
	extern void(__cdecl* Scr_AddFloat)(scriptInstance_t inst, float value);
	extern void(__cdecl* Scr_AddInt)(scriptInstance_t inst, int value);
	extern void(__cdecl* Scr_AddString)(scriptInstance_t inst, const char* value);
	extern void(__cdecl* Scr_AddVector)(scriptInstance_t inst, float* value);

	extern int(__cdecl* Scr_GetNumParam)(scriptInstance_t inst);

	extern gentity_s* (__cdecl* Scr_GetEntity)(scriptInstance_t inst, int index);
	extern float(__cdecl* Scr_GetFloat)(scriptInstance_t inst, int index);
	extern int(__cdecl* Scr_GetInt)(scriptInstance_t inst, int index);
	extern const char* (__cdecl* Scr_GetString)(scriptInstance_t inst, int index);
	extern void(__cdecl* Scr_GetVector)(scriptInstance_t inst, int index, float* out);

	bool is_mp();
	bool is_zm();
	void init();
}
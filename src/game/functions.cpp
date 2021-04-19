#include <stdafx.hpp>

namespace game
{
	gamemode current = gamemode::none;

	gentity_s* g_entities;

	void(__cdecl* Scr_AddEntity)(scriptInstance_t, gentity_s*);
	void(__cdecl* Scr_AddFloat)(scriptInstance_t, float);
	void(__cdecl* Scr_AddInt)(scriptInstance_t, int);
	void(__cdecl* Scr_AddString)(scriptInstance_t, const char*);
	void(__cdecl* Scr_AddVector)(scriptInstance_t, float*);

	gentity_s* (__cdecl* Scr_GetEntity)(scriptInstance_t, int);
	float(__cdecl* Scr_GetFloat)(scriptInstance_t, int);
	int(__cdecl* Scr_GetInt)(scriptInstance_t, int);
	int(__cdecl* Scr_GetNumParam)(scriptInstance_t);
	const char* (__cdecl* Scr_GetString)(scriptInstance_t, int);
	void(__cdecl* Scr_GetVector)(scriptInstance_t, int, float*);

	bool is_mp()
	{
		return current == gamemode::multiplayer;
	}

	bool is_zm()
	{
		return current == gamemode::zombies;
	}

	void init()
	{
		current = (strcmp(reinterpret_cast<const char*>(0xC2F028), "multiplayer") == 0) ? gamemode::multiplayer : gamemode::zombies;

		g_entities = reinterpret_cast<gentity_s*>(SELECT(0x21EF7C0, 0x21C13C0));

		Scr_AddEntity = (decltype(Scr_AddEntity))SELECT(0x4C20F0, 0x5D8F80);
		Scr_AddFloat = (decltype(Scr_AddFloat))SELECT(0x579130, 0x503480);
		Scr_AddInt = (decltype(Scr_AddInt))SELECT(0x57AFF0, 0x643A40);
		Scr_AddString = (decltype(Scr_AddString))SELECT(0x4F1650, 0x6A7A70);
		Scr_AddVector = (decltype(Scr_AddVector))SELECT(0x4C1A40, 0x4FAB00);

		Scr_GetEntity = (decltype(Scr_GetEntity))SELECT(0x48F250, 0x489100);
		Scr_GetFloat = (decltype(Scr_GetFloat))SELECT(0x633400, 0x625EE0);
		Scr_GetInt = (decltype(Scr_GetInt))SELECT(0x45D840, 0x49A060);
		Scr_GetNumParam = (decltype(Scr_GetNumParam))SELECT(0x42E990, 0x680EA0);
		Scr_GetString = (decltype(Scr_GetString))SELECT(0x67C6A0, 0x488110);
		Scr_GetVector = (decltype(Scr_GetVector))SELECT(0x4CBCC0, 0x4BB100);
	}
}

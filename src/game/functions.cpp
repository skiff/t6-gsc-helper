#include <stdafx.hpp>

namespace game
{
	gamemode current = gamemode::none;

	bool is_mp()
	{
		return current == gamemode::multiplayer;
	}

	bool is_zm()
	{
		return current == gamemode::zombies;
	}

	void set_mode()
	{
		current = (strcmp(reinterpret_cast<const char*>(0xC2F028), "multiplayer") == 0) ? gamemode::multiplayer : gamemode::zombies;
	}
}

#include <stdafx.hpp>

/*
	Date: December 18th, 2020

	Note: This is for use as a server plugin on plutonium-t6 dedicated servers.
		  This will not work on the client and you WILL be banned if you try to load/inject this outside of a dedicated server.
*/

BOOL APIENTRY DllMain(HMODULE module_, DWORD ul_reason_for_call, LPVOID reserved_)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		game::init();

		gsc::setup();
	}

	return TRUE;
}
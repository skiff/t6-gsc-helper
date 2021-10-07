#include <stdafx.hpp>

void function_example()
{
	/*
	Getting parameters
	*/
	auto string_param = gsc::value::get<const char*>(0);
	auto int_param = gsc::value::get<int>(1);

	/*
	Return int value
	*/
	gsc::value::add<int>(10);

	/*
	Return vector value
	*/
	float origin[3] = { 100.0f, 100.0f, 100.0f };
	gsc::value::add<float*>(origin);

	/*
	Return string-indexed array (i.e. how BulletTrace works)
	*/
	gsc::array::create();
	gsc::array::set<int>("arrayValue", 100); //accessed in gsc by value["arrayValue"]

	/*
	Return int-indexed array
	*/
	gsc::array::create();
	gsc::array::set<int>(100); //value[0] = 100
	gsc::array::set<int>(200); //value[1] = 200 etc

	/*
	Notify the 'level' entity
	*/
	auto notify = gsc::notify::create("level_custom_notify"); //can be used with `level waittill( "level_custom_notify" )`
	notify->send();
}

void method_example(game::scr_entref_t ent)
{
	/*
	Get the entity from the entref
	*/
	auto* entity = &game::g_entities[ent.entnum];

	/*
	Notify the entity
	*/
	auto notify = gsc::notify::create("custom_notify"); //can be used with `self waittill( "custom_notify", message )`
	notify->add<const char*>("extra message"); // add a parameter to the notify
	notify->send(entity);
}

BOOL APIENTRY DllMain(HMODULE module_, DWORD ul_reason_for_call, LPVOID reserved_)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		game::set_mode();
		gsc::function::init();
		gsc::method::init();

		gsc::function::add("function_example", 0, 4, function_example);
		gsc::method::add("method_example", 0, 4, method_example);
	}

	return TRUE;
}
#include <stdafx.hpp>
#include "methods.hpp"

std::unordered_map<std::string, BuiltinMethodDef> method::registered_methods;

void method::add(const char* name, int min_args, int max_args, void(*f)(scr_entref_t))
{
    if (find(name) != nullptr)
        return;

    registered_methods[name] = {};
    auto itr = registered_methods.find(name);

    itr->second.actionString = name;
    itr->second.type = 1;
    itr->second.min_args = min_args;
    itr->second.max_args = max_args;
    itr->second.actionFunc = f;
}

BuiltinMethodDef* method::find(const std::string& name)
{
    auto itr = registered_methods.find(name);
    if (itr != registered_methods.end())
        return &itr->second;

    return nullptr;
}

/*
    This method takes no parameters and returns a string
*/
void method::example_one(scr_entref_t entref)
{
    // get the calling entity
    auto* self = &game::g_entities[entref.entnum];
    auto num = self->entity_num;

    // do your logic here

    game::Scr_AddString(SCRIPTINSTANCE_SERVER, "hello world");
}

/*
    This function takes two required parameters and returns a float
       - Both parameters are string types
*/
void method::example_two(scr_entref_t entref)
{
    // get the calling entity
    auto* self = &game::g_entities[entref.entnum];
    auto num = self->entity_num;

    auto* parameter_one = game::Scr_GetString(SCRIPTINSTANCE_SERVER, 0); // index 0 represents the first parameter
    auto* parameter_two = game::Scr_GetString(SCRIPTINSTANCE_SERVER, 1); // index 1 represents the second parameter
    // If the parameters were integers, you would need to use Scr_GetInt

    // do your logic here

    game::Scr_AddFloat(SCRIPTINSTANCE_SERVER, 100.0f);
}

/*
    This function takes one required parameter and one optional parameter and returns an integer
       - Both parameters are string types
*/
void method::example_three(scr_entref_t entref)
{
    // get the calling entity
    auto* self = &game::g_entities[entref.entnum];
    auto num = self->entity_num;

    auto* parameter_one = game::Scr_GetString(SCRIPTINSTANCE_SERVER, 0); // index 0 represents the first parameter
    const char* parameter_two = nullptr;

    // Since the second parameter is optional, we need to verify that it was given before trying to read it
    if (game::Scr_GetNumParam(SCRIPTINSTANCE_SERVER) > 1)
    {
        parameter_two = game::Scr_GetString(SCRIPTINSTANCE_SERVER, 1); // index 1 represents the second parameter
    }

    // do your logic here

    game::Scr_AddInt(SCRIPTINSTANCE_SERVER, num);
}
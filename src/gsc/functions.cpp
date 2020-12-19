#include <stdafx.hpp>
#include "functions.hpp"

std::unordered_map<std::string, BuiltinFunctionDef> function::registered_functions;

void function::add(const char* name, int min_args, int max_args, void(*f)())
{
    if (find(name) != nullptr)
        return;

    registered_functions[name] = {};
    auto itr = registered_functions.find(name);

    itr->second.actionString = name;
    itr->second.type = 1;
    itr->second.min_args = min_args;
    itr->second.max_args = max_args;
    itr->second.actionFunc = f;
}

BuiltinFunctionDef* function::find(const std::string& name)
{
    auto itr = registered_functions.find(name);
    if (itr != registered_functions.end())
        return &itr->second;

    return nullptr;
}

/*
    This function takes no parameters and returns a string
*/
void function::example_one()
{
    // do your logic here

    // use an "Scr_Add" function to set the return value at the end of your function
    // if this was supposed to return an integer, you would use Scr_AddInt
    game::Scr_AddString(SCRIPTINSTANCE_SERVER, "hello world");
}

/*
    This function takes two required parameters and returns a float
       - Both parameters are string types
*/
void function::example_two()
{
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
void function::example_three()
{
    auto* parameter_one = game::Scr_GetString(SCRIPTINSTANCE_SERVER, 0); // index 0 represents the first parameter
    const char* parameter_two = nullptr;
    
    // Since the second parameter is optional, we need to verify that it was given before trying to read it
    if (game::Scr_GetNumParam(SCRIPTINSTANCE_SERVER) > 1)
    {
        parameter_two = game::Scr_GetString(SCRIPTINSTANCE_SERVER, 1); // index 1 represents the second parameter
    }

    // do your logic here

    game::Scr_AddInt(SCRIPTINSTANCE_SERVER, 100);
}
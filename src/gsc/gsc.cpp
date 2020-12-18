#include <stdafx.hpp>

#include "gsc/functions.hpp"
#include "gsc/methods.hpp"

void(*scr_get_common_function(const char** pName, int* type, int* min_args, int* max_args))()
{
    auto func = function::find(*pName);
    if (func == nullptr)
        return 0;

    *pName = func->actionString;
    *type = func->type;
    *min_args = func->min_args;
    *max_args = func->max_args;
    return func->actionFunc;
}

void(*player_get_method(const char** pName, int* min_args, int* max_args))(scr_entref_t)
{
    auto method = method::find(*pName);
    if (method == nullptr)
        return 0;

    *pName = method->actionString;
    *min_args = method->min_args;
    *max_args = method->max_args;
    return method->actionFunc;
}

void gsc::setup()
{
    hook::call(0x4B580D, scr_get_common_function);
    hook::call(0x59D0AE, player_get_method);

    /*
    Here is where you should add you custom gsc functions

    Notes:
        - All functions and methods added MUST be lowercase with no spaces
        - Every function that takes and scriptInstance_t parameter, use SCRIPTINSTANCE_SERVER
        - This DOES NOT show you how to add type safety or error checking. If you add a function and give it wrong parameters you will have issues or crash the server
        - Functions are used to add calls that do not require an entity
            An example of this is like calling "Distance", "BulletTrace", "Min" etc
        - Methods are used to add calls that REQUIRE an entity
            An example of this is like calling "GiveWeapon", "iPrintln", "Suicide" etc
    */

    // Function that does not take any parameters
    // You would call this in gsc with `exampleFunctionOne()`
    function::add("examplefunctionone", 0, 0, function::example_one);

    // Function that takes required parameters
    // You would call this in gsc with `exampleFunctionTwo("hello", "world")`
    function::add("examplefunctiontwo", 2, 2, function::example_two);

    // Function that takes required and optional parameters
    // You would call this in gsc with `exampleFunctionThree("hello")` OR `exampleFunctionThree("hello", "optional parameter")`
    function::add("examplefunctionthree", 1, 2, function::example_three);

    // Method that does not take any parameters
    // You would call this in gsc with `self exampleMethodOne()`
    method::add("examplemethodone", 0, 0, method::example_one);

    // Method that takes required parameters
    // You would call this in gsc with `self exampleMethodTwo("hello", "world")`
    method::add("examplemethodtwo", 2, 2, method::example_two);

    // Method that takes required and optional parameters
    // You would call this in gsc with `self exampleMethodThree("hello")` OR `self exampleMethodThree("hello", "optional parameter")`
    method::add("examplemethodthree", 1, 2, method::example_three);
}
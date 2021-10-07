#include <stdafx.hpp>

namespace gsc
{
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

    void* (__cdecl* scr_get_common_function_t)(const char**, int*, int*, int*) = nullptr;
    void(*scr_get_common_function(const char** pName, int* type, int* min_args, int* max_args))()
    {
        auto func = function::find(*pName);
        if (func == nullptr)
        {
            auto value = scr_get_common_function_t(pName, type, min_args, max_args);
            return reinterpret_cast<void(__cdecl*)()>(value);
        }

        *pName = func->actionString;
        *type = func->type;
        *min_args = func->min_args;
        *max_args = func->max_args;
        return func->actionFunc;
    }

    void function::init()
    {
        // This function is also hooked by Plutonium, so we need to get the plutonium hook to call
        scr_get_common_function_t = reinterpret_cast<decltype(scr_get_common_function_t)>(hook::get_relative(SELECT(0x4B57B0, 0x4AD040)));
        hook::jump(SELECT(0x4B57B0, 0x4AD040), scr_get_common_function);
    }
}
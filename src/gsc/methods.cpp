#include <stdafx.hpp>

namespace gsc
{
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

    void* (__cdecl* player_get_method_t)(const char**, int*, int*) = nullptr;
    void(*player_get_method(const char** pName, int* min_args, int* max_args))(scr_entref_t)
    {
        auto method = method::find(*pName);
        if (method == nullptr)
        {
            auto value = player_get_method_t(pName, min_args, max_args);
            return reinterpret_cast<void(__cdecl*)(scr_entref_t)>(value);
        }

        *pName = method->actionString;
        *min_args = method->min_args;
        *max_args = method->max_args;
        return method->actionFunc;
    }

    void method::init()
    {
        // This function is also hooked by Plutonium, so we need to get the plutonium hook to call
        player_get_method_t = reinterpret_cast<decltype(player_get_method_t)>(hook::get_relative(SELECT(0x432480, 0x6F2DB0)));
        hook::jump(SELECT(0x432480, 0x6F2DB0), player_get_method);
    }
}
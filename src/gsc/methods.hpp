#pragma once

class method
{
public:
	static void add(const char* name, int min_args, int max_args, void(*f)(scr_entref_t));
	static BuiltinMethodDef* find(const std::string& name);

	static void example_one(scr_entref_t entref);
	static void example_two(scr_entref_t entref);
	static void example_three(scr_entref_t entref);

private:
	static std::unordered_map<std::string, BuiltinMethodDef> registered_methods;
};
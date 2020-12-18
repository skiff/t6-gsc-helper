#pragma once

class function
{
public:
	static void add(const char* name, int min_args, int max_args, void(*f)());
	static BuiltinFunctionDef* find(const std::string& name);

	static void example_one();
	static void example_two();
	static void example_three();

private:
	static std::unordered_map<std::string, BuiltinFunctionDef> registered_functions;
};
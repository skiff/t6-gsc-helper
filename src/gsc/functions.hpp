#pragma once

namespace gsc
{
	class function
	{
	public:
		static void add(const char* name, int min_args, int max_args, void(*f)());
		static BuiltinFunctionDef* find(const std::string& name);
		static void init();

	private:
		static std::unordered_map<std::string, BuiltinFunctionDef> registered_functions;
	};
}
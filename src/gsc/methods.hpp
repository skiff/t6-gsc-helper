#pragma once

namespace gsc
{
	class method
	{
	public:
		static void add(const char* name, int min_args, int max_args, void(*f)(scr_entref_t));
		static BuiltinMethodDef* find(const std::string& name);
		static void init();

	private:
		static std::unordered_map<std::string, BuiltinMethodDef> registered_methods;
	};
}
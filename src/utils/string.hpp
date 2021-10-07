#pragma once

#define ARR_SIZE(x) (sizeof(x) / sizeof(x[0]))

namespace utils::string
{
	const char* va(const char* fmt, ...);

	std::vector<std::string> split(std::string& s, char delim);

	std::string to_lower(std::string text);
	std::string to_upper(std::string text);
	std::wstring to_wide(std::string text);

	void replace(std::string& s, const std::string& pattern, const std::string& value);

	bool starts_with(std::string haystack, std::string needle);
	bool ends_with(std::string haystack, std::string needle);
	bool string_compare(const std::string& input, const std::string& text, bool exact);

	std::string dump_hex(const std::string& data, const std::string& separator);
	std::string parse_hex(const std::string& data, const std::string& separator);

	std::string get_clipboard_data();

	bool is_letter(char c);
}
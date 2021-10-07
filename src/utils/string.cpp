#include "../main.hpp"
#include "string.hpp"

#define VA_BUFFER_COUNT		16
#define VA_BUFFER_SIZE		65536

namespace utils::string
{
	const char* va(const char* fmt, ...)
	{
		static char g_vaBuffer[VA_BUFFER_COUNT][VA_BUFFER_SIZE];
		static int g_vaNextBufferIndex = 0;

		va_list ap;
		va_start(ap, fmt);

		char* dest = g_vaBuffer[g_vaNextBufferIndex];
		vsnprintf(g_vaBuffer[g_vaNextBufferIndex], VA_BUFFER_SIZE, fmt, ap);
		g_vaNextBufferIndex = (g_vaNextBufferIndex + 1) % VA_BUFFER_COUNT;

		va_end(ap);
		return dest;
	}

	std::vector<std::string> split(std::string& s, char delim)
	{
		std::stringstream ss(s);
		std::string item;
		std::vector<std::string> elems;

		while (std::getline(ss, item, delim))
		{
			elems.push_back(item);
		}

		return elems;
	}

	bool starts_with(std::string haystack, std::string needle)
	{
		return (haystack.size() >= needle.size() && !strncmp(needle.data(), haystack.data(), needle.size()));
	}

	bool ends_with(std::string haystack, std::string needle)
	{
		return (strstr(haystack.data(), needle.data()) == (haystack.data() + haystack.size() - needle.size()));
	}

	std::string to_lower(std::string text)
	{
		std::transform(text.begin(), text.end(), text.begin(), ::tolower);
		return text;
	}

	std::string to_upper(std::string text)
	{
		std::transform(text.begin(), text.end(), text.begin(), ::toupper);
		return text;
	}

	std::wstring to_wide(std::string text)
	{
		int size_needed = MultiByteToWideChar(CP_UTF8, 0, &text[0], (int)text.size(), NULL, 0);
		std::wstring wstrTo(size_needed, 0);
		MultiByteToWideChar(CP_UTF8, 0, &text[0], (int)text.size(), &wstrTo[0], size_needed);
		return wstrTo;
	}

	void replace(std::string& s, const std::string& pattern, const std::string& value)
	{
		size_t pos = 0;
		while ((pos = s.find(pattern, pos)) != std::string::npos)
		{
			s = s.replace(pos, pattern.length(), value);
			pos += value.length();
		}
	}

	bool string_compare(const std::string& input, const std::string& text, bool exact)
	{
		if (exact && text == input)
		{
			return true;
		}

		if (!exact && text.find(input) != std::string::npos)
		{
			return true;
		}

		return false;
	}

	std::string dump_hex(const std::string& data, const std::string& separator)
	{
		std::string result;

		for (unsigned int i = 0; i < data.size(); ++i)
		{
			if (i > 0)
			{
				result.append(separator);
			}

			result.append(va("%02X", data[i] & 0xFF));
		}

		return result;
	}

	std::string parse_hex(const std::string& data, const std::string& separator)
	{
		std::string result;

		for (std::size_t i = 0u; i < data.size(); i += (2 + separator.size()))
		{
			int c;
			sscanf_s(&data[i], "%2x", &c);

			result.append(1, c);
		}

		return result;
	}

	std::string get_clipboard_data()
	{
		if (OpenClipboard(0))
		{
			std::string data;

			const auto clipboard_data = GetClipboardData(1u);
			if (clipboard_data)
			{
				const auto cliptext = static_cast<char*>(GlobalLock(clipboard_data));
				if (cliptext)
				{
					data.append(cliptext);
					GlobalUnlock(clipboard_data);
				}
			}
			CloseClipboard();

			return data;
		}
		return {};
	}

	bool is_letter(char c)
	{
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			return true;
		}

		return false;
	}
}
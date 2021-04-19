#pragma once

#define CalculateRelativeJMPAddress(X, Y) (((std::uintptr_t)Y - (std::uintptr_t)X) - 5)

class hook
{
public:
	static void get(uint64_t address, LPVOID buffer, size_t size);
	static void set(std::uintptr_t address, std::vector<std::uint8_t>&& bytes);
	static void set(std::uintptr_t address, void* buffer, size_t size);

	static void nop(std::uintptr_t address, size_t size);
	static void call(std::uintptr_t address, void* destination);
	static void jump(std::uintptr_t address, void* destination);

	static std::uintptr_t get_relative(std::uintptr_t address);

	template<typename T> static void set(std::uintptr_t address, T data)
	{
		set(address, &data, sizeof(T));
	}
};
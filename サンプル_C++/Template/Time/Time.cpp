#include "Time.h"
#include <chrono>

Time::Time() : 
	begin(0), end(0), result(0)
{
}

Time::~Time()
{
}

void Time::Begin(void)
{
	begin = std::chrono::duration_cast<std::chrono::duration<std::uint64_t, std::nano>> (std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}

std::uint64_t Time::End(void)
{
	end    = std::chrono::duration_cast<std::chrono::duration<std::uint64_t, std::nano>> (std::chrono::high_resolution_clock::now().time_since_epoch()).count();
	result = end - begin;

	return result;
}

std::uint64_t Time::GetResult(void) const
{
	return result;
}

// by folkert van heusden <folkert@vanheusden.com>
// MIT license
#include <chrono>
#include <cstdint>


uint64_t get_ns()
{
	auto now = std::chrono::steady_clock::now();
	auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count();
	return static_cast<uint64_t>(nanos);
}

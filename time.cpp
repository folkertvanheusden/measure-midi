// by folkert van heusden <folkert@vanheusden.com>
// MIT license
#include <cerrno>
#include <chrono>
#include <cstring>
#include <cstdint>
#include <cstdio>
#include <ctime>


uint64_t get_ms()
{
	auto now = std::chrono::steady_clock::now();  // monotonic clock
	auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
	return static_cast<uint64_t>(millis);
}

uint64_t get_us()
{
	auto now = std::chrono::steady_clock::now();
	auto micros = std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()).count();
	return static_cast<uint64_t>(micros);
}

uint64_t get_ns()
{
	auto now = std::chrono::steady_clock::now();
	auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count();
	return static_cast<uint64_t>(nanos);
}

void my_us_sleep(const uint64_t duration)
{
	timespec ts_duration { (long int)(duration / 1000000), (long int)((duration % 1000000) * 1000) };

	// don't care about the remainder: it should only be shortened when signals come in
	if (clock_nanosleep(CLOCK_MONOTONIC, 0, &ts_duration, nullptr) == -1)
		printf("clock_nanosleep failed: %s\n", strerror(errno));
}

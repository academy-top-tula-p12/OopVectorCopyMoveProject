#pragma once
#include <chrono>

class Timer
{
	using clock = std::chrono::high_resolution_clock;
	using second = std::chrono::duration<double, std::ratio<1>>;

	std::chrono::time_point<clock> pStart{ clock::now() };

public:
	void Reset();
	double Elapsed() const;
};


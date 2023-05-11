#include "Timer.h"

void Timer::Reset()
{
	pStart = clock::now();
}

double Timer::Elapsed() const
{
	return std::chrono::duration_cast<second>(clock::now() - pStart).count();
}

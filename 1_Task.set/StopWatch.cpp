#include "StopWatch.h"

StopWatch::StopWatch()
{
    m_counter = 0;
}

void StopWatch::start ()
{
    m_start = std::chrono::steady_clock::now();
}

void StopWatch::stop ()
{
    m_stop = std::chrono::steady_clock::now();
}

int StopWatch::print()
{
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(m_stop - m_start);

	return m_counter+elapsed.count();
}

void StopWatch::pause ()
{
    m_stop = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(m_stop - m_start);
    m_counter += elapsed.count() ;
}

void StopWatch::resume ()
{
    m_start = std::chrono::steady_clock::now();
}


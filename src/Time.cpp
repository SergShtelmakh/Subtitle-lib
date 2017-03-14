#include "include/subtitle_lib/Time.h"

#include <utility>

namespace subtitle_lib
{
const int cMsecInSecond = 1000;
const int cSecondInMinute = 60;
const int cMinuteInHour = 60;

Time::Time(int hour, int minute, int second, int msec)
	: m_hour(hour)
	, m_minute(minute)
	, m_msec(msec)
	, m_second(second)
{
}

Time::Time(Time &&other)
	: m_hour(std::move(other.m_hour))
	, m_minute(std::move(other.m_minute))
	, m_msec(std::move(other.m_msec))
	, m_second(std::move(other.m_second))
{
}

Time::Time(const Time &other)
	: m_hour(other.m_hour)
	, m_minute(other.m_minute)
	, m_msec(other.m_msec)
	, m_second(other.m_second)
{
}

int Time::hour() const
{
	return m_hour;
}

void Time::setHour(int value)
{
	m_hour = value;
}

int Time::minute() const
{
	return m_minute;
}

void Time::setMinute(int value)
{
	m_minute = value;
}

int Time::msec() const
{
	return m_msec;
}

void Time::setMsec(int value)
{
	m_msec = value;
}

int Time::second() const
{
	return m_second;
}

void Time::setSecond(int value)
{
	m_second = value;
}

bool Time::operator==(const Time &other) const
{
	return  m_msec == other.m_msec &&
			m_second == other.m_second &&
			m_minute == other.m_minute &&
			m_hour == other.m_hour;
}

bool Time::operator<(const Time &other) const
{
	if (m_hour != other.m_hour) {
		return m_hour < other.m_hour;
	}

	if (m_minute != other.m_minute) {
		return m_minute < other.m_minute;
	}

	if (m_second != other.m_second) {
		return m_second < other.m_second;
	}

	return m_msec < other.m_msec;
}

bool Time::operator<=(const Time &other) const
{
	return (*this < other) || (*this == other);
}

bool Time::operator>(const Time &other) const
{
	return other < *this;
}

bool Time::operator>=(const Time &other) const
{
	return (*this > other) || (*this == other);
}

Time &Time::operator+=(const Time &other)
{
	m_hour += other.m_hour;
	m_minute += other.m_minute;
	m_second += other.m_second;
	m_msec += other.m_msec;
	normalize();
	return *this;
}

Time Time::operator+(const Time &other) const
{
	return Time(*this) += other;
}

void Time::normalize()
{
	m_second += m_msec / cMsecInSecond;
	m_minute += m_second / cSecondInMinute;
	m_hour += m_minute / cMinuteInHour;

	m_msec %= cMsecInSecond;
	m_second %= cSecondInMinute;
	m_minute %= cMinuteInHour;
}

std::ostream &operator<<(std::ostream &os, const subtitle_lib::Time &time)
{
	os << time.hour() << ':' << time.minute() << ':' << time.second() << ':' <<time.msec();
	return os;
}
}

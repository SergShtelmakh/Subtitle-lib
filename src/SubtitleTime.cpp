#include "SubtitleTime.h"

#include <utility>

namespace sub_util
{
const int cMsecInSecond = 1000;
const int cSecondInMinute = 60;
const int cMinuteInHour = 60;

SubtitleTime::SubtitleTime(int hour, int minute, int second, int msec)
	: m_hour(hour)
	, m_minute(minute)
	, m_msec(msec)
	, m_second(second)
{
}

SubtitleTime::SubtitleTime(SubtitleTime &&other)
	: m_hour(std::move(other.m_hour))
	, m_minute(std::move(other.m_minute))
	, m_msec(std::move(other.m_msec))
	, m_second(std::move(other.m_second))
{
}

SubtitleTime::SubtitleTime(const SubtitleTime &other)
	: m_hour(other.m_hour)
	, m_minute(other.m_minute)
	, m_msec(other.m_msec)
	, m_second(other.m_second)
{
}

int SubtitleTime::hour() const
{
	return m_hour;
}

void SubtitleTime::setHour(int value)
{
	m_hour = value;
}

int SubtitleTime::minute() const
{
	return m_minute;
}

void SubtitleTime::setMinute(int value)
{
	m_minute = value;
}

int SubtitleTime::msec() const
{
	return m_msec;
}

void SubtitleTime::setMsec(int value)
{
	m_msec = value;
}

int SubtitleTime::second() const
{
	return m_second;
}

void SubtitleTime::setSecond(int value)
{
	m_second = value;
}

bool SubtitleTime::operator==(const SubtitleTime &other) const
{
	return  m_msec == other.m_msec &&
			m_second == other.m_second &&
			m_minute == other.m_minute &&
			m_hour == other.m_hour;
}

bool SubtitleTime::operator<(const SubtitleTime &other) const
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

bool SubtitleTime::operator<=(const SubtitleTime &other) const
{
	return (*this < other) || (*this == other);
}

bool SubtitleTime::operator>(const SubtitleTime &other) const
{
	return other < *this;
}

bool SubtitleTime::operator>=(const SubtitleTime &other) const
{
	return (*this > other) || (*this == other);
}

SubtitleTime &SubtitleTime::operator+=(const SubtitleTime &other)
{
	m_hour += other.m_hour;
	m_minute += other.m_minute;
	m_second += other.m_second;
	m_msec += other.m_msec;
	normalize();
	return *this;
}

SubtitleTime SubtitleTime::operator+(const SubtitleTime &other) const
{
	return SubtitleTime(*this) += other;
}

void SubtitleTime::normalize()
{
	m_second += m_msec / cMsecInSecond;
	m_minute += m_second / cSecondInMinute;
	m_hour += m_minute / cMinuteInHour;

	m_msec %= cMsecInSecond;
	m_second %= cSecondInMinute;
	m_minute %= cMinuteInHour;
}

std::ostream &operator<<(std::ostream &os, const sub_util::SubtitleTime &time)
{
	os << time.hour() << ':' << time.minute() << ':' << time.second() << ':' <<time.msec();
	return os;
}
}

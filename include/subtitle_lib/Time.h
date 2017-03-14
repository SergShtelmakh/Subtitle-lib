#pragma once

#include <iostream>

namespace subtitle_lib
{

class Time
{
public:
	Time() = default;
	Time(int hour, int minute, int second, int msec = 0);
	Time(Time &&other);
	Time(const Time &other);

	int hour() const;
	void setHour(int value);

	int minute() const;
	void setMinute(int value);

	int msec() const;
	void setMsec(int value);

	int second() const;
	void setSecond(int value);

	bool operator==(const Time &other) const;
	bool operator<(const Time &other) const;
	bool operator<=(const Time &other) const;
	bool operator>(const Time &other) const;
	bool operator>=(const Time &other) const;
	Time &operator+=(const Time &other);
	Time operator+(const Time &other) const;
	Time &operator=(const Time &other) = default;

	friend std::ostream& operator<<(std::ostream &os, const Time &time);

private:
	void normalize();

	int m_hour = 0;
	int m_minute = 0;
	int m_msec = 0;
	int m_second = 0;
};

}

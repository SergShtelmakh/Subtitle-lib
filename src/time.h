#pragma once

namespace sub_util
{

class Time
{
public:
	Time() {}
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

private:
	int m_hour = 0;
	int m_minute = 0;
	int m_msec = 0;
	int m_second = 0;
};

}

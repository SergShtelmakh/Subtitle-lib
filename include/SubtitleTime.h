#pragma once

#include <iostream>

namespace sub_util
{

class SubtitleTime
{
public:
	SubtitleTime() = default;
	SubtitleTime(int hour, int minute, int second, int msec = 0);
	SubtitleTime(SubtitleTime &&other);
	SubtitleTime(const SubtitleTime &other);

	int hour() const;
	void setHour(int value);

	int minute() const;
	void setMinute(int value);

	int msec() const;
	void setMsec(int value);

	int second() const;
	void setSecond(int value);

	bool operator==(const SubtitleTime &other) const;
	bool operator<(const SubtitleTime &other) const;
	bool operator<=(const SubtitleTime &other) const;
	bool operator>(const SubtitleTime &other) const;
	bool operator>=(const SubtitleTime &other) const;
	SubtitleTime &operator+=(const SubtitleTime &other);
	SubtitleTime operator+(const SubtitleTime &other) const;
	SubtitleTime &operator=(const SubtitleTime &other) = default;

	friend std::ostream& operator<<(std::ostream& os, const SubtitleTime& time);

private:
	void normalize();

	int m_hour = 0;
	int m_minute = 0;
	int m_msec = 0;
	int m_second = 0;
};

}

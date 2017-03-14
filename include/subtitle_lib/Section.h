#pragma once

#include "Time.h"

#include <string>

namespace subtitle_lib
{

class Section
{
public:
	Section() = default;
	Section(Time &&start, Time &&end, std::string &&text);
	Section(const Time &start, const Time &end, const std::string &text) = delete;

	Time start() const;
	void setStart(const Time &start);

	Time end() const;
	void setEnd(const Time &end);

	std::string text() const;
	void setText(const std::string &text);

	bool isValid() const;

private:
	Time m_start;
	Time m_end;
	std::string m_text;
};

}

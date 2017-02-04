#pragma once

#include <string>
#include <list>

#include "Time.h"

namespace sub_util
{

class SubtitleSection
{
public:
	SubtitleSection(){}
	SubtitleSection(Time &&start, Time &&end, std::string &&text);
	SubtitleSection(const Time &start, const Time &end, const std::string &text) = delete;

	Time start() const;
	Time end() const;
	std::string text() const;

private:
	Time m_start;
	Time m_end;
	std::string m_text;
};

}

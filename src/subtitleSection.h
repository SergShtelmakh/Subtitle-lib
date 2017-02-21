#pragma once

#include "SubtitleTime.h"

#include <string>
#include <list>

namespace sub_util
{

class SubtitleSection
{
public:
	SubtitleSection() = default;
	SubtitleSection(SubtitleTime &&start, SubtitleTime &&end, std::string &&text);
	SubtitleSection(const SubtitleTime &start, const SubtitleTime &end, const std::string &text) = delete;

	SubtitleTime start() const;
	void setStart(const SubtitleTime &start);

	SubtitleTime end() const;
	void setEnd(const SubtitleTime &end);

	std::string text() const;
	void setText(const std::string &text);

	bool isValid() const;

private:
	SubtitleTime m_start;
	SubtitleTime m_end;
	std::string m_text;
};

}

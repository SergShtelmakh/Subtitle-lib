#include "SubtitleSection.h"

namespace sub_util
{

SubtitleSection::SubtitleSection(SubtitleTime &&start, SubtitleTime &&end, std::string &&text)
	: m_start(std::move(start))
	, m_end(std::move(end))
	, m_text(std::move(text))
{
}

SubtitleTime SubtitleSection::start() const
{
	return m_start;
}

void SubtitleSection::setStart(const SubtitleTime &start)
{
	m_start = start;
}

SubtitleTime SubtitleSection::end() const
{
	return m_end;
}

void SubtitleSection::setEnd(const SubtitleTime &end)
{
	m_end = end;
}

std::string SubtitleSection::text() const
{
	return m_text;
}

void SubtitleSection::setText(const std::string &text)
{
	m_text = text;
}

bool SubtitleSection::isValid() const
{
	return m_end > m_start && !m_text.empty();
}

}

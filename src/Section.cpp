#include "include/subtitle_lib/Section.h"

namespace subtitle_lib
{

Section::Section(Time &&start, Time &&end, std::string &&text)
	: m_start(std::move(start))
	, m_end(std::move(end))
	, m_text(std::move(text))
{
}

Time Section::start() const
{
	return m_start;
}

void Section::setStart(const Time &start)
{
	m_start = start;
}

Time Section::end() const
{
	return m_end;
}

void Section::setEnd(const Time &end)
{
	m_end = end;
}

std::string Section::text() const
{
	return m_text;
}

void Section::setText(const std::string &text)
{
	m_text = text;
}

bool Section::isValid() const
{
	return m_end > m_start && !m_text.empty();
}

}

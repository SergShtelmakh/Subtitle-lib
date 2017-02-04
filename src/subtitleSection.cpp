#include "SubtitleSection.h"

namespace sub_util
{

SubtitleSection::SubtitleSection(Time &&start, Time &&end, std::string &&text)
	: m_start(std::move(start))
	, m_end(std::move(end))
	, m_text(std::move(text))
{
}

Time SubtitleSection::start() const
{
	return m_start;
}

Time SubtitleSection::end() const
{
	return m_end;
}

std::string SubtitleSection::text() const
{
	return m_text;
}

}

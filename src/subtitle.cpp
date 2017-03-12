#include "Subtitle.h"

#include "ParseHelper.h"

namespace sub_util
{

Subtitle::Subtitle(const std::string &path)
{
	load(path);
}

void Subtitle::load(const std::string &path)
{
	m_data = parseSubtitles(path);
}

size_t Subtitle::size() const
{
	return m_data.size();
}

SubtitleSection Subtitle::operator[](int index) const
{
	return m_data[index];
}

}

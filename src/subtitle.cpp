#include "include/subtitle_lib/Subtitle.h"

#include "ParseHelper.h"

namespace subtitle_lib
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

const Section &Subtitle::operator[](int index) const
{
	return m_data[index];
}

}

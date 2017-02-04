#pragma once

#include <list>
#include <string>

namespace sub_util
{
class SubtitleSection;

class Subtitle
{
public:
	Subtitle(){}
	Subtitle(const std::string &path);

	void load(const std::string &path);

private:
	std::list<SubtitleSection> m_data;
};

}

#pragma once

#include "SubtitleSection.h"

#include <vector>
#include <string>

namespace sub_util
{

class Subtitle
{
public:
	Subtitle() = default;
	Subtitle(const std::string &path);

	void load(const std::string &path);

	size_t size() const;

	SubtitleSection operator[](int index) const;

private:
	std::vector<SubtitleSection> m_data;
};

}

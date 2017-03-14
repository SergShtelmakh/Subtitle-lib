#pragma once

#include "Section.h"

#include <vector>
#include <string>

namespace subtitle_lib
{

class Subtitle
{
public:
	Subtitle() = default;
	explicit Subtitle(const std::string &path);

	void load(const std::string &path);

	size_t size() const;

	const Section &operator[](int index) const;

private:
	std::vector<Section> m_data;
};

}

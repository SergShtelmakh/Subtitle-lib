#include "Subtitle.h"

#include "SubtitleSection.h"

#include <fstream>

namespace sub_util
{

Subtitle::Subtitle(const std::string &path)
{
	load(path);
}

void Subtitle::load(const std::string &path)
{
	// TODO
}

}

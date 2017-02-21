#pragma once

#include "SubtitleTime.h"
#include "SubtitleSection.h"

#include <vector>
#include <string>

namespace sub_util
{
std::vector<SubtitleTime> parseTimes(const std::string &text);
std::vector<SubtitleSection> parseSubtitles(const std::string &path);
}

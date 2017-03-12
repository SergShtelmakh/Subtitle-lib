#pragma once

#include <vector>
#include <string>

namespace sub_util
{
class SubtitleTime;
class SubtitleSection;

std::vector<SubtitleTime> parseTimes(const std::string &text);
std::vector<SubtitleSection> parseSubtitles(const std::string &path);
}

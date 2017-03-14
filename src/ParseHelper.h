#pragma once

#include <vector>
#include <string>

namespace subtitle_lib
{
class Time;
class Section;

std::vector<Time> parseTimes(const std::string &text);
std::vector<Section> parseSubtitles(const std::string &path);
}

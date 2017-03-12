#include "ParseHelper.h"

#include "SubtitleTime.h"
#include "SubtitleSection.h"

#include <regex>
#include <fstream>

namespace sub_util
{
enum class ParseState {
	ParseIndex,
	ParseTime,
	ParseText
};

const std::regex timeRegex("([0-9]{1,2}):([0-9]{1,2}):([0-9]{1,2}),([0-9]{1,3})");

std::vector<SubtitleTime> parseTimes(const std::string &text)
{
	std::vector<SubtitleTime> result;
	auto tail = text;
	std::smatch matches;
	while (std::regex_search(tail, matches, timeRegex)) {
		if (matches.size() >= 5) {
			result.emplace_back(SubtitleTime(std::stoi(matches.str(1)),
											 std::stoi(matches.str(2)),
											 std::stoi(matches.str(3)),
											 std::stoi(matches.str(4))));
		}
		tail = matches.suffix();
	}
	return std::move(result);
}

std::vector<SubtitleSection> parseSubtitles(const std::string &path)
{
	std::ifstream input (path, std::ifstream::in);
	if (!input.is_open()) {
		return {};
	}

	std::vector<SubtitleSection> result;

	SubtitleSection currentSection;
	std::string currentText;
	ParseState state = ParseState::ParseIndex;
	for (std::string line; getline(input, line); ) {
		switch (state) {
		case ParseState::ParseIndex:
			// TODO check
			state = ParseState::ParseTime;
			break;
		case ParseState::ParseTime: {
			auto times = parseTimes(line);
			if (times.size() == 2) {
				currentSection.setStart(times[0]);
				currentSection.setEnd(times[1]);
			}
			state = ParseState::ParseText;
			break;
		}
		case ParseState::ParseText: {
			if (!line.empty()) {
				currentText.append(line);
			} else {
				currentSection.setText(currentText);
				currentText.clear();
				if (currentSection.isValid()) {
					result.push_back(currentSection);
				} else {
					std::cerr << "invalid section" << std::endl;
				}
				state = ParseState::ParseIndex;
			}
			break;
		}
		default:
			break;
		}
	}
	return std::move(result);
}

}

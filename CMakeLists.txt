cmake_minimum_required(VERSION 3.1)

project(Subtitles)

set(PROJECT_VERSION "1.0")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
set(CXX_STANDARD 14)

# add lib

include_directories(include)

set(lib_source
    src/ParseHelper.cpp
    src/Subtitle.cpp
    src/SubtitleSection.cpp
    src/SubtitleTime.cpp
)

set(lib_headers
    include/ParseHelper.h
    include/Subtitle.h
    include/SubtitleSection.h
    include/SubtitleTime.h
)

add_library(subtitlesLib SHARED ${lib_source} ${lib_headers})

# test lib

enable_testing()

find_package (Qt5Test REQUIRED)

add_executable(SubtitleLibTests tests/SubtitleLibTests.cpp)
target_link_libraries(SubtitleLibTests Qt5::Test subtitlesLib)

add_test(NAME testSubtitleLib COMMAND SubtitleLibTests)

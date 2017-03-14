cmake_minimum_required(VERSION 3.1)

project(SubtitleLib)

set(PROJECT_VERSION "1.0")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
set(CXX_STANDARD 14)

# add lib

include_directories(include)

set(lib_source
    src/Subtitle.cpp
    src/Section.cpp
    src/Time.cpp
    src/ParseHelper.cpp
)

set(lib_headers
    include/subtitle_lib/Subtitle.h
    include/subtitle_lib/Section.h
    include/subtitle_lib/Time.h

    src/ParseHelper.h
)

add_library(SubtitleLib SHARED ${lib_source} ${lib_headers})

# test lib

find_package (Qt5Test REQUIRED)

enable_testing()

add_executable(SubtitleLibTests tests/SubtitleLibTests.cpp)
target_link_libraries(SubtitleLibTests Qt5::Test SubtitleLib)

add_test(NAME testSubtitleLib COMMAND SubtitleLibTests)

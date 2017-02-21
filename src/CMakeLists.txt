project(subtitlesLib)

set(lib_source
    ParseHelper.cpp
    Subtitle.cpp
    SubtitleSection.cpp
    SubtitleTime.cpp
)

set(lib_headers
    ParseHelper.h
    Subtitle.h
    SubtitleSection.h
    SubtitleTime.h
)

add_library(subtitlesLib STATIC ${lib_source} ${lib_headers})

set_target_properties(subtitlesLib PROPERTIES LINKER_LANGUAGE CXX)

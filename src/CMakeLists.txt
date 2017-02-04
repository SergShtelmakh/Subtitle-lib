project(subtitlesLib)

set(lib_source
    Subtitle.cpp
    SubtitleSection.cpp
    Time.cpp
)

set(lib_headers
    Subtitle.h
    SubtitleSection.h
    Time.h
)

add_library(subtitlesLib STATIC ${lib_source} ${lib_headers})

set_target_properties(subtitlesLib PROPERTIES LINKER_LANGUAGE CXX)

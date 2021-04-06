cmake_minimum_required(VERSION 3.10)

include(ExternalProject)

add_library(UniqueMorseCodeWords_Src STATIC
    MorseAlphabet.cpp
    MorseAlphabet.h
    Solution.cpp
    Solution.h
)

target_include_directories(UniqueMorseCodeWords_Src
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

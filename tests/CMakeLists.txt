cmake_minimum_required(VERSION 3.10)

find_package(PkgConfig REQUIRED)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(UniqueMorseCodeWords_Test
    main_test.cpp
)

target_link_libraries(UniqueMorseCodeWords_Test 
    ${GTEST_LIBRARIES} 
    ${GTEST_MAIN_LIBRARIES} 
    pthread
    UniqueMorseCodeWords_Src
)

add_test(UniqueMorseCodeWords UniqueMorseCodeWords_Test)

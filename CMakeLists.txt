cmake_minimum_required(VERSION 3.20)
project(OOP VERSION 0.1.0)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)

include_directories(
    include/
)

set(SRC
    src/HelloWorld.cpp

    include/HelloWorld.hpp
)

add_executable(OOP
    src/main.cpp
    ${SRC}
)

add_executable(ut_all
    test/ut_main.cpp

    ${SRC}
)
target_link_libraries(ut_all PRIVATE
    GTest::gtest
    GTest::gtest_main
)
add_test(UT ut_all)
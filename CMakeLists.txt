cmake_minimum_required(VERSION 3.16) # needs to be >=3.14
project(OOP VERSION 0.1.0)
enable_testing()

set(CMAKE_CXX_STANDARD 11)

#### GTest
# reference: https://google.github.io/googletest/quickstart-cmake.html
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(SRC
    src/HelloWorld.cpp

    include/HelloWorld.hpp
)

set(INCLUDE_DIRS
    include/
)

add_executable(OOP
    src/main.cpp
    ${SRC}
)
target_include_directories(OOP PRIVATE
    ${INCLUDE_DIRS}
)

add_executable(ut_all
    test/ut_main.cpp

    ${SRC}
)
target_link_libraries(ut_all
    GTest::gtest_main
)
target_include_directories(ut_all PRIVATE
    ${INCLUDE_DIRS}
)
include(GoogleTest)
gtest_discover_tests(ut_all)
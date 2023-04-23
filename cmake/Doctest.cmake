message(INFO " getting doctest v2.4.11")
add_definitions(-DENABLE_DOCTEST_IN_LIBRARY)
include(FetchContent)
FetchContent_Declare(
    DocTest
    GIT_REPOSITORY https://github.com/doctest/doctest.git
    GIT_TAG        v2.4.11
)

FetchContent_MakeAvailable(DocTest)
include_directories(${DOCTEST_INCLUDE_DIR})

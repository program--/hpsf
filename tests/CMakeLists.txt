project(tests)

set(TESTFILES test_tensor.cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
include(Doctest)
include_directories(${INCLUDE_DIR})

add_library(test_sources OBJECT ${TESTFILES})
target_link_libraries(test_sources hpsf)
target_link_libraries(test_sources doctest::doctest)

add_executable(tests main.cpp)
target_compile_features(tests PRIVATE cxx_std_14)
target_link_libraries(tests test_sources)
target_link_libraries(tests doctest::doctest)

include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
doctest_discover_tests(tests)

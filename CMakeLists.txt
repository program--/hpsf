cmake_minimum_required(VERSION 3.14..3.27)

project(hpsf VERSION 0.1.0
             LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
set(TEST_DIR ${CMAKE_CURRENT_LIST_DIR}/tests)
set(MODULE_DIR ${CMAKE_CURRENT_LIST_DIR}/cmake)

list(APPEND CMAKE_MODULE_PATH ${MODULE_DIR})

add_library(hpsf INTERFACE)
target_include_directories(hpsf INTERFACE ${INCLUDE_DIR})

option(ENABLE_TESTS "include tests" ON)
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME) AND ENABLE_TESTS)
    add_subdirectory(tests)
endif()

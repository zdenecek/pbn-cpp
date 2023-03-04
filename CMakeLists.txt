cmake_minimum_required(VERSION 3.23)
project(pbn)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES src/**/*.cpp include/**/*.cpp)
file(GLOB HEADERS include/**/*.h)

add_executable(pbn main.cpp ${SOURCES} ${HEADERS})

target_include_directories(pbn PUBLIC include)
target_include_directories(pbn PUBLIC include/pbn)
target_include_directories(pbn PUBLIC include/tokens)



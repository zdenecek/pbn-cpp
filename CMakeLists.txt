cmake_minimum_required(VERSION 3.23)
project(pbn)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES src/**/*.cpp include/**/*.cpp)
file(GLOB HEADERS include/**/*.h)

add_executable(pbn main.cpp ${SOURCES} ${HEADERS} include/program/application.cpp include/program/application.h include/tokens/TagFactory.cpp include/tokens/TagFactory.h include/utils/strings.cpp include/utils/strings.h include/tokens/TableTag.cpp include/tokens/TableTag.h)

target_include_directories(pbn PUBLIC include)
target_include_directories(pbn PUBLIC include/pbn)
target_include_directories(pbn PUBLIC include/tokens)
target_include_directories(pbn PUBLIC include/utils)



cmake_minimum_required(VERSION 3.23)
project(pbn)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES src/**/*.cpp include/**/*.cpp)
file(GLOB HEADERS include/**/*.h)

add_executable(pbn main.cpp ${SOURCES} ${HEADERS} include/program/application.cpp include/program/application.h include/tokens/TagFactory.cpp include/tokens/TagFactory.h include/utils/strings.cpp include/utils/strings.h include/tokens/TableTag.cpp include/tokens/TableTag.h)
include_directories(include include/pbn include/tokens include/utils include/program)

# Boost
# set(Boost_DEBUG 1)
find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(pbn ${Boost_LIBRARIES})



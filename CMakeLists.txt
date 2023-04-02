cmake_minimum_required(VERSION 3.23)
project(pbn)

set(CMAKE_CXX_STANDARD 20)
set(TARGET_NAME pbn)

file(GLOB SOURCES src/**/*.cpp include/**/*.cpp)
file(GLOB HEADERS include/**/*.h)

add_executable(${TARGET_NAME} main.cpp ${SOURCES} ${HEADERS})
include_directories(include include/pbn include/tokens include/utils include/program include/manipulators include/debug)

# Boost
# set(Boost_DEBUG 1)
# set(BOOST_ROOT "C:/boost")

find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(${TARGET_NAME} ${Boost_LIBRARIES})

if(MSVC)
  target_compile_options(${TARGET_NAME} PRIVATE /Wall)
else()
  target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -Wpedantic)
  target_compile_options(${TARGET_NAME} PRIVATE -g)
endif()


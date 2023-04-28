cmake_minimum_required(VERSION 3.23)
project(pbn)

set(CMAKE_CXX_STANDARD 23)

file(GLOB SOURCES src/**/*.cpp include/**/*.cpp include/**/**/*.cpp )
file(GLOB HEADERS include/**/*.h)
file(GLOB TESTS test/**/*.h)

include_directories(include include/pbn include/dds include/tokens include/tokens/tags include/utils include/program include/manipulators 
 include/debug)

# Boost

# Useful for debugging boost issues
# set(Boost_DEBUG 1)
# set(BOOST_ROOT "C:/boost")

# if(MSVC)
#   set(BOOST_ROOT "C:/boostVC")
# endif()

find_package(Boost COMPONENTS program_options unit_test_framework  REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
link_libraries(${Boost_LIBRARIES})

# END Boost

add_executable(pbn main.cpp ${SOURCES} ${HEADERS}  )
add_executable(test test/basic.cpp ${SOURCES} ${TESTS})

set_target_properties(test PROPERTIES OUTPUT_NAME pbn_test)

# dds library

unset(DDS_LIB CACHE)
find_library(DDS_LIB NAMES dds.lib PATHS ${CMAKE_CURRENT_SOURCE_DIR}/dds ${CMAKE_CURRENT_SOURCE_DIR} )
target_link_libraries(pbn PRIVATE ${DDS_LIB})
target_link_libraries(test PRIVATE ${DDS_LIB})

# End dds library

if(MSVC)
  add_compile_options(PRIVATE /Wall)
else()
  add_compile_options(PRIVATE -Wall -Wextra -Wpedantic -g)
endif()


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/zdnek/src/pbn

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/zdnek/src/pbn/build2

# Include any dependencies generated for this target.
include CMakeFiles/test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/test/basic.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/test/basic.cpp.o: ../test/basic.cpp
CMakeFiles/test.dir/test/basic.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/zdnek/src/pbn/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test.dir/test/basic.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/test/basic.cpp.o -MF CMakeFiles/test.dir/test/basic.cpp.o.d -o CMakeFiles/test.dir/test/basic.cpp.o -c /mnt/c/Users/zdnek/src/pbn/test/basic.cpp

CMakeFiles/test.dir/test/basic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/test/basic.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/zdnek/src/pbn/test/basic.cpp > CMakeFiles/test.dir/test/basic.cpp.i

CMakeFiles/test.dir/test/basic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/test/basic.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/zdnek/src/pbn/test/basic.cpp -o CMakeFiles/test.dir/test/basic.cpp.s

CMakeFiles/test.dir/src/manipulators/PbnInfoPrinter.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/manipulators/PbnInfoPrinter.cpp.o: ../src/manipulators/PbnInfoPrinter.cpp
CMakeFiles/test.dir/src/manipulators/PbnInfoPrinter.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/zdnek/src/pbn/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test.dir/src/manipulators/PbnInfoPrinter.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/manipulators/PbnInfoPrinter.cpp.o -MF CMakeFiles/test.dir/src/manipulators/PbnInfoPrinter.cpp.o.d -o CMakeFiles/test.dir/src/manipulators/PbnInfoPrinter.cpp.o -c /mnt/c/Users/zdnek/src/pbn/src/manipulators/PbnInfoPrinter.cpp

CMakeFiles/test.dir/src/manipulators/PbnInfoPrinter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/manipulators/PbnInfoPrinter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/zdnek/src/pbn/src/manipulators/PbnInfoPrinter.cpp > CMakeFiles/test.dir/src/manipulators/PbnInfoPrinter.cpp.i

CMakeFiles/test.dir/src/manipulators/PbnInfoPrinter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/manipulators/PbnInfoPrinter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/zdnek/src/pbn/src/manipulators/PbnInfoPrinter.cpp -o CMakeFiles/test.dir/src/manipulators/PbnInfoPrinter.cpp.s

CMakeFiles/test.dir/src/manipulators/PbnStripper.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/manipulators/PbnStripper.cpp.o: ../src/manipulators/PbnStripper.cpp
CMakeFiles/test.dir/src/manipulators/PbnStripper.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/zdnek/src/pbn/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test.dir/src/manipulators/PbnStripper.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/manipulators/PbnStripper.cpp.o -MF CMakeFiles/test.dir/src/manipulators/PbnStripper.cpp.o.d -o CMakeFiles/test.dir/src/manipulators/PbnStripper.cpp.o -c /mnt/c/Users/zdnek/src/pbn/src/manipulators/PbnStripper.cpp

CMakeFiles/test.dir/src/manipulators/PbnStripper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/manipulators/PbnStripper.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/zdnek/src/pbn/src/manipulators/PbnStripper.cpp > CMakeFiles/test.dir/src/manipulators/PbnStripper.cpp.i

CMakeFiles/test.dir/src/manipulators/PbnStripper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/manipulators/PbnStripper.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/zdnek/src/pbn/src/manipulators/PbnStripper.cpp -o CMakeFiles/test.dir/src/manipulators/PbnStripper.cpp.s

CMakeFiles/test.dir/src/pbn/BoardContext.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/pbn/BoardContext.cpp.o: ../src/pbn/BoardContext.cpp
CMakeFiles/test.dir/src/pbn/BoardContext.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/zdnek/src/pbn/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/test.dir/src/pbn/BoardContext.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/pbn/BoardContext.cpp.o -MF CMakeFiles/test.dir/src/pbn/BoardContext.cpp.o.d -o CMakeFiles/test.dir/src/pbn/BoardContext.cpp.o -c /mnt/c/Users/zdnek/src/pbn/src/pbn/BoardContext.cpp

CMakeFiles/test.dir/src/pbn/BoardContext.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/pbn/BoardContext.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/zdnek/src/pbn/src/pbn/BoardContext.cpp > CMakeFiles/test.dir/src/pbn/BoardContext.cpp.i

CMakeFiles/test.dir/src/pbn/BoardContext.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/pbn/BoardContext.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/zdnek/src/pbn/src/pbn/BoardContext.cpp -o CMakeFiles/test.dir/src/pbn/BoardContext.cpp.s

CMakeFiles/test.dir/src/pbn/PbnFile.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/pbn/PbnFile.cpp.o: ../src/pbn/PbnFile.cpp
CMakeFiles/test.dir/src/pbn/PbnFile.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/zdnek/src/pbn/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/test.dir/src/pbn/PbnFile.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/pbn/PbnFile.cpp.o -MF CMakeFiles/test.dir/src/pbn/PbnFile.cpp.o.d -o CMakeFiles/test.dir/src/pbn/PbnFile.cpp.o -c /mnt/c/Users/zdnek/src/pbn/src/pbn/PbnFile.cpp

CMakeFiles/test.dir/src/pbn/PbnFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/pbn/PbnFile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/zdnek/src/pbn/src/pbn/PbnFile.cpp > CMakeFiles/test.dir/src/pbn/PbnFile.cpp.i

CMakeFiles/test.dir/src/pbn/PbnFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/pbn/PbnFile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/zdnek/src/pbn/src/pbn/PbnFile.cpp -o CMakeFiles/test.dir/src/pbn/PbnFile.cpp.s

CMakeFiles/test.dir/src/pbn/PbnParser.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/pbn/PbnParser.cpp.o: ../src/pbn/PbnParser.cpp
CMakeFiles/test.dir/src/pbn/PbnParser.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/zdnek/src/pbn/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/test.dir/src/pbn/PbnParser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/pbn/PbnParser.cpp.o -MF CMakeFiles/test.dir/src/pbn/PbnParser.cpp.o.d -o CMakeFiles/test.dir/src/pbn/PbnParser.cpp.o -c /mnt/c/Users/zdnek/src/pbn/src/pbn/PbnParser.cpp

CMakeFiles/test.dir/src/pbn/PbnParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/pbn/PbnParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/zdnek/src/pbn/src/pbn/PbnParser.cpp > CMakeFiles/test.dir/src/pbn/PbnParser.cpp.i

CMakeFiles/test.dir/src/pbn/PbnParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/pbn/PbnParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/zdnek/src/pbn/src/pbn/PbnParser.cpp -o CMakeFiles/test.dir/src/pbn/PbnParser.cpp.s

CMakeFiles/test.dir/src/pbn/PbnSerializer.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/pbn/PbnSerializer.cpp.o: ../src/pbn/PbnSerializer.cpp
CMakeFiles/test.dir/src/pbn/PbnSerializer.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/zdnek/src/pbn/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/test.dir/src/pbn/PbnSerializer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/pbn/PbnSerializer.cpp.o -MF CMakeFiles/test.dir/src/pbn/PbnSerializer.cpp.o.d -o CMakeFiles/test.dir/src/pbn/PbnSerializer.cpp.o -c /mnt/c/Users/zdnek/src/pbn/src/pbn/PbnSerializer.cpp

CMakeFiles/test.dir/src/pbn/PbnSerializer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/pbn/PbnSerializer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/zdnek/src/pbn/src/pbn/PbnSerializer.cpp > CMakeFiles/test.dir/src/pbn/PbnSerializer.cpp.i

CMakeFiles/test.dir/src/pbn/PbnSerializer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/pbn/PbnSerializer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/zdnek/src/pbn/src/pbn/PbnSerializer.cpp -o CMakeFiles/test.dir/src/pbn/PbnSerializer.cpp.s

CMakeFiles/test.dir/src/program/PbnApplication.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/program/PbnApplication.cpp.o: ../src/program/PbnApplication.cpp
CMakeFiles/test.dir/src/program/PbnApplication.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/zdnek/src/pbn/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/test.dir/src/program/PbnApplication.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/program/PbnApplication.cpp.o -MF CMakeFiles/test.dir/src/program/PbnApplication.cpp.o.d -o CMakeFiles/test.dir/src/program/PbnApplication.cpp.o -c /mnt/c/Users/zdnek/src/pbn/src/program/PbnApplication.cpp

CMakeFiles/test.dir/src/program/PbnApplication.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/program/PbnApplication.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/zdnek/src/pbn/src/program/PbnApplication.cpp > CMakeFiles/test.dir/src/program/PbnApplication.cpp.i

CMakeFiles/test.dir/src/program/PbnApplication.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/program/PbnApplication.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/zdnek/src/pbn/src/program/PbnApplication.cpp -o CMakeFiles/test.dir/src/program/PbnApplication.cpp.s

CMakeFiles/test.dir/src/tokens/Commentary.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/tokens/Commentary.cpp.o: ../src/tokens/Commentary.cpp
CMakeFiles/test.dir/src/tokens/Commentary.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/zdnek/src/pbn/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/test.dir/src/tokens/Commentary.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/tokens/Commentary.cpp.o -MF CMakeFiles/test.dir/src/tokens/Commentary.cpp.o.d -o CMakeFiles/test.dir/src/tokens/Commentary.cpp.o -c /mnt/c/Users/zdnek/src/pbn/src/tokens/Commentary.cpp

CMakeFiles/test.dir/src/tokens/Commentary.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/tokens/Commentary.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/zdnek/src/pbn/src/tokens/Commentary.cpp > CMakeFiles/test.dir/src/tokens/Commentary.cpp.i

CMakeFiles/test.dir/src/tokens/Commentary.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/tokens/Commentary.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/zdnek/src/pbn/src/tokens/Commentary.cpp -o CMakeFiles/test.dir/src/tokens/Commentary.cpp.s

CMakeFiles/test.dir/src/tokens/CustomEscapedLine.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/tokens/CustomEscapedLine.cpp.o: ../src/tokens/CustomEscapedLine.cpp
CMakeFiles/test.dir/src/tokens/CustomEscapedLine.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/zdnek/src/pbn/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/test.dir/src/tokens/CustomEscapedLine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/tokens/CustomEscapedLine.cpp.o -MF CMakeFiles/test.dir/src/tokens/CustomEscapedLine.cpp.o.d -o CMakeFiles/test.dir/src/tokens/CustomEscapedLine.cpp.o -c /mnt/c/Users/zdnek/src/pbn/src/tokens/CustomEscapedLine.cpp

CMakeFiles/test.dir/src/tokens/CustomEscapedLine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/tokens/CustomEscapedLine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/zdnek/src/pbn/src/tokens/CustomEscapedLine.cpp > CMakeFiles/test.dir/src/tokens/CustomEscapedLine.cpp.i

CMakeFiles/test.dir/src/tokens/CustomEscapedLine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/tokens/CustomEscapedLine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/zdnek/src/pbn/src/tokens/CustomEscapedLine.cpp -o CMakeFiles/test.dir/src/tokens/CustomEscapedLine.cpp.s

CMakeFiles/test.dir/src/tokens/EmptyLine.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/tokens/EmptyLine.cpp.o: ../src/tokens/EmptyLine.cpp
CMakeFiles/test.dir/src/tokens/EmptyLine.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/zdnek/src/pbn/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/test.dir/src/tokens/EmptyLine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/tokens/EmptyLine.cpp.o -MF CMakeFiles/test.dir/src/tokens/EmptyLine.cpp.o.d -o CMakeFiles/test.dir/src/tokens/EmptyLine.cpp.o -c /mnt/c/Users/zdnek/src/pbn/src/tokens/EmptyLine.cpp

CMakeFiles/test.dir/src/tokens/EmptyLine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/tokens/EmptyLine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/zdnek/src/pbn/src/tokens/EmptyLine.cpp > CMakeFiles/test.dir/src/tokens/EmptyLine.cpp.i

CMakeFiles/test.dir/src/tokens/EmptyLine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/tokens/EmptyLine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/zdnek/src/pbn/src/tokens/EmptyLine.cpp -o CMakeFiles/test.dir/src/tokens/EmptyLine.cpp.s

CMakeFiles/test.dir/src/tokens/EscapedLine.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/tokens/EscapedLine.cpp.o: ../src/tokens/EscapedLine.cpp
CMakeFiles/test.dir/src/tokens/EscapedLine.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/zdnek/src/pbn/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/test.dir/src/tokens/EscapedLine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/tokens/EscapedLine.cpp.o -MF CMakeFiles/test.dir/src/tokens/EscapedLine.cpp.o.d -o CMakeFiles/test.dir/src/tokens/EscapedLine.cpp.o -c /mnt/c/Users/zdnek/src/pbn/src/tokens/EscapedLine.cpp

CMakeFiles/test.dir/src/tokens/EscapedLine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/tokens/EscapedLine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/zdnek/src/pbn/src/tokens/EscapedLine.cpp > CMakeFiles/test.dir/src/tokens/EscapedLine.cpp.i

CMakeFiles/test.dir/src/tokens/EscapedLine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/tokens/EscapedLine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/zdnek/src/pbn/src/tokens/EscapedLine.cpp -o CMakeFiles/test.dir/src/tokens/EscapedLine.cpp.s

CMakeFiles/test.dir/src/tokens/SemanticPbnToken.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/tokens/SemanticPbnToken.cpp.o: ../src/tokens/SemanticPbnToken.cpp
CMakeFiles/test.dir/src/tokens/SemanticPbnToken.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/zdnek/src/pbn/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/test.dir/src/tokens/SemanticPbnToken.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/tokens/SemanticPbnToken.cpp.o -MF CMakeFiles/test.dir/src/tokens/SemanticPbnToken.cpp.o.d -o CMakeFiles/test.dir/src/tokens/SemanticPbnToken.cpp.o -c /mnt/c/Users/zdnek/src/pbn/src/tokens/SemanticPbnToken.cpp

CMakeFiles/test.dir/src/tokens/SemanticPbnToken.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/tokens/SemanticPbnToken.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/zdnek/src/pbn/src/tokens/SemanticPbnToken.cpp > CMakeFiles/test.dir/src/tokens/SemanticPbnToken.cpp.i

CMakeFiles/test.dir/src/tokens/SemanticPbnToken.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/tokens/SemanticPbnToken.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/zdnek/src/pbn/src/tokens/SemanticPbnToken.cpp -o CMakeFiles/test.dir/src/tokens/SemanticPbnToken.cpp.s

CMakeFiles/test.dir/src/tokens/TableTag.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/tokens/TableTag.cpp.o: ../src/tokens/TableTag.cpp
CMakeFiles/test.dir/src/tokens/TableTag.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/zdnek/src/pbn/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/test.dir/src/tokens/TableTag.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/tokens/TableTag.cpp.o -MF CMakeFiles/test.dir/src/tokens/TableTag.cpp.o.d -o CMakeFiles/test.dir/src/tokens/TableTag.cpp.o -c /mnt/c/Users/zdnek/src/pbn/src/tokens/TableTag.cpp

CMakeFiles/test.dir/src/tokens/TableTag.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/tokens/TableTag.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/zdnek/src/pbn/src/tokens/TableTag.cpp > CMakeFiles/test.dir/src/tokens/TableTag.cpp.i

CMakeFiles/test.dir/src/tokens/TableTag.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/tokens/TableTag.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/zdnek/src/pbn/src/tokens/TableTag.cpp -o CMakeFiles/test.dir/src/tokens/TableTag.cpp.s

CMakeFiles/test.dir/src/tokens/Tag.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/tokens/Tag.cpp.o: ../src/tokens/Tag.cpp
CMakeFiles/test.dir/src/tokens/Tag.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/zdnek/src/pbn/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/test.dir/src/tokens/Tag.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/tokens/Tag.cpp.o -MF CMakeFiles/test.dir/src/tokens/Tag.cpp.o.d -o CMakeFiles/test.dir/src/tokens/Tag.cpp.o -c /mnt/c/Users/zdnek/src/pbn/src/tokens/Tag.cpp

CMakeFiles/test.dir/src/tokens/Tag.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/tokens/Tag.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/zdnek/src/pbn/src/tokens/Tag.cpp > CMakeFiles/test.dir/src/tokens/Tag.cpp.i

CMakeFiles/test.dir/src/tokens/Tag.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/tokens/Tag.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/zdnek/src/pbn/src/tokens/Tag.cpp -o CMakeFiles/test.dir/src/tokens/Tag.cpp.s

CMakeFiles/test.dir/src/tokens/TagFactory.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/tokens/TagFactory.cpp.o: ../src/tokens/TagFactory.cpp
CMakeFiles/test.dir/src/tokens/TagFactory.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/zdnek/src/pbn/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/test.dir/src/tokens/TagFactory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/tokens/TagFactory.cpp.o -MF CMakeFiles/test.dir/src/tokens/TagFactory.cpp.o.d -o CMakeFiles/test.dir/src/tokens/TagFactory.cpp.o -c /mnt/c/Users/zdnek/src/pbn/src/tokens/TagFactory.cpp

CMakeFiles/test.dir/src/tokens/TagFactory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/tokens/TagFactory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/zdnek/src/pbn/src/tokens/TagFactory.cpp > CMakeFiles/test.dir/src/tokens/TagFactory.cpp.i

CMakeFiles/test.dir/src/tokens/TagFactory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/tokens/TagFactory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/zdnek/src/pbn/src/tokens/TagFactory.cpp -o CMakeFiles/test.dir/src/tokens/TagFactory.cpp.s

CMakeFiles/test.dir/src/tokens/TextLine.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/tokens/TextLine.cpp.o: ../src/tokens/TextLine.cpp
CMakeFiles/test.dir/src/tokens/TextLine.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/zdnek/src/pbn/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/test.dir/src/tokens/TextLine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/tokens/TextLine.cpp.o -MF CMakeFiles/test.dir/src/tokens/TextLine.cpp.o.d -o CMakeFiles/test.dir/src/tokens/TextLine.cpp.o -c /mnt/c/Users/zdnek/src/pbn/src/tokens/TextLine.cpp

CMakeFiles/test.dir/src/tokens/TextLine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/tokens/TextLine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/zdnek/src/pbn/src/tokens/TextLine.cpp > CMakeFiles/test.dir/src/tokens/TextLine.cpp.i

CMakeFiles/test.dir/src/tokens/TextLine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/tokens/TextLine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/zdnek/src/pbn/src/tokens/TextLine.cpp -o CMakeFiles/test.dir/src/tokens/TextLine.cpp.s

CMakeFiles/test.dir/src/tokens/tags/BoardTag.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/tokens/tags/BoardTag.cpp.o: ../src/tokens/tags/BoardTag.cpp
CMakeFiles/test.dir/src/tokens/tags/BoardTag.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/zdnek/src/pbn/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/test.dir/src/tokens/tags/BoardTag.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/tokens/tags/BoardTag.cpp.o -MF CMakeFiles/test.dir/src/tokens/tags/BoardTag.cpp.o.d -o CMakeFiles/test.dir/src/tokens/tags/BoardTag.cpp.o -c /mnt/c/Users/zdnek/src/pbn/src/tokens/tags/BoardTag.cpp

CMakeFiles/test.dir/src/tokens/tags/BoardTag.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/tokens/tags/BoardTag.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/zdnek/src/pbn/src/tokens/tags/BoardTag.cpp > CMakeFiles/test.dir/src/tokens/tags/BoardTag.cpp.i

CMakeFiles/test.dir/src/tokens/tags/BoardTag.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/tokens/tags/BoardTag.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/zdnek/src/pbn/src/tokens/tags/BoardTag.cpp -o CMakeFiles/test.dir/src/tokens/tags/BoardTag.cpp.s

CMakeFiles/test.dir/src/utils/strings.cpp.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/utils/strings.cpp.o: ../src/utils/strings.cpp
CMakeFiles/test.dir/src/utils/strings.cpp.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/zdnek/src/pbn/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/test.dir/src/utils/strings.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test.dir/src/utils/strings.cpp.o -MF CMakeFiles/test.dir/src/utils/strings.cpp.o.d -o CMakeFiles/test.dir/src/utils/strings.cpp.o -c /mnt/c/Users/zdnek/src/pbn/src/utils/strings.cpp

CMakeFiles/test.dir/src/utils/strings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/src/utils/strings.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/zdnek/src/pbn/src/utils/strings.cpp > CMakeFiles/test.dir/src/utils/strings.cpp.i

CMakeFiles/test.dir/src/utils/strings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/src/utils/strings.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/zdnek/src/pbn/src/utils/strings.cpp -o CMakeFiles/test.dir/src/utils/strings.cpp.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/test/basic.cpp.o" \
"CMakeFiles/test.dir/src/manipulators/PbnInfoPrinter.cpp.o" \
"CMakeFiles/test.dir/src/manipulators/PbnStripper.cpp.o" \
"CMakeFiles/test.dir/src/pbn/BoardContext.cpp.o" \
"CMakeFiles/test.dir/src/pbn/PbnFile.cpp.o" \
"CMakeFiles/test.dir/src/pbn/PbnParser.cpp.o" \
"CMakeFiles/test.dir/src/pbn/PbnSerializer.cpp.o" \
"CMakeFiles/test.dir/src/program/PbnApplication.cpp.o" \
"CMakeFiles/test.dir/src/tokens/Commentary.cpp.o" \
"CMakeFiles/test.dir/src/tokens/CustomEscapedLine.cpp.o" \
"CMakeFiles/test.dir/src/tokens/EmptyLine.cpp.o" \
"CMakeFiles/test.dir/src/tokens/EscapedLine.cpp.o" \
"CMakeFiles/test.dir/src/tokens/SemanticPbnToken.cpp.o" \
"CMakeFiles/test.dir/src/tokens/TableTag.cpp.o" \
"CMakeFiles/test.dir/src/tokens/Tag.cpp.o" \
"CMakeFiles/test.dir/src/tokens/TagFactory.cpp.o" \
"CMakeFiles/test.dir/src/tokens/TextLine.cpp.o" \
"CMakeFiles/test.dir/src/tokens/tags/BoardTag.cpp.o" \
"CMakeFiles/test.dir/src/utils/strings.cpp.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

pbn_test: CMakeFiles/test.dir/test/basic.cpp.o
pbn_test: CMakeFiles/test.dir/src/manipulators/PbnInfoPrinter.cpp.o
pbn_test: CMakeFiles/test.dir/src/manipulators/PbnStripper.cpp.o
pbn_test: CMakeFiles/test.dir/src/pbn/BoardContext.cpp.o
pbn_test: CMakeFiles/test.dir/src/pbn/PbnFile.cpp.o
pbn_test: CMakeFiles/test.dir/src/pbn/PbnParser.cpp.o
pbn_test: CMakeFiles/test.dir/src/pbn/PbnSerializer.cpp.o
pbn_test: CMakeFiles/test.dir/src/program/PbnApplication.cpp.o
pbn_test: CMakeFiles/test.dir/src/tokens/Commentary.cpp.o
pbn_test: CMakeFiles/test.dir/src/tokens/CustomEscapedLine.cpp.o
pbn_test: CMakeFiles/test.dir/src/tokens/EmptyLine.cpp.o
pbn_test: CMakeFiles/test.dir/src/tokens/EscapedLine.cpp.o
pbn_test: CMakeFiles/test.dir/src/tokens/SemanticPbnToken.cpp.o
pbn_test: CMakeFiles/test.dir/src/tokens/TableTag.cpp.o
pbn_test: CMakeFiles/test.dir/src/tokens/Tag.cpp.o
pbn_test: CMakeFiles/test.dir/src/tokens/TagFactory.cpp.o
pbn_test: CMakeFiles/test.dir/src/tokens/TextLine.cpp.o
pbn_test: CMakeFiles/test.dir/src/tokens/tags/BoardTag.cpp.o
pbn_test: CMakeFiles/test.dir/src/utils/strings.cpp.o
pbn_test: CMakeFiles/test.dir/build.make
pbn_test: /usr/lib/x86_64-linux-gnu/libboost_program_options.so.1.74.0
pbn_test: /usr/lib/x86_64-linux-gnu/libboost_unit_test_framework.so.1.74.0
pbn_test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/zdnek/src/pbn/build2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Linking CXX executable pbn_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: pbn_test
.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /mnt/c/Users/zdnek/src/pbn/build2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/zdnek/src/pbn /mnt/c/Users/zdnek/src/pbn /mnt/c/Users/zdnek/src/pbn/build2 /mnt/c/Users/zdnek/src/pbn/build2 /mnt/c/Users/zdnek/src/pbn/build2/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend


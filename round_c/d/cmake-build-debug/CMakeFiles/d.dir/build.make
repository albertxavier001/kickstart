# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/albertxavier/workspace/kickstart/round_c/d

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/albertxavier/workspace/kickstart/round_c/d/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/d.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/d.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/d.dir/flags.make

CMakeFiles/d.dir/main.cpp.o: CMakeFiles/d.dir/flags.make
CMakeFiles/d.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/albertxavier/workspace/kickstart/round_c/d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/d.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/d.dir/main.cpp.o -c /Users/albertxavier/workspace/kickstart/round_c/d/main.cpp

CMakeFiles/d.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/d.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/albertxavier/workspace/kickstart/round_c/d/main.cpp > CMakeFiles/d.dir/main.cpp.i

CMakeFiles/d.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/d.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/albertxavier/workspace/kickstart/round_c/d/main.cpp -o CMakeFiles/d.dir/main.cpp.s

CMakeFiles/d.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/d.dir/main.cpp.o.requires

CMakeFiles/d.dir/main.cpp.o.provides: CMakeFiles/d.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/d.dir/build.make CMakeFiles/d.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/d.dir/main.cpp.o.provides

CMakeFiles/d.dir/main.cpp.o.provides.build: CMakeFiles/d.dir/main.cpp.o


# Object files for target d
d_OBJECTS = \
"CMakeFiles/d.dir/main.cpp.o"

# External object files for target d
d_EXTERNAL_OBJECTS =

d : CMakeFiles/d.dir/main.cpp.o
d : CMakeFiles/d.dir/build.make
d : CMakeFiles/d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/albertxavier/workspace/kickstart/round_c/d/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable d"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/d.dir/build: d

.PHONY : CMakeFiles/d.dir/build

CMakeFiles/d.dir/requires: CMakeFiles/d.dir/main.cpp.o.requires

.PHONY : CMakeFiles/d.dir/requires

CMakeFiles/d.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/d.dir/cmake_clean.cmake
.PHONY : CMakeFiles/d.dir/clean

CMakeFiles/d.dir/depend:
	cd /Users/albertxavier/workspace/kickstart/round_c/d/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/albertxavier/workspace/kickstart/round_c/d /Users/albertxavier/workspace/kickstart/round_c/d /Users/albertxavier/workspace/kickstart/round_c/d/cmake-build-debug /Users/albertxavier/workspace/kickstart/round_c/d/cmake-build-debug /Users/albertxavier/workspace/kickstart/round_c/d/cmake-build-debug/CMakeFiles/d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/d.dir/depend


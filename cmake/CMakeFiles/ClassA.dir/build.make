# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/cppTest/cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/cppTest/cmake

# Include any dependencies generated for this target.
include CMakeFiles/ClassA.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ClassA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ClassA.dir/flags.make

CMakeFiles/ClassA.dir/src/ClassA.cpp.o: CMakeFiles/ClassA.dir/flags.make
CMakeFiles/ClassA.dir/src/ClassA.cpp.o: src/ClassA.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/cppTest/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ClassA.dir/src/ClassA.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ClassA.dir/src/ClassA.cpp.o -c /root/cppTest/cmake/src/ClassA.cpp

CMakeFiles/ClassA.dir/src/ClassA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ClassA.dir/src/ClassA.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/cppTest/cmake/src/ClassA.cpp > CMakeFiles/ClassA.dir/src/ClassA.cpp.i

CMakeFiles/ClassA.dir/src/ClassA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ClassA.dir/src/ClassA.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/cppTest/cmake/src/ClassA.cpp -o CMakeFiles/ClassA.dir/src/ClassA.cpp.s

CMakeFiles/ClassA.dir/src/ClassA.cpp.o.requires:

.PHONY : CMakeFiles/ClassA.dir/src/ClassA.cpp.o.requires

CMakeFiles/ClassA.dir/src/ClassA.cpp.o.provides: CMakeFiles/ClassA.dir/src/ClassA.cpp.o.requires
	$(MAKE) -f CMakeFiles/ClassA.dir/build.make CMakeFiles/ClassA.dir/src/ClassA.cpp.o.provides.build
.PHONY : CMakeFiles/ClassA.dir/src/ClassA.cpp.o.provides

CMakeFiles/ClassA.dir/src/ClassA.cpp.o.provides.build: CMakeFiles/ClassA.dir/src/ClassA.cpp.o


# Object files for target ClassA
ClassA_OBJECTS = \
"CMakeFiles/ClassA.dir/src/ClassA.cpp.o"

# External object files for target ClassA
ClassA_EXTERNAL_OBJECTS =

libClassA.a: CMakeFiles/ClassA.dir/src/ClassA.cpp.o
libClassA.a: CMakeFiles/ClassA.dir/build.make
libClassA.a: CMakeFiles/ClassA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/cppTest/cmake/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libClassA.a"
	$(CMAKE_COMMAND) -P CMakeFiles/ClassA.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ClassA.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ClassA.dir/build: libClassA.a

.PHONY : CMakeFiles/ClassA.dir/build

CMakeFiles/ClassA.dir/requires: CMakeFiles/ClassA.dir/src/ClassA.cpp.o.requires

.PHONY : CMakeFiles/ClassA.dir/requires

CMakeFiles/ClassA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ClassA.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ClassA.dir/clean

CMakeFiles/ClassA.dir/depend:
	cd /root/cppTest/cmake && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/cppTest/cmake /root/cppTest/cmake /root/cppTest/cmake /root/cppTest/cmake /root/cppTest/cmake/CMakeFiles/ClassA.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ClassA.dir/depend


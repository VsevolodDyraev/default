# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /usr/coding/cpp/cikl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /usr/coding/cpp/cikl/build

# Include any dependencies generated for this target.
include src/CMakeFiles/list.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/list.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/list.dir/flags.make

src/CMakeFiles/list.dir/list.cpp.o: src/CMakeFiles/list.dir/flags.make
src/CMakeFiles/list.dir/list.cpp.o: ../src/list.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/usr/coding/cpp/cikl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/list.dir/list.cpp.o"
	cd /usr/coding/cpp/cikl/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/list.dir/list.cpp.o -c /usr/coding/cpp/cikl/src/list.cpp

src/CMakeFiles/list.dir/list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/list.dir/list.cpp.i"
	cd /usr/coding/cpp/cikl/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/coding/cpp/cikl/src/list.cpp > CMakeFiles/list.dir/list.cpp.i

src/CMakeFiles/list.dir/list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/list.dir/list.cpp.s"
	cd /usr/coding/cpp/cikl/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/coding/cpp/cikl/src/list.cpp -o CMakeFiles/list.dir/list.cpp.s

# Object files for target list
list_OBJECTS = \
"CMakeFiles/list.dir/list.cpp.o"

# External object files for target list
list_EXTERNAL_OBJECTS =

src/liblist.a: src/CMakeFiles/list.dir/list.cpp.o
src/liblist.a: src/CMakeFiles/list.dir/build.make
src/liblist.a: src/CMakeFiles/list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/usr/coding/cpp/cikl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblist.a"
	cd /usr/coding/cpp/cikl/build/src && $(CMAKE_COMMAND) -P CMakeFiles/list.dir/cmake_clean_target.cmake
	cd /usr/coding/cpp/cikl/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/list.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/list.dir/build: src/liblist.a

.PHONY : src/CMakeFiles/list.dir/build

src/CMakeFiles/list.dir/clean:
	cd /usr/coding/cpp/cikl/build/src && $(CMAKE_COMMAND) -P CMakeFiles/list.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/list.dir/clean

src/CMakeFiles/list.dir/depend:
	cd /usr/coding/cpp/cikl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /usr/coding/cpp/cikl /usr/coding/cpp/cikl/src /usr/coding/cpp/cikl/build /usr/coding/cpp/cikl/build/src /usr/coding/cpp/cikl/build/src/CMakeFiles/list.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/list.dir/depend


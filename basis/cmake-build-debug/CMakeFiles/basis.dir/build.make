# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /Volumes/CLion/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Volumes/CLion/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/coast/Desktop/C++/basis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/coast/Desktop/C++/basis/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/basis.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/basis.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/basis.dir/flags.make

CMakeFiles/basis.dir/main.cpp.o: CMakeFiles/basis.dir/flags.make
CMakeFiles/basis.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/coast/Desktop/C++/basis/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/basis.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/basis.dir/main.cpp.o -c /Users/coast/Desktop/C++/basis/main.cpp

CMakeFiles/basis.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basis.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/coast/Desktop/C++/basis/main.cpp > CMakeFiles/basis.dir/main.cpp.i

CMakeFiles/basis.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basis.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/coast/Desktop/C++/basis/main.cpp -o CMakeFiles/basis.dir/main.cpp.s

CMakeFiles/basis.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/basis.dir/main.cpp.o.requires

CMakeFiles/basis.dir/main.cpp.o.provides: CMakeFiles/basis.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/basis.dir/build.make CMakeFiles/basis.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/basis.dir/main.cpp.o.provides

CMakeFiles/basis.dir/main.cpp.o.provides.build: CMakeFiles/basis.dir/main.cpp.o


# Object files for target basis
basis_OBJECTS = \
"CMakeFiles/basis.dir/main.cpp.o"

# External object files for target basis
basis_EXTERNAL_OBJECTS =

basis: CMakeFiles/basis.dir/main.cpp.o
basis: CMakeFiles/basis.dir/build.make
basis: CMakeFiles/basis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/coast/Desktop/C++/basis/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable basis"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/basis.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/basis.dir/build: basis

.PHONY : CMakeFiles/basis.dir/build

CMakeFiles/basis.dir/requires: CMakeFiles/basis.dir/main.cpp.o.requires

.PHONY : CMakeFiles/basis.dir/requires

CMakeFiles/basis.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/basis.dir/cmake_clean.cmake
.PHONY : CMakeFiles/basis.dir/clean

CMakeFiles/basis.dir/depend:
	cd /Users/coast/Desktop/C++/basis/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/coast/Desktop/C++/basis /Users/coast/Desktop/C++/basis /Users/coast/Desktop/C++/basis/cmake-build-debug /Users/coast/Desktop/C++/basis/cmake-build-debug /Users/coast/Desktop/C++/basis/cmake-build-debug/CMakeFiles/basis.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/basis.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/coastcao/Desktop/cpp_primer_plus/cmake/0_tutorial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/coastcao/Desktop/cpp_primer_plus/cmake/0_tutorial/build

# Include any dependencies generated for this target.
include CMakeFiles/tutorial.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tutorial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tutorial.dir/flags.make

CMakeFiles/tutorial.dir/tutorial.cpp.o: CMakeFiles/tutorial.dir/flags.make
CMakeFiles/tutorial.dir/tutorial.cpp.o: ../tutorial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/coastcao/Desktop/cpp_primer_plus/cmake/0_tutorial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tutorial.dir/tutorial.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tutorial.dir/tutorial.cpp.o -c /Users/coastcao/Desktop/cpp_primer_plus/cmake/0_tutorial/tutorial.cpp

CMakeFiles/tutorial.dir/tutorial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tutorial.dir/tutorial.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/coastcao/Desktop/cpp_primer_plus/cmake/0_tutorial/tutorial.cpp > CMakeFiles/tutorial.dir/tutorial.cpp.i

CMakeFiles/tutorial.dir/tutorial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tutorial.dir/tutorial.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/coastcao/Desktop/cpp_primer_plus/cmake/0_tutorial/tutorial.cpp -o CMakeFiles/tutorial.dir/tutorial.cpp.s

# Object files for target tutorial
tutorial_OBJECTS = \
"CMakeFiles/tutorial.dir/tutorial.cpp.o"

# External object files for target tutorial
tutorial_EXTERNAL_OBJECTS =

tutorial: CMakeFiles/tutorial.dir/tutorial.cpp.o
tutorial: CMakeFiles/tutorial.dir/build.make
tutorial: mathFunctions/libMathFunctions.a
tutorial: CMakeFiles/tutorial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/coastcao/Desktop/cpp_primer_plus/cmake/0_tutorial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tutorial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tutorial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tutorial.dir/build: tutorial

.PHONY : CMakeFiles/tutorial.dir/build

CMakeFiles/tutorial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tutorial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tutorial.dir/clean

CMakeFiles/tutorial.dir/depend:
	cd /Users/coastcao/Desktop/cpp_primer_plus/cmake/0_tutorial/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/coastcao/Desktop/cpp_primer_plus/cmake/0_tutorial /Users/coastcao/Desktop/cpp_primer_plus/cmake/0_tutorial /Users/coastcao/Desktop/cpp_primer_plus/cmake/0_tutorial/build /Users/coastcao/Desktop/cpp_primer_plus/cmake/0_tutorial/build /Users/coastcao/Desktop/cpp_primer_plus/cmake/0_tutorial/build/CMakeFiles/tutorial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tutorial.dir/depend


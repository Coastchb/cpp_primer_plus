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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/coast/Desktop/C++/ch_10

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/coast/Desktop/C++/ch_10/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ch_10.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ch_10.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ch_10.dir/flags.make

CMakeFiles/ch_10.dir/main.cpp.o: CMakeFiles/ch_10.dir/flags.make
CMakeFiles/ch_10.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/coast/Desktop/C++/ch_10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ch_10.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ch_10.dir/main.cpp.o -c /Users/coast/Desktop/C++/ch_10/main.cpp

CMakeFiles/ch_10.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ch_10.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/coast/Desktop/C++/ch_10/main.cpp > CMakeFiles/ch_10.dir/main.cpp.i

CMakeFiles/ch_10.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ch_10.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/coast/Desktop/C++/ch_10/main.cpp -o CMakeFiles/ch_10.dir/main.cpp.s

CMakeFiles/ch_10.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ch_10.dir/main.cpp.o.requires

CMakeFiles/ch_10.dir/main.cpp.o.provides: CMakeFiles/ch_10.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ch_10.dir/build.make CMakeFiles/ch_10.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ch_10.dir/main.cpp.o.provides

CMakeFiles/ch_10.dir/main.cpp.o.provides.build: CMakeFiles/ch_10.dir/main.cpp.o


CMakeFiles/ch_10.dir/stock00.cpp.o: CMakeFiles/ch_10.dir/flags.make
CMakeFiles/ch_10.dir/stock00.cpp.o: ../stock00.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/coast/Desktop/C++/ch_10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ch_10.dir/stock00.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ch_10.dir/stock00.cpp.o -c /Users/coast/Desktop/C++/ch_10/stock00.cpp

CMakeFiles/ch_10.dir/stock00.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ch_10.dir/stock00.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/coast/Desktop/C++/ch_10/stock00.cpp > CMakeFiles/ch_10.dir/stock00.cpp.i

CMakeFiles/ch_10.dir/stock00.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ch_10.dir/stock00.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/coast/Desktop/C++/ch_10/stock00.cpp -o CMakeFiles/ch_10.dir/stock00.cpp.s

CMakeFiles/ch_10.dir/stock00.cpp.o.requires:

.PHONY : CMakeFiles/ch_10.dir/stock00.cpp.o.requires

CMakeFiles/ch_10.dir/stock00.cpp.o.provides: CMakeFiles/ch_10.dir/stock00.cpp.o.requires
	$(MAKE) -f CMakeFiles/ch_10.dir/build.make CMakeFiles/ch_10.dir/stock00.cpp.o.provides.build
.PHONY : CMakeFiles/ch_10.dir/stock00.cpp.o.provides

CMakeFiles/ch_10.dir/stock00.cpp.o.provides.build: CMakeFiles/ch_10.dir/stock00.cpp.o


# Object files for target ch_10
ch_10_OBJECTS = \
"CMakeFiles/ch_10.dir/main.cpp.o" \
"CMakeFiles/ch_10.dir/stock00.cpp.o"

# External object files for target ch_10
ch_10_EXTERNAL_OBJECTS =

ch_10: CMakeFiles/ch_10.dir/main.cpp.o
ch_10: CMakeFiles/ch_10.dir/stock00.cpp.o
ch_10: CMakeFiles/ch_10.dir/build.make
ch_10: CMakeFiles/ch_10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/coast/Desktop/C++/ch_10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ch_10"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ch_10.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ch_10.dir/build: ch_10

.PHONY : CMakeFiles/ch_10.dir/build

CMakeFiles/ch_10.dir/requires: CMakeFiles/ch_10.dir/main.cpp.o.requires
CMakeFiles/ch_10.dir/requires: CMakeFiles/ch_10.dir/stock00.cpp.o.requires

.PHONY : CMakeFiles/ch_10.dir/requires

CMakeFiles/ch_10.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ch_10.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ch_10.dir/clean

CMakeFiles/ch_10.dir/depend:
	cd /Users/coast/Desktop/C++/ch_10/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/coast/Desktop/C++/ch_10 /Users/coast/Desktop/C++/ch_10 /Users/coast/Desktop/C++/ch_10/cmake-build-debug /Users/coast/Desktop/C++/ch_10/cmake-build-debug /Users/coast/Desktop/C++/ch_10/cmake-build-debug/CMakeFiles/ch_10.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ch_10.dir/depend


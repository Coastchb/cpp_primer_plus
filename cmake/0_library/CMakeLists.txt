### compulsive headers
cmake_minimum_required(VERSION 2.6)
project(MyPrint)
set(CMAKE_MACOSX_RPATH 1)

### optional headers
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -W -Wall -Wextra -O3 -fPIC -c")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall -pipe -g3 -fPIC")



###### part 1: compile the target dynamic library #######
### add directory to find the include files
INCLUDE_DIRECTORIES("src/utils")

### get the source files the target depends on, and will be used in add_library/add_executable
file(GLOB_RECURSE util_SRCS "src/utils/*.cpp")  # get files recursively
#message(${util_SRCS})


### add library
add_library(myprint SHARED src/func1.cpp ${util_SRCS})




###### part 2: export headers and library to ../0_tutorial ######

### export headers to ../0_tutorial/include
file(GLOB_RECURSE src_headers "src/*.h")
message("${src_headers}")

list(APPEND to_export_headers "${src_headers}")
message(${to_export_headers})
list(TRANSFORM to_export_headers REPLACE "${PROJECT_SOURCE_DIR}/src/" "")
message(${to_export_headers})


### export library to ../0_tutorial/lib
list(APPEND to_export_libs "${PROJECT_BINARY_DIR}/lib${PROJECT_NAME}.dylib")
#message("${to_export_libs}")


### include the configure file to execute copying
include("${PROJECT_SOURCE_DIR}/../0_tutorial/conf_for_cmake.txt")

########
# make install often used to install to system path,even if we can change the destination
#set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/../0_tutorial)
#message("${CMAKE_INSTALL_PREFIX}")
#install (TARGETS myprint DESTINATION ./lib)
#install (DIRECTORY src/ DESTINATION ./include PATTERN "*.h")
########

###
#AUX_SOURCE_DIRECTORY("src" src_root)
#message("${src_root}")

cmake_minimum_required(VERSION 2.6)
project(Tutorial)

### add version info
# version number
set (Tutorial_version_major 1)
set (Tutorail_version_minor 0)

### set an optional
option(USE_MYMATH_OPTION "use the tutorial provided math implemention" ON)

###
configure_file(
        "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
        "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

# add the MathFunctions library?
if (USE_MYMATH_OPTION)
    message("${USE_MYMATH_OPTION}")
    include_directories ("${PROJECT_SOURCE_DIR}/mathFunctions")
    ### compile and use the library
    add_subdirectory (mathFunctions)
    set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH_OPTION)


### add directory to find the include files
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/include/")

### add library directories and the library
link_directories("${PROJECT_SOURCE_DIR}/lib/")
list(APPEND EXTRA_LIBS "MyPrint")

### compile and link to build the target executable
add_executable(tutorial tutorial.cpp)
target_link_libraries(tutorial ${EXTRA_LIBS})



####################
###### use make install to compile executable and include files (but it seems needless) ######
### modify the default varible: CMAKE_INSTALL_PREFIX is used to determine the root of where the files will be installed
#set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR})

#install(TARGETS tutorial DESTINATION bin)
#install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
#        DESTINATION include)
####################
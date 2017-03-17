# Set CMake minimum version and CMake policy required by UrhoCommon module
cmake_minimum_required (VERSION 3.2.3)
if (COMMAND cmake_policy)
    # Libraries linked via full path no longer produce linker search paths
    cmake_policy (SET CMP0003 NEW)
    # INTERFACE_LINK_LIBRARIES defines the link interface
    cmake_policy (SET CMP0022 NEW)
    # Disallow use of the LOCATION target property - so we set to OLD as we still need it
    cmake_policy (SET CMP0026 OLD)
    # MACOSX_RPATH is enabled by default
    cmake_policy (SET CMP0042 NEW)
endif ()

# Set project name
project (urho_iogram)

# Set CMake modules search path
set (CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake/Modules)

# Include UrhoCommon.cmake module after setting project name
include (UrhoCommon)

# Define target name
set (TARGET_NAME iogram)

#c11
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Define source files
#define_source_files (GLOB_CPP_PATTERNS src/*.cpp src/*.cc GLOB_H_PATTERNS src/*.h)
define_source_files (GLOB_CPP_PATTERNS src/framework/src/*.c* src/iogram/Urho3D/UI/*.c* src/Main.cpp GLOB_H_PATTERNS src/framework/src/*.h* src/iogram/Urho3D/UI/*.h* src/Main.h RECURSE GROUP )

# Setup target with resource copying
setup_main_executable ()

add_subdirectory("src/iogram/Core")
#add_subdirectory("src/iogram/Geometry")
add_subdirectory("src/iogram/Components")

add_dependencies(${TARGET_NAME} Core)
#add_dependencies(${TARGET_NAME} Geometry)
add_dependencies(${TARGET_NAME} Components)

#get rid of resource copying
set(RESOURCE_DIRS "")

add_definitions(-DNOMINMAX)

#link the libs
include_directories("src/iogram/Core")
#include_directories("src/iogram/Geometry")
include_directories("src/iogram/Components")

target_link_libraries(${TARGET_NAME} Components)
target_link_libraries(${TARGET_NAME} Core)
#target_link_libraries(${TARGET_NAME} Geometry)
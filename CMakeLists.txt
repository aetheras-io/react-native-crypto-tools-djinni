cmake_minimum_required(VERSION 3.6)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
option(TARGET_JNI "Indicates wether or not the toolchain must build for JNI or not" OFF)
option(BUILD_TESTS "Indicates wether or not the toolchain must build the test or not" ON)

# message(STATUS "JNI? " ${TARGET_JNI})
# message(STATUS "ANDROID " ${ANDROID})
# message(STATUS "PROJECT SOURCE " ${PROJECT_SOURCE_DIR})
# message(STATUS "JAVA_HOME  " ${JAVA_HOME})

#list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
#include(UseBackportedModules)

# The project version number.
set(VERSION_MAJOR   0   CACHE STRING "Project major version number.")
set(VERSION_MINOR   1   CACHE STRING "Project minor version number.")
set(VERSION_PATCH   0   CACHE STRING "Project patch version number.")
mark_as_advanced(VERSION_MAJOR VERSION_MINOR VERSION_PATCH)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY build)
#list(APPEND INCLUDE_DIRECTORIES core/test/include/)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MACOSX_RPATH 1)

string(FIND "${CMAKE_OSX_SYSROOT}" "iphone" IS_IOS)
if(((IS_IOS GREATER 0) OR (IS_IOS EQUAL 0)) OR TARGET_JNI OR ANDROID)
    set(BUILD_TESTING OFF CACHE BOOL "iOS build fail otherwise" FORCE)
    set(BUILD_TESTS OFF CACHE BOOL "Cannot run tests for these options" FORCE)
endif()

#if(APPLE)
#    set(JAVA_INCLUDE_PATH2 "$ENV{JAVA_HOME}/include" CACHE PATH "")
#endif()

#add_subdirectory(doc)
add_subdirectory(core)

#if (BUILD_TESTS)
#    add_subdirectory(qt-host)
#endif()

enable_testing()
cmake_minimum_required(VERSION 3.6)
project(crypto-core)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
option(TARGET_JNI "Indicates wether or not the toolchain must build for JNI or not" ON)
option(ANDROID "Indicates wether or not the toolchain must build for ANDROID or not" ON)
option(BUILD_TESTS "Indicates wether or not the toolchain must build the test or not" OFF)

include(${CMAKE_CURRENT_SOURCE_DIR}/../CMakeLists.txt)

cmake_minimum_required(VERSION 2.8.11)

message(STATUS ${CMAKE_CURRENT_DIR})
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# add sources
list(APPEND core-sources
        api_impl/greetingImpl.hpp
        api_impl/greetingImpl.cpp
        )

set(ANDROID_CPP_FEATURES exceptions)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# Automatically ADD djinni api files to the library
file(GLOB core-djinni-api-sources
        "generated_api/*"
        )
list(APPEND core-sources ${core-djinni-api-sources})

file(GLOB core-jni-sources
    "generated_jni/*.cpp"
    "generated_jni/*.hpp"
    "generated_jni/jni/*"
    )

if (TARGET_JNI)
    message(STATUS "Configure project for JNI")
    if(NOT ANDROID)
        find_package(JNI REQUIRED)
    endif()
    list(APPEND core-sources ${core-jni-sources})
endif ()

function (ListToString result delim)
    list(GET ARGV 2 temp)
    math(EXPR N "${ARGC}-1")
    foreach(IDX RANGE 3 ${N})
        list(GET ARGV ${IDX} STR)
        set(temp "${temp}${delim}${STR}")
    endforeach()
    set(${result} "${temp}" PARENT_SCOPE)
endfunction(ListToString)

#set(LIB_BUILD_TYPE SHARED)
ListToSTring(str "\n" ${core-sources})
message(STATUS ${str})
add_library(core-native SHARED ${core-sources})

target_include_directories(
    core-native
    PUBLIC
    generated_api
    generated_jni
    generated_jni/jni
    )
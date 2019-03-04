cmake_minimum_required(VERSION 2.8.11)

message(STATUS ${CMAKE_CURRENT_DIR})
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# add sources
list(APPEND core-sources
        api_impl/greetingImpl.hpp
        api_impl/greetingImpl.cpp
        api_impl/Secp256k1Impl.cpp
        api_impl/Secp256k1Impl.hpp
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
    add_definitions(-DTARGET_JNI=1)
endif ()

add_library(core-interface INTERFACE)
link_directories(${CMAKE_BINARY_DIR}/lib)
file(GLOB_RECURSE SRC_FILES *.cpp)
file(GLOB_RECURSE HEADERS_FILES *.h *.hpp)

#Secp256k1
target_link_libraries(core-interface INTERFACE "${CMAKE_SOURCE_DIR}/core/lib/secp256k1/lib/${CMAKE_STATIC_LIBRARY_PREFIX}secp256k1${CMAKE_STATIC_LIBRARY_SUFFIX}")
link_directories("${CMAKE_SOURCE_DIR}/core/lib/secp256k1/lib")
add_dependencies(core-interface INTERFACE secp256k1)

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
ListToSTring(str1 "\n" ${SRC_FILES})
ListToSTring(str2 "\n" ${SRC_FILES})
message(STATUS "SRC_FILES\n" ${str1})
message(STATUS "HEADERS_FILES\n" ${str2})


add_library(core-native SHARED ${core-sources})

target_include_directories(
    core-native
    PUBLIC
    generated_api
    generated_jni
    generated_jni/jni
    ../lib/secp256k1
    )

# target_include_directories(core-native INTERFACE )

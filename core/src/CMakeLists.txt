cmake_minimum_required(VERSION 3.12)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(ANDROID_CPP_FEATURES exceptions)

# Automaticall ADD djinni api files to the library
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
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

link_directories(${CMAKE_BINARY_DIR}/lib)

file(GLOB_RECURSE SRC_FILES *.cpp)
file(GLOB_RECURSE HEADERS_FILES *.h *.hpp)
list(REMOVE_ITEM SRC_FILES ${core-jni-sources})
list(REMOVE_ITEM SRC_FILES dummy.cpp)
list(REMOVE_ITEM HEADERS_FILES ${core-jni-sources})

add_library(core-interface INTERFACE)

string(FIND "${CMAKE_OSX_SYSROOT}" "iphone" IS_IOS)
if(IS_IOS GREATER_EQUAL 0)
    add_library(core SHARED
            ${core-sources}
            ${SRC_FILES}
            ${HEADERS_FILES})
    target_link_libraries(core PUBLIC core-interface)
    set(CMAKE_SHARED_LINKER_FLAGS "-Wall")
    set(FRAMEWORK_BUNDLE_IDENTIFIER "com.ledger.core")
    set(DEPLOYMENT_TARGET 9.0)
    set(DEVICE_FAMILY "1")
    set(PRODUCT_NAME core)
    set_target_properties(core PROPERTIES
            FRAMEWORK TRUE
            FRAMEWORK_VERSION A
            MACOSX_FRAMEWORK_IDENTIFIER ${FRAMEWORK_BUNDLE_IDENTIFIER}
            MACOSX_FRAMEWORK_BUNDLE_VERSION ${VERSION_MAJOR}
            MACOSX_FRAMEWORK_SHORT_VERSION_STRING "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}"
            MACOSX_FRAMEWORK_INFO_PLIST ${CMAKE_BINARY_DIR}/framework.plist.in
            # "current version" in semantic format in Mach-O binary file
            VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}
            # "compatibility version" in semantic format in Mach-O binary file
            SOVERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}
            PUBLIC_HEADER "${CMAKE_BINARY_DIR}/include/ledger/core"
            XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET ${DEPLOYMENT_TARGET}
            XCODE_ATTRIBUTE_TARGETED_DEVICE_FAMILY ${DEVICE_FAMILY}
            XCODE_ATTRIBUTE_SKIP_INSTALL "YES"
            )
    add_custom_command(
            TARGET core
            POST_BUILD
            COMMAND /bin/bash -c "${CMAKE_BINARY_DIR}/install_name.sh \${BUILT_PRODUCTS_DIR}/\${PRODUCT_NAME}.framework/\${PRODUCT_NAME} ${CMAKE_OSX_ARCHITECTURES}"
    )
    add_custom_command(
            TARGET core
            POST_BUILD
            COMMAND install_name_tool -id \"@rpath/\${PRODUCT_NAME}.framework/\${PRODUCT_NAME}\"
            \${BUILT_PRODUCTS_DIR}/\${PRODUCT_NAME}.framework/\${PRODUCT_NAME}
    )
else()
    add_library(core-obj OBJECT
            ${core-sources}
            ${SRC_FILES}
            ${HEADERS_FILES})
    target_link_libraries(core-obj PUBLIC core-interface)
    # shared and static libraries built from the same object files
    add_library(core SHARED)
    target_link_libraries(core PUBLIC core-obj)

    add_library(core-static STATIC)
    target_link_libraries(core-static PUBLIC core-obj)
    install(TARGETS core-static DESTINATION "lib")
endif()

if(UNIX AND NOT APPLE AND NOT ANDROID)
    target_link_libraries(core-interface INTERFACE -static-libstdc++)
endif()

#target_link_libraries(core-interface INTERFACE crypto)
#Secp256k1
target_link_libraries(core-interface INTERFACE "${CMAKE_SOURCE_DIR}/core/lib/secp256k1/lib/${CMAKE_STATIC_LIBRARY_PREFIX}secp256k1${CMAKE_STATIC_LIBRARY_SUFFIX}")
link_directories("${CMAKE_SOURCE_DIR}/core/lib/secp256k1/lib")
add_dependencies(core-interface INTERFACE secp256k1)

file(GLOB CORE_API_HEADERS
        "api/*.hpp"
        )

include_directories(core-interface INTERFACE ../lib/bigd)

if (TARGET_JNI)
    include_directories(core-interface INTERFACE ${JNI_INCLUDE_DIRS})
    target_link_libraries(core-interface INTERFACE ${JNI_LIBRARIES})
endif ()

file(GLOB core-header
        "*"
        )

file(COPY ${core-header} DESTINATION ${CMAKE_BINARY_DIR}/include/core FILES_MATCHING PATTERN "*.h")
file(COPY ${core-header} DESTINATION ${CMAKE_BINARY_DIR}/include/core FILES_MATCHING PATTERN "*.hpp")

target_include_directories(core-interface INTERFACE ..)
target_include_directories(core-interface INTERFACE ../lib/secp256k1)

install(TARGETS core DESTINATION "lib")
install(FILES ${CORE_API_HEADERS} DESTINATION "include/core")
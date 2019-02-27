# Project Structure

Initial structure created with frostney/react-native-create-library (recommended officially by facebook's documentation).  Djinni is used to create boilerplate obj-C and java/jni bindings.  Build steps are configured using CMake in the root CMakeLists.txt.  Each platform will use their own native build tools (Android Gradle and IOS XCode) for the C/C++ libraries.

- Java8 is required for deps/djinni
- Cmake 3.2.0+ and clang/gcc are required for C/C++
- Automake, Autoconf, Pkg-config and Libtool required for bitcoin-core/secp256k1
- C++ Libraries and their Shims located in "./core"

# Makefile Magic

- Djinni generation, cleanup and movement of generated files to correct locations

# Setup Steps Taken (Android)

- Installed Android Studio and Android NDK (Native Development Kit)
- Modified "./android/build.gradle" to a newer gradle version than the generated one  (2.2.1 -> 3.2.1)
- Created Android dependencies and GradleWrapper(gradlew) by opening "./android" with Android Studio

## Android

This section describes the necessary items that were modified to create the android build pipeline

- Added "externalNativeBuild" block in "./android/build.gradle" to hook up the cmake pipline to the gradle pipline.  This uses gradle settings for CMake and also the NDK to do the actual compilation, which guarantees the correct build time settings for Android


## C++

- bitcoin-core/secp256k1 requires a prebuild to generate a special binary header file https://github.com/bitcoin-core/secp256k1/issues/394
- bitcoin-core/secp256k1 needs to be built with "./configure --disable-shared --disable-tests --disable-coverage --disable-openssl-tests --disable-exhaustive-tests --disable-jni --with-bignum=no --with-field=64bit --with-scalar=64bit --with-asm=no"
- use "make core/lib/secp256k1/gen_context/ecmult_static_context.h" to generate the context.  Modify the file from ```#include "src/group.h"``` to ```#include "group.h"```
- core/lib/cmake/ProjectSecp256k1 has a lot of magic and version pinning to a hash.  Updating this library will be a manual process
#!/bin/bash

GIT_REPO="https://github.com/aetheras-io/react-native-crypto-tools.git"
GIT_BRANCH="master"
GIT_BIN=$(which git)
CMAKE_BIN=$(which cmake)
MAKE_BIN=$(which make)
WORK_DIR=./dist
echo ${BUILD_DIR}

if [ ! -d "${WORK_DIR}" ]; then
    mkdir -p ${WORK_DIR}
fi

function check_deps() {
    if [ -z "${1}" ]; then
        echo "Missing dependencies: ${2}"
        exit 1
    fi
}

while getopts "rb" option; do
    case $option in
        r)
            GIT_REPO="${OPTARG}"
        ;;
        b)
            GIT_BRANCH="${OPTARG}"
        ;;
        j)
            BUILD_OPS="-DTARGET_JNI=on"
        ;;
        *)
            usage: "${0} [-r git repository] [-b git branch] [-j to enable jni bindings]"
            exit 1
        ;;
    esac
done

check_deps "${GIT_BIN}" "git"
check_deps "${CMAKE_BIN}" "cmake"
check_deps "${MAKE_BIN}" "make"

cd ${WORK_DIR}

# Check cmake version and install it when required
cmake_version=$($CMAKE_BIN --version | head -n 1 | awk '{print $3}')
cmake_major=$(echo ${cmake_version} | cut -f 1 -d.)
cmake_minor=$(echo ${cmake_version} | cut -f 2 -d.)

if [ $cmake_major -lt 3 ] || [ $cmake_minor -lt 10 ]; then
    echo "cmake is too old"
    exit 1
fi

# echo "Cloning sources"
# cd ${BUILD_DIR}
# src_dir=$(echo ${GIT_REPO} | rev | cut -d'/' -f 1 | rev | cut -f 1 -d.)
# git clone "${GIT_REPO}"
# cd ${src_dir}

# if [ "$(git branch | grep '^*' | awk '{print $2}')" != "${GIT_BRANCH}" ]; then
#     git checkout -b "${GIT_BRANCH}" "origin/${GIT_BRANCH}"
# fi

set -e
#git submodule update --init
pwd
cmake "${BUILD_OPS}" ../
#make

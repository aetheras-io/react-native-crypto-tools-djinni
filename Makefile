# Path and Variables
ORG := aetheras-io
PROJECT := RNCryptoTools
REPO := github.com/${ORG}/${PROJECT}
ROOT_DIR := $(shell pwd)
OUTPUT_DIR := ${ROOT_DIR}/dist
$(shell mkdir -p ${OUTPUT_DIR})

# Djinni IDL file location
#DJINNI_FILE := core/core.djinni
DJINNI_FILE := core/idl/greeting.djinni
# C++ namespace for generated src
C_NAMESPACE := crypto::core::api
# Objective-C class name prefix for generated src
OBJC_PREFIX := HW
# Java package name for generated src
JAVA_PACKAGE := io.aetheras.djinni
# get java directory from package name
JAVA_DIR := $(shell echo ${JAVA_PACKAGE} | tr . /)
# output directories for generated src
CPP_OUT := core/src/api

deps: deps/djinni

deps/djinni:
	#fix to some version at a later point
	git submodule add https://github.com/dropbox/djinni.git deps/djinni

core/lib/secp256k1:
	git submodule add https://github.com/bitcoin-core/secp256k1.git core/lib/secp256k1

deps-update:
	git submodule update --init --recursive

djinni: clean-djinni
	./deps/djinni/src/run \
	--java-out "${OUTPUT_DIR}/djinni/java/${JAVA_DIR}" \
	--java-package "${JAVA_PACKAGE}" \
	--cpp-out "${CPP_OUT}" \
	--cpp-namespace ${C_NAMESPACE} \
	--ident-java-field "mFooBar" \
	--jni-out "${OUTPUT_DIR}/djinni/jni" \
	--ident-jni-class "NativeCryptoTools" \
	--ident-jni-file "NativeCryptoTools" \
	--objc-out "${OUTPUT_DIR}/djinni/objc" \
	--objc-type-prefix "${OBJC_PREFIX}" \
	--objcpp-out "${OUTPUT_DIR}/djinni/objc" \
	--idl "${DJINNI_FILE}"

ship:
	echo "shipping"

clean: 
	rm -rf ${OUTPUT_DIR}

clean-djinni:
	rm -rf ${CPP_OUT} ${OUTPUT_DIR}/djinni

.PHONY: djinni ship clean deps-update

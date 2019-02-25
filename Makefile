# Path and Variables
ORG := aetheras-io
PROJECT := RNCryptoTools
REPO := github.com/${ORG}/${PROJECT}
ROOT_DIR := $(shell pwd)
OUTPUT_DIR := ${ROOT_DIR}/dist
$(shell mkdir -p ${OUTPUT_DIR})

# Djinni configuration
#DJINNI_FILE := core/core.djinni
DJINNI_FILE := ${ROOT_DIR}/core/idl/greeting.djinni
CPP_NAMESPACE := crypto::core::api
CPP_OUT := ${ROOT_DIR}/core/src/generated_api
OBJC_PREFIX := AIO
OBJC_OUT := ${ROOT_DIR}/ios/generated_objc
OBJCPP_OUT := ${ROOT_DIR}/ios/generated_objcpp
JAVA_PACKAGE := io.aetheras.djinni
JAVA_DIR := $(shell echo ${JAVA_PACKAGE} | tr . /)
JAVA_OUT := ${ROOT_DIR}/android/src/main/java/${JAVA_DIR}
JNI_OUT := ${ROOT_DIR}/core/src/generated_jni

deps: deps/djinni core/lib/secp256k1

deps/djinni:
	#fix to some version at a later point
	git submodule add https://github.com/dropbox/djinni.git deps/djinni

core/lib/secp256k1:
	git submodule add https://github.com/bitcoin-core/secp256k1.git core/lib/secp256k1

deps-update:
	git submodule update --init --recursive

djinni: 
	./deps/djinni/src/run \
	--java-out "${JAVA_OUT}" \
	--java-package "${JAVA_PACKAGE}" \
	--cpp-out "${CPP_OUT}" \
	--cpp-namespace ${CPP_NAMESPACE} \
	--ident-java-field "mFooBar" \
	--jni-out "${JNI_OUT}/jni" \
	--jni-include-cpp-prefix "../../generated_api/" \
	--ident-jni-class "NativeCryptoTools" \
	--ident-jni-file "NativeCryptoTools" \
	--objc-out "${OBJC_OUT}" \
	--objcpp-out "${OBJCPP_OUT}" \
	--objc-type-prefix "${OBJC_PREFIX}" \
	--idl "${DJINNI_FILE}"
	@echo "copying support-lib files to ${JNI_OUT}"
	cp ./deps/djinni/support-lib/jni/* ${JNI_OUT}/jni
	cp ./deps/djinni/support-lib/*.hpp ${JNI_OUT}

ship:
	echo "shipping"

clean: clean-android clean-djinni
	rm -rf ${OUTPUT_DIR}

clean-djinni:
	rm -rf ${CPP_OUT} ${JNI_OUT} ${ROOT_DIR}/android/src/main/java/io ${OBJC_OUT} ${OBJCPP_OUT}

clean-android:
	# Clean gradle, remove built native binaries and remove djinni jni bridge
	android/gradlew clean
	rm -rf android/native
	rm -rf ${JAVA_OUT}/io

.PHONY: djinni ship clean deps-update

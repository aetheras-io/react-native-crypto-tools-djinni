// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from greeting.djinni

#include "greeting_service.hpp"  // my header
#include "Marshal.hpp"

namespace djinni_generated {

GreetingService::GreetingService() : ::djinni::JniInterface<::crypto::core::api::GreetingService, GreetingService>("io/aetheras/djinni/GreetingService$CppProxy") {}

GreetingService::~GreetingService() = default;


CJNIEXPORT void JNICALL Java_io_aetheras_djinni_GreetingService_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::crypto::core::api::GreetingService>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_io_aetheras_djinni_GreetingService_00024CppProxy_createService(JNIEnv* jniEnv, jobject /*this*/)
{
    try {
        DJINNI_FUNCTION_PROLOGUE0(jniEnv);
        auto r = ::crypto::core::api::GreetingService::create_service();
        return ::djinni::release(::djinni_generated::GreetingService::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_io_aetheras_djinni_GreetingService_00024CppProxy_native_1greet(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jobject j_who)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::crypto::core::api::GreetingService>(nativeRef);
        auto r = ref->greet(::djinni::List<::djinni::String>::toCpp(jniEnv, j_who));
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated

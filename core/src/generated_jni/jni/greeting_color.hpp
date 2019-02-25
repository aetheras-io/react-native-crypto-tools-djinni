// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from greeting.djinni

#pragma once

#include "../../generated_api/greeting_color.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class GreetingColor final : ::djinni::JniEnum {
public:
    using CppType = ::crypto::core::api::GreetingColor;
    using JniType = jobject;

    using Boxed = GreetingColor;

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return static_cast<CppType>(::djinni::JniClass<GreetingColor>::get().ordinal(jniEnv, j)); }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, CppType c) { return ::djinni::JniClass<GreetingColor>::get().create(jniEnv, static_cast<jint>(c)); }

private:
    GreetingColor() : JniEnum("io/aetheras/djinni/GreetingColor") {}
    friend ::djinni::JniClass<GreetingColor>;
};

}  // namespace djinni_generated
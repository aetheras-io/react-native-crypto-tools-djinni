// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from greeting.djinni

#include "greeting.hpp"  // my header
#include "Marshal.hpp"
#include "greeting_color.hpp"

namespace djinni_generated {

Greeting::Greeting() = default;

Greeting::~Greeting() = default;

auto Greeting::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<Greeting>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.message)),
                                                           ::djinni::get(::djinni_generated::GreetingColor::fromCpp(jniEnv, c.color)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto Greeting::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 3);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<Greeting>::get();
    return {::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_mMessage)),
            ::djinni_generated::GreetingColor::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_mColor))};
}

}  // namespace djinni_generated

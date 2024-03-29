// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from secp256k1.djinni

#pragma once

#include "../../generated_api/Secp256k1.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class Secp256k1 final : ::djinni::JniInterface<::crypto::core::api::Secp256k1, Secp256k1> {
public:
    using CppType = std::shared_ptr<::crypto::core::api::Secp256k1>;
    using CppOptType = std::shared_ptr<::crypto::core::api::Secp256k1>;
    using JniType = jobject;

    using Boxed = Secp256k1;

    ~Secp256k1();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<Secp256k1>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<Secp256k1>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    Secp256k1();
    friend ::djinni::JniClass<Secp256k1>;
    friend ::djinni::JniInterface<::crypto::core::api::Secp256k1, Secp256k1>;

};

}  // namespace djinni_generated

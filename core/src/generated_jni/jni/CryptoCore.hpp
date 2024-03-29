// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from core.djinni

#pragma once

#include "../../generated_api/CryptoCore.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class CryptoCore final : ::djinni::JniInterface<::crypto::core::api::CryptoCore, CryptoCore> {
public:
    using CppType = std::shared_ptr<::crypto::core::api::CryptoCore>;
    using CppOptType = std::shared_ptr<::crypto::core::api::CryptoCore>;
    using JniType = jobject;

    using Boxed = CryptoCore;

    ~CryptoCore();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<CryptoCore>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<CryptoCore>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    CryptoCore();
    friend ::djinni::JniClass<CryptoCore>;
    friend ::djinni::JniInterface<::crypto::core::api::CryptoCore, CryptoCore>;

};

}  // namespace djinni_generated

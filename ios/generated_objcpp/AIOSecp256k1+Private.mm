// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from secp256k1.djinni

#import "AIOSecp256k1+Private.h"
#import "AIOSecp256k1.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface AIOSecp256k1 ()

- (id)initWithCpp:(const std::shared_ptr<::crypto::core::api::Secp256k1>&)cppRef;

@end

@implementation AIOSecp256k1 {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::crypto::core::api::Secp256k1>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::crypto::core::api::Secp256k1>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

+ (nullable AIOSecp256k1 *)createInstance {
    try {
        auto objcpp_result_ = ::crypto::core::api::Secp256k1::createInstance();
        return ::djinni_generated::Secp256k1::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nullable AIOSecp256k1 *)newInstance {
    try {
        auto objcpp_result_ = ::crypto::core::api::Secp256k1::newInstance();
        return ::djinni_generated::Secp256k1::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSData *)computePubKey:(nonnull NSData *)privKey
                         compress:(BOOL)compress {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->computePubKey(::djinni::Binary::toCpp(privKey),
                                                                 ::djinni::Bool::toCpp(compress));
        return ::djinni::Binary::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSData *)computeUncompressedPubKey:(nonnull NSData *)pubKey {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->computeUncompressedPubKey(::djinni::Binary::toCpp(pubKey));
        return ::djinni::Binary::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSData *)sign:(nonnull NSData *)privKey
                    data:(nonnull NSData *)data {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->sign(::djinni::Binary::toCpp(privKey),
                                                        ::djinni::Binary::toCpp(data));
        return ::djinni::Binary::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (BOOL)verify:(nonnull NSData *)data
     signature:(nonnull NSData *)signature
        pubKey:(nonnull NSData *)pubKey {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->verify(::djinni::Binary::toCpp(data),
                                                          ::djinni::Binary::toCpp(signature),
                                                          ::djinni::Binary::toCpp(pubKey));
        return ::djinni::Bool::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto Secp256k1::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto Secp256k1::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<AIOSecp256k1>(cpp);
}

}  // namespace djinni_generated

@end

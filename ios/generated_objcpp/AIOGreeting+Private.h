// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from greeting.djinni

#import "AIOGreeting.h"
#include "greeting.hpp"

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class AIOGreeting;

namespace djinni_generated {

struct Greeting
{
    using CppType = ::crypto::core::api::Greeting;
    using ObjcType = AIOGreeting*;

    using Boxed = Greeting;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCpp(const CppType& cpp);
};

}  // namespace djinni_generated

// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from greeting.djinni

#pragma once

#include <functional>

namespace crypto { namespace core { namespace api {

enum class GreetingColor : int {
    RED,
    BLUE,
};

} } }  // namespace crypto::core::api

namespace std {

template <>
struct hash<::crypto::core::api::GreetingColor> {
    size_t operator()(::crypto::core::api::GreetingColor type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std

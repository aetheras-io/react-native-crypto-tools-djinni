// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from greeting.djinni

#pragma once

#include "greeting_color.hpp"
#include <string>
#include <utility>

namespace crypto { namespace core { namespace api {

struct Greeting final {
    std::string message;
    GreetingColor color;

    Greeting(std::string message_,
             GreetingColor color_)
    : message(std::move(message_))
    , color(std::move(color_))
    {}
};

} } }  // namespace crypto::core::api

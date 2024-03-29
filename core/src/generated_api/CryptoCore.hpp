// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from core.djinni

#pragma once

#include <cstdint>
#include <string>

namespace crypto { namespace core { namespace api {

/**
 * @import "idl/example.djinni"
 * @import "idl/errors.djinni"
 */
class CryptoCore {
public:
    virtual ~CryptoCore() {}

    /**
     * Gets the version of the library as a human readable string.
     * @return The version of the library (e.g. '1.0.1')
     */
    static std::string getStringVersion();

    /**
     * Get the integer version of the Library
     * @return The integer version of the library
     */
    static int32_t getIntVersion();
};

} } }  // namespace crypto::core::api

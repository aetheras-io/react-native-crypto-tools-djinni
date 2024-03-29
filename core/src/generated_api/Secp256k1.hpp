// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from secp256k1.djinni

#pragma once

#include <cstdint>
#include <memory>
#include <vector>

namespace crypto { namespace core { namespace api {

/**Bitcoin secp256k1 library interface */
class Secp256k1 {
public:
    virtual ~Secp256k1() {}

    /**
     * Create an instance of Secp256k1
     * @return Secp256k1 instance
     */
    static std::shared_ptr<Secp256k1> createInstance();

    static std::shared_ptr<Secp256k1> newInstance();

    /**
     * Generates public key from private key.
     * @param privKey 32 byte private key
     * @param compress get compressed (35 bytes) or uncompressed (65 bytes)
     * @return public key can be compressed (35 bytes starting with 02 or 03) or uncompressed (65 bytes starting with 04)
     */
    virtual std::vector<uint8_t> computePubKey(const std::vector<uint8_t> & privKey, bool compress) = 0;

    /**
     * Generates uncompressed public key from compressed public key.
     * @param pubKey 33 byte private key (starting with 02 or 03)
     * @return uncompressed public key (65 bytes starting with 04)
     */
    virtual std::vector<uint8_t> computeUncompressedPubKey(const std::vector<uint8_t> & pubKey) = 0;

    /**
     * Signs message using a given private key
     * @param privKey 32 bytes private key
     * @param data 32 bytes message to sign
     * @return 32 bytes signed message
     */
    virtual std::vector<uint8_t> sign(const std::vector<uint8_t> & privKey, const std::vector<uint8_t> & data) = 0;

    /**
     * Check if message was signed with given signature and public key
     * @param data 32 bytes signed message
     * @param signature 32 bytes signature (generated from private key)
     * @param oubkey 32 bytes public key
     * @return true if message was signed with signature and public key (both issued from same private key)
     */
    virtual bool verify(const std::vector<uint8_t> & data, const std::vector<uint8_t> & signature, const std::vector<uint8_t> & pubKey) = 0;
};

} } }  // namespace crypto::core::api

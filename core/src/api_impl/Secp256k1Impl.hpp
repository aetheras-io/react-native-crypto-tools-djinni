#include <generated_api/Secp256k1.hpp>
#include <include/secp256k1.h>

namespace crypto { namespace core {
    class Secp256k1Impl : public api::Secp256k1 {
      public:
        Secp256k1Impl();
        std::vector<uint8_t> computePubKey(const std::vector<uint8_t>& privKey,
                                           bool compress) override;
        std::vector<uint8_t>
        computeUncompressedPubKey(const std::vector<uint8_t>& pubKey) override;
        std::vector<uint8_t> sign(const std::vector<uint8_t>& privKey,
                                  const std::vector<uint8_t>& data) override;
        bool verify(const std::vector<uint8_t>& data,
                    const std::vector<uint8_t>& signature,
                    const std::vector<uint8_t>& pubKey) override;

        ~Secp256k1Impl();

      private:
        secp256k1_context* _context;
    };
}}  // namespace crypto::core
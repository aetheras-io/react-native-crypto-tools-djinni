#pragma once

#include "greeting_service.hpp"
#include <memory>
#include <string>

namespace crypto { namespace core { namespace api {

class GreetingServiceImpl : public GreetingService {
  public:
    GreetingServiceImpl(const std::shared_ptr<GreetingDisplay> &display);

    virtual void greet(const std::vector<std::string> &who) override;

  private:
    std::shared_ptr<GreetingDisplay> m_display;
};
}}} // namespace crypto::core::api
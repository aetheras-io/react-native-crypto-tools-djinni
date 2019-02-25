#pragma once

#include "greeting_service.hpp"
#include <memory>
#include <string>

using namespace crypto::core::api;

class GreetingServiceImpl : public GreetingService {
  public:
    GreetingServiceImpl();

    virtual std::string greet(const std::vector<std::string>& who) override;
};
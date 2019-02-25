#include "greetingImpl.hpp"
// #include "greeting.hpp"
// #include "greeting_color.hpp"
// #include "greeting_display.hpp"
#include <stdlib.h>
#include <thread>

using namespace crypto::core::api;

std::shared_ptr<GreetingService> GreetingService::create_service() {
    return std::make_shared<GreetingServiceImpl>();
}

GreetingServiceImpl::GreetingServiceImpl() {}

std::string GreetingServiceImpl::greet(const std::vector<std::string>& who) {
    std::string message = "[CPP]Hello, ";
    for (auto addressee : who) {
        message = message + addressee + ", ";
        // GreetingColor color =
        //     rand() % 100 < 50 ? GreetingColor::RED : GreetingColor::BLUE;
        // Greeting greeting = Greeting(message, color);
        // this->m_display->display(greeting);
        // std::this_thread::sleep_for(
        //     std::chrono::milliseconds(GreetingService::COOLDOWN_MS));
    }
    message = message + "!";
    return message;
}
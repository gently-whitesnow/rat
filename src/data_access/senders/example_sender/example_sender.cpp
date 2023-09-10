#include "example_sender.h"

#include <models/result.h>

#include <iostream>
#include <vector>

ExampleSender::ExampleSender(){};

void ExampleSender::Send(
    const std::vector<Result<std::unique_ptr<BaseDto>>>& resultsVector) noexcept {
    for (const auto& result : resultsVector) {
        if (result.IsSuccess()) {
            std::cout << result.GetValue()->GetStringifyData() << std::endl;
        } else {
            std::cout << "Error:\n" << result.ErrorMessage() << std::endl;
        }
    }
};
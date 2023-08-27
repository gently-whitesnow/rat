#include <iostream>
#include <vector>
#include "example_sender.h"

ExampleSender::ExampleSender(){};

void ExampleSender::Send(const std::vector<std::unique_ptr<IDto>>& dtoVectors) noexcept {
    for (const auto& dto : dtoVectors){
        std::cout << "send data: " << dto->GetStringifyData() << std::endl;
    }
};
#pragma once

#include <models/result.h>

template <typename I, typename O>
class IStartUpPipeHandler {
public:
    virtual Result<O> Handle(const I&& arg) noexcept = 0;
};
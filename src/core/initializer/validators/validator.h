#pragma once

template <typename T>
class IValidator {
public:
    bool Validate(const T&& obj) noexcept const;
};
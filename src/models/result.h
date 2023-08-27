#pragma once

template <typename T>
class Result {
   public:
    explicit Result(T&& value) : _value(std::move(value)), _success(true) {}

    explicit Result(bool success) : _success(success) {}

    T&& ReleaseValue() { return std::move(_value); }

    bool IsSuccess() const { return _success; }

   private:
    T _value;
    bool _success;
};
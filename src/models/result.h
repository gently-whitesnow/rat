#pragma once

#include <string>

#include "result_status.h"

template <typename TValue>
class Result {
   public:
    explicit Result(TValue&& value)
        : _value(std::move(value)), _status(ResultStatus::Success) {}

    explicit Result(ResultStatus status) : _status(status) {}

    explicit Result(const ResultStatus status, const std::string& errorMessage)
        : _status(status), _errorMessage(errorMessage) {}

    TValue&& ReleaseValue() { return std::move(_value); }

    const TValue& GetValue() const { return _value; }

    bool IsSuccess() const { return _status == ResultStatus::Success; }

    bool IsReady() const { return _status != ResultStatus::NotReady; }

    const ResultStatus Status() const { return _status; }

    const std::string& ErrorMessage() const { return _errorMessage; }

   private:
    TValue _value;
    ResultStatus _status;
    std::string _errorMessage;
};
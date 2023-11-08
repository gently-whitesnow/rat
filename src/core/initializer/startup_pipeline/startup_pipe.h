#pragma once

#include <memory>

#include <models/result.h>
#include <core/initializer/startup_pipeline/startup_pipe_handler.h>

template <typename I, typename O, typename Out>
class StartUpPipe {
private:
    const std::unique_ptr<StartUpPipe<O, Result<Out>>> _nextPipe;
    const std::unique_ptr<IStartUpPipeHandler<I, Result<O>>> _currentHandler;
public:
    StartUpPipe() = delete;

    StartUpPipe(const std::unique_ptr<IStartUpPipeHandler<I, Result<O>>>&& currentHandler
                ) : _nextPipe(nullptr), _currentHandler(currentHandler) {}

    StartUpPipe(const std::unique_ptr<StartUpPipe<O, Result<Out>>>&& nextPipe,
                const std::unique_ptr<IStartUpPipeHandler<I, Result<O>>>&& currentHandler
                ) : _nextPipe(nextPipe), _currentHandler(currentHandler) {}

    Result<OResult> Execute(const I&& prevResult) const noexcept {
        auto result = _currentHandler.Handle(prevResult);
        if (result.IsSuccess()) {
            if (_nextPipe != nullptr) {
                return _nextPipe.Execute(result.ReleaseValue());
            } else {
                return result;
            }
        } else {
            return Result<OResult>(false);
        }
    }

    StartUpPipe(const StartUpPipe& other) = delete;
    StartUpPipe& operator = (const StartUpPipe& other) = delete;
};
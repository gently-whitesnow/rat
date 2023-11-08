#pragma once

#include <core/initializer/startup_pipeline/startup_pipe_handler.h>

class StartUpPipelineBuilder {
private:
    StartUpPipelineBuilder(const IStartUpPipeHandler&&)
public:
    static StartUpPipelineBuilder From(const IStartUpPipeHandler&& handler);
};
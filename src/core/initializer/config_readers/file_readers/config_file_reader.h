#pragma once

#include <iostream>
#include <string>

#include <memory>
#include <fstream>

//#include <nlohmann/json.hpp>
//using json = nlohmann::json;

#include <core/initializer/config_readers/config_reader.h>
#include <core/initializer/startup_pipeline/startup_pipe_handler.h>

class ConfigFileReader : public IConfigReader, public IStartUpPipeHandler<std::string, std::string> {
private:
    std::string _filename;

    std::string TryRead() const;
public:
    Result<std::string> Read() const noexcept override;
    Result<std::string> Handle(const std::string&& filename) noexcept override;

    ConfigFileReader(const ConfigFileReader& other) = delete;
    ConfigFileReader& operator = (const ConfigFileReader& other) = delete;
};
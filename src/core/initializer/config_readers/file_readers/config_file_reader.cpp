#include "config_file_reader.h"

Result<std::string> ConfigFileReader::Handle(const std::string&& filename) noexcept {
    _filename = filename;
    auto result = Read();

    if (result.IsSuccess() == false) {
        return Result<std::string>(false);
    }

    return result;
};

Result<std::string> ConfigFileReader::Read() const noexcept {
    try
    {
        auto lines = TryRead();
        return Result<std::string>(std::move(lines));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return Result<std::string>(false);
    }
};

std::string ConfigFileReader::TryRead() const {
    
};
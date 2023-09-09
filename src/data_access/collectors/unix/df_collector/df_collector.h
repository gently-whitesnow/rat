#pragma once
#include <data_access/collectors/collector.h>
#include <data_access/collectors/unix/system_executor.h>

#include <string>
#include <vector>

class DfCollector : public ICollector {
   public:
    DfCollector(int collectionSecondsInterval, std::string collectorName,
                std::vector<std::string> discNames);

    DfCollector(int collectionSecondsInterval, std::string collectorName);

    Result<std::unique_ptr<IDto>> Collect() override;

   private:
    std::string GetFilteredString(const std::string& rawString);
    SystemExecutor _systemExecutor;
    std::string _command = "df -h";
    std::vector<std::string> _discNames;
};
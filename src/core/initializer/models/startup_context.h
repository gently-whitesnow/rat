#pragma once

#include <vector>
#include <memory>

#include <data_access/collectors/collector.h>
#include <data_access/senders/sender.h>

class StartUpContext {
private:
    std::vector<std::unique_ptr<ISender>> _senders;
    std::vector<std::unique_ptr<ICollector>> _collectors;
public:
    void AddSender(const std::unique_ptr<ISender>&& sender) noexcept;
    void AddCollector(const std::unique_ptr<ICollector>&& collector) noexcept;

    std::vector<std::unique_ptr<ISender>>& GetSenders() noexcept const;
    std::vector<std::unique_ptr<ICollector>>& GetCollectors() noexcept const;
};
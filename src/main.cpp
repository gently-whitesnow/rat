#include <data_access/collectors/base_collector.h>
#include <data_access/collectors/example_collector/example_collector.h>
#include <data_access/collectors/unix/df_collector/df_collector.h>
#include <data_access/senders/example_sender/example_sender.h>
#include <data_access/senders/sender.h>

#include <iostream>
#include <vector>

#include "core/worker/worker.h"

using namespace std;

int main() {
    cout << "Starting program" << endl;

    // Initializer initializer;

    // throw exception if configuration error
    // initializer.build();

    std::vector<std::unique_ptr<BaseCollector>> collectors;
    std::vector<std::unique_ptr<ISender>> senders;

    std::vector<std::string> discNames{"/dev/disk3s5", "/dev/disk3s2"};

    collectors.emplace_back(std::make_unique<ExampleCollector>(10, "Example collector"));
    collectors.emplace_back(std::make_unique<DfCollector>(5, "Disc space", std::move(discNames)));
    senders.emplace_back(std::make_unique<ExampleSender>());

    // no exceptions, try catch and logging to console and file?
    Worker worker(std::move(collectors), std::move(senders));
    worker.Run();
}
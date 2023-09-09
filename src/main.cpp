#include <data_access/collectors/collector.h>
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

    std::vector<std::unique_ptr<ICollector>> collectors;
    std::vector<std::unique_ptr<ISender>> senders;

    std::unique_ptr<ExampleCollector> exampleCollector = std::make_unique<ExampleCollector>(10, "Example collector");

    std::vector<std::string> discNames{"/dev/disk3s5", "/dev/disk3s2"};
    std::unique_ptr<DfCollector> dfCollector = std::make_unique<DfCollector>(5, "Disc space", discNames);

    std::unique_ptr<ExampleSender> exampleSender = std::make_unique<ExampleSender>();
    collectors.push_back(std::move(exampleCollector));
    collectors.push_back(std::move(dfCollector));
    senders.push_back(std::move(exampleSender));

    // no exceptions, try catch and logging to console and file?
    Worker worker(std::move(collectors), std::move(senders));
    worker.Run();
}
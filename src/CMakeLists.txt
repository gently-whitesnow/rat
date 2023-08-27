project(rat)
file(GLOB_RECURSE all_headers LIST_DIRECTORIES FALSE "*.h")

add_executable(rat)

target_sources(rat PRIVATE
    ${all_headers}
    core/worker/worker.cpp
    data_access/collectors/example_collector/example_collector.cpp
    data_access/collectors/i_collector.cpp
    data_access/senders/example_sender/example_sender.cpp
    main.cpp
)

target_include_directories(rat PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
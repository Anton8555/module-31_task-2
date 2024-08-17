cmake_minimum_required(VERSION 3.8)

add_executable("module-30_task-2"
    main.cpp
    shared_ptr_toy.cpp
    toy.cpp
)

target_include_directories("module-30_task-2" PUBLIC ${MY_INCLUDE_DIR})

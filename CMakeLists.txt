cmake_minimum_required(VERSION 3.16)

project(c_command_parser C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_executable(command_parser_example
    examples/main.c
    src/command_parser.c
    src/device_state.c
)

add_executable(test_command_parser
    tests/test_command_parser.c
    src/command_parser.c
    src/device_state.c
)
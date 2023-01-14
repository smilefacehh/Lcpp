cmake_minimum_required(VERSION 3.0.0)
project(Lcpp)

set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wall -Werror -Wno-error=unused-variable -O3)

add_subdirectory(state_machine)
cmake_minimum_required(VERSION 3.0.2)
project(lcpp)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-w -Wall -Werror -Wno-error=unused-variable -O3)

find_package(OpenCV 4 REQUIRED)

include_directories(
    src
    ${OpenCV_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME} SHARED
    src/raytracing/raytracing.cc
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    ${OpenCV_LIBS}
)

add_executable(raytracing_test src/examples/raytracing_test.cc)
target_link_libraries(raytracing_test ${PROJECT_NAME} )

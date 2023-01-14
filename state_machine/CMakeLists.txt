message("-- Add state_machine")

file(GLOB_RECURSE SOURCE_FILES ${PROJECT_SOURCE_DIR}/state_machine/*.h ${PROJECT_SOURCE_DIR}/state_machine/*.cpp)
add_library(state_machine STATIC ${SOURCE_FILES})
add_executable(state_machine_example state_machine_example.cpp)
target_link_libraries(state_machine_example state_machine)

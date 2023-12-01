cmake_minimum_required(VERSION 3.27.9)

project(textadventure CXX)

add_executable(${PROJECT_NAME} "src/main.cpp")
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

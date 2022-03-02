cmake_minimum_required(VERSION 3.13)

# Project setup
project(CommandDefense VERSION 1.0)

add_executable(CommandDefense main.cpp)

target_include_directories(CommandDefense PUBLIC ../AppCUI)
target_link_libraries(CommandDefense PUBLIC AppCUI)




cmake_minimum_required(VERSION 2.6)
project(MinecraftExample)

include_directories(../../include)

add_executable(MinecraftExample MinecraftExample.cc)
target_link_libraries(MinecraftExample RakNetShared)

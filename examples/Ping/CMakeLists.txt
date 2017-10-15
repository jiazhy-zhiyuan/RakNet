cmake_minimum_required(VERSION 2.6)
project(Ping)

include_directories(../../include)

add_executable(Ping Ping.cc)
target_link_libraries(Ping RakNetShared)

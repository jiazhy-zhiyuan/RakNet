cmake_minimum_required(VERSION 2.6)
project(PacketLoggerTest)

include_directories(../../include)

add_executable(PacketLoggerTest PacketLoggerTest.cc)
target_link_libraries(PacketLoggerTest RakNetShared)

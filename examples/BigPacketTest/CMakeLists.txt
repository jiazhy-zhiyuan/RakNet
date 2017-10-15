cmake_minimum_required(VERSION 2.6)
project(BigPacketTest)

include_directories(../../include)

add_executable(BigPacketTest BigPacketTest.cc)
target_link_libraries(BigPacketTest RakNetShared)

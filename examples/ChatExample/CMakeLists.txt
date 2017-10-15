cmake_minimum_required(VERSION 2.6)
project(ChatExample)

include_directories(../../include)

add_executable(ChatServer ChatExampleServer.cc)
add_executable(ChatClient ChatExampleClient.cc)
target_link_libraries(ChatServer RakNetShared)
target_link_libraries(ChatClient RakNetShared)

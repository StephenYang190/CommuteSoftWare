cmake_minimum_required(VERSION 3.17)
project(server_system)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

link_libraries(ws2_32 wsock32)

add_executable(server_system serve.cpp ClioneData.h ClioneData.cpp MssPrss.cpp MssPrss.h)
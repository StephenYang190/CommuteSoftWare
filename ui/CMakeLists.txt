cmake_minimum_required(VERSION 3.17)
project(ui)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "D:\\ruanjian\\Qt\\Qt5.9.0\\5.9\\mingw53_32")

find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(build-qqclient-Desktop_Qt_5_9_0_MinGW_32bit-Debug)
include_directories(build-qqclient-Desktop_Qt_5_9_0_MinGW_32bit-Debug/debug)
include_directories(qqclient)

add_executable(ui
        build-qqclient-Desktop_Qt_5_9_0_MinGW_32bit-Debug/debug/moc_cw.cpp
        build-qqclient-Desktop_Qt_5_9_0_MinGW_32bit-Debug/debug/moc_mainwindow.cpp
        build-qqclient-Desktop_Qt_5_9_0_MinGW_32bit-Debug/debug/moc_networksocket.cpp
        build-qqclient-Desktop_Qt_5_9_0_MinGW_32bit-Debug/debug/moc_predefs.h
        build-qqclient-Desktop_Qt_5_9_0_MinGW_32bit-Debug/ui_cw.h
        build-qqclient-Desktop_Qt_5_9_0_MinGW_32bit-Debug/ui_mainwindow.h
        qqclient/cw.cpp
        qqclient/cw.h
        qqclient/main.cpp
        qqclient/mainwindow.cpp
        qqclient/mainwindow.h
        qqclient/message.cpp
        qqclient/message.h
        qqclient/networksocket.cpp
        qqclient/networksocket.h
        qqclient/cw.ui
        qqclient/qqclient.pro)

target_link_libraries(ui Qt5::Widgets)
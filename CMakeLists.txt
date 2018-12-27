cmake_minimum_required(VERSION 3.1.0)

project(SPIMlab)

include_directories(${INCLUDE_DIRS})
message(STATUS "Custom include directories: ${INCLUDE_DIRS}")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_STANDARD 11)

option(DEMO_MODE "Demo mode: simulate hardware" OFF)

if (NOT DEMO_MODE)
    add_definitions(-DWITH_HARDWARE)
else ()
    message(AUTHOR_WARNING "Configuring in DEMO mode")
endif ()

find_package(Qt5Widgets REQUIRED)
find_package(Qwt REQUIRED)
find_package(NIDAQmx REQUIRED NOT DEMO_MODE)
find_package(DCAMAPI REQUIRED NOT DEMO_MODE)

include_directories(${Qwt_INCLUDE_DIR} ${DCAMAPI_INCLUDE_DIR})

if (UNIX)
    add_definitions(-DLINUX)  # needed for DCAM-API
endif ()

add_subdirectory(src)
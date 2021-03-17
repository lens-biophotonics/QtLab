option(BUILD_SERIAL "Build serial" ON)
if(NOT BUILD_SERIAL)
    return()
endif()

find_package(Qt5 COMPONENTS SerialPort REQUIRED)

set(CMAKE_AUTOMOC ON)

set(TARGETNAME qtlab-hw-serial)
set(EXPORT_NAME Serial)


set(SOURCE_FILES
    serialport.cpp
    serialdevice.cpp

    cobolt.cpp

    filterwheel.cpp
)

set(HEADERS
    serialport.h
    serialdevice.h
    cobolt.h

    filterwheel.h
)

add_library(${TARGETNAME} SHARED ${SOURCE_FILES})

target_link_libraries(${TARGETNAME}
    PUBLIC
        Qt5::SerialPort
        qtlab-core
)
include(install_targets)

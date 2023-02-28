option(BUILD_SERIAL "Build serial" ON)
if(NOT BUILD_SERIAL)
    return()
endif()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS SerialPort)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS SerialPort)

set(CMAKE_AUTOMOC ON)

set(TARGETNAME qtlab-hw-serial)
set(EXPORT_NAME Serial)


set(SOURCE_FILES
    serialport.cpp
    serialdevice.cpp

    cobolt.cpp
    filterwheel.cpp
    AA_MPDSnCxx.cpp
)

set(HEADERS
    serialport.h
    serialdevice.h

    cobolt.h
    filterwheel.h
    AA_MPDSnCxx.h
)

add_library(${TARGETNAME} SHARED ${SOURCE_FILES})

target_link_libraries(${TARGETNAME}
    PUBLIC
        Qt${QT_VERSION_MAJOR}::SerialPort
        qtlab-core
)
set(${TARGETNAME}_GEN_EXPORT_HEADER TRUE)
include(install_targets)

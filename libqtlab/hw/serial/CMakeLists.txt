find_package(Qt5 COMPONENTS SerialPort REQUIRED)

set(CMAKE_AUTOMOC ON)

set(TARGETNAME qtlab-hw-serial)
add_library(${TARGETNAME} SHARED)

target_sources(${TARGETNAME}
    PRIVATE
        serialport.cpp

        cobolt.cpp

        filterwheel.cpp
)

set(HEADERS
    serialport.h

    cobolt.h

    filterwheel.h
)

target_link_libraries(${TARGETNAME} PRIVATE
    Qt5::SerialPort
    qtlab-core
)

target_include_directories(${TARGETNAME} PRIVATE ${LIBQTLAB_INCLUDE_DIR})

set(EXPORT_NAME Serial)
include(install_targets)

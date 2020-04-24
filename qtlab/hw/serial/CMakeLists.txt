find_package(Qt5 COMPONENTS SerialPort REQUIRED)

set(CMAKE_AUTOMOC ON)

set(TARGETNAME qtlab-hw-serial)
set(EXPORT_NAME Serial)


set(SOURCE_FILES
    serialport.cpp

    cobolt.cpp

    filterwheel.cpp
)

set(HEADERS
    serialport.h

    cobolt.h

    filterwheel.h
)

add_library(${TARGETNAME} SHARED ${SOURCE_FILES})
set_target_properties(${TARGETNAME} PROPERTIES EXPORT_NAME ${EXPORT_NAME})

target_link_libraries(${TARGETNAME} PRIVATE
    Qt5::SerialPort
    qtlab-core
)

target_include_directories(${TARGETNAME} PRIVATE ${QTLAB_INCLUDE_DIR})

include(install_targets)

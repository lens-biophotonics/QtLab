find_package(PIGCS)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS SerialPort)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS SerialPort)

set(TARGETNAME qtlab-hw-pi)
set(EXPORT_NAME PI)

CMAKE_DEPENDENT_OPTION(QTLAB_PI_DEMO "PI DEMO" ON "QTLAB_DEMO" OFF)

if(NOT PIGCS_INCLUDE_DIR)
    message("Could not find ${PIGCS_LIBNAME_STR} headers. "
            "Library ${TARGETNAME} will not be built.")
    return()
endif()

set(SOURCEFILES
    pidaisychain.cpp
    pidevice.cpp
)

set(HEADERS
    pidaisychain.h
    pidevice.h
)

add_library(${TARGETNAME} SHARED ${SOURCEFILES})

target_link_libraries(${TARGETNAME} PUBLIC
    Qt${QT_VERSION_MAJOR}::SerialPort
    qtlab-core
)
target_include_directories(${TARGETNAME} PUBLIC
    ${PIGCS_INCLUDE_DIR}
)
if(UNIX)
    target_compile_definitions(${TARGETNAME} PRIVATE LINUX)
endif()

if(PIGCS_FOUND)
    set(QTLAB_HW_PI TRUE PARENT_SCOPE)
    target_link_libraries(${TARGETNAME} PUBLIC ${PIGCS_LIBRARY})
    if(NOT QTLAB_PI_DEMO)
        target_compile_definitions(${TARGETNAME} PRIVATE WITH_HARDWARE)
    endif()
else()
    message("Could not find ${PIGCS_LIBNAME_STR}. "
            "Library ${TARGETNAME} will be built in demo mode.")
endif()

set(${TARGETNAME}_GEN_EXPORT_HEADER TRUE)
include(install_targets)

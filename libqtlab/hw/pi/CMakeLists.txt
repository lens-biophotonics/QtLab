find_package(PIGCS)
find_package(Qt5 COMPONENTS SerialPort REQUIRED)

set(TARGETNAME qtlab-hw-pi)

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
target_link_libraries(${TARGETNAME} PRIVATE
    Qt5::SerialPort
    qtlab-core
)
target_include_directories(${TARGETNAME} PRIVATE
    ${PIGCS_INCLUDE_DIR}
    ${LIBQTLAB_INCLUDE_DIR}
)
target_compile_definitions(${TARGETNAME} PRIVATE PIGCS_HEADERS)

if(UNIX)
    target_compile_definitions(${TARGETNAME} PRIVATE LINUX)
endif()

if(PIGCS_FOUND)
    target_link_libraries(${TARGETNAME} PRIVATE ${PIGCS_LIBRARY})
    target_compile_definitions(${TARGETNAME} PRIVATE WITH_HARDWARE)
else()
    message("Could not find ${PIGCS_LIBNAME_STR}. "
            "Library ${TARGETNAME} will be built in demo mode.")
endif()

set(EXPORT_NAME PI)
include(install_targets)

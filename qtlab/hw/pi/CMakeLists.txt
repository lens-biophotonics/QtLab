find_package(PIGCS)
find_package(Qt5 COMPONENTS SerialPort REQUIRED)

set(TARGETNAME qtlab-hw-pi)
set(EXPORT_NAME PI)

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
set_target_properties(${TARGETNAME} PROPERTIES EXPORT_NAME ${EXPORT_NAME})

target_link_libraries(${TARGETNAME} PRIVATE
    Qt5::SerialPort
    qtlab-core
)
target_include_directories(${TARGETNAME} PRIVATE
    ${PIGCS_INCLUDE_DIR}
    ${QTLAB_INCLUDE_DIR}
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

include(install_targets)
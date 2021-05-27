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

target_link_libraries(${TARGETNAME} PUBLIC
    Qt5::SerialPort
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
    target_compile_definitions(${TARGETNAME} PRIVATE WITH_HARDWARE)
else()
    message("Could not find ${PIGCS_LIBNAME_STR}. "
            "Library ${TARGETNAME} will be built in demo mode.")
endif()

set(${TARGETNAME}_GEN_EXPORT_HEADER TRUE)
include(install_targets)

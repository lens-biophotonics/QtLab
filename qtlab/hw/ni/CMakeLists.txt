find_package(NIDAQmx)
set(EXPORT_NAME NI)

set(TARGETNAME qtlab-hw-ni)

if(NOT NIDAQMX_INCLUDE_DIR)
    message("Could not find ${NIDAQMX_LIBNAME_STR} headers. "
            "Library ${TARGETNAME} will not be built.")
    return()
endif()

set(SOURCEFILES
    natinst.cpp
    niabstracttask.cpp
)

set(HEADERS
    natinst.h
    niabstracttask.h
)

add_library(${TARGETNAME} SHARED ${SOURCEFILES})
set_target_properties(${TARGETNAME} PROPERTIES EXPORT_NAME ${EXPORT_NAME})

target_link_libraries(${TARGETNAME} PRIVATE
    qtlab-core
)
target_include_directories(${TARGETNAME}
    PUBLIC
        ${NIDAQMX_INCLUDE_DIR}
    PRIVATE
        ${QTLAB_INCLUDE_DIR}
)

if(UNIX)
    target_compile_definitions(${TARGETNAME} PRIVATE LINUX)
endif()

if(NIDAQMX_FOUND)
    target_link_libraries(${TARGETNAME} PRIVATE ${NIDAQMX_LIBRARY})
    target_compile_definitions(${TARGETNAME} PRIVATE WITH_HARDWARE)
else()
    message("Could not find ${NIDAQMX_LIBNAME_STR}. "
            "Library ${TARGETNAME} will be built in demo mode.")
endif()

include(install_targets)

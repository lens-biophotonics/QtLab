find_package(NIDAQmx)

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

add_library(${TARGETNAME} SHARED ${SOURCEFILES})
target_link_libraries(${TARGETNAME}
    qtlab-core
)
target_include_directories(${TARGETNAME} PRIVATE
    ${NIDAQMX_INCLUDE_DIR}
    ${LIBQTLAB_INCLUDE_DIR}
)
target_compile_definitions(${TARGETNAME} PRIVATE NIDAQMX_HEADERS)

if(UNIX)
    target_compile_definitions(${TARGETNAME} PRIVATE LINUX)
endif()

if(NIDAQMX_FOUND)
    target_link_libraries(${TARGETNAME} ${NIDAQMX_LIBRARY})
    target_compile_definitions(${TARGETNAME} PRIVATE WITH_HARDWARE)
else()
    message("Could not find ${NIDAQMX_LIBNAME_STR}. "
            "Library ${TARGETNAME} will be built in demo mode.")
endif()

find_package(DCAMAPI)

set(TARGETNAME qtlab-hw-hamamatsu)

if(NOT DCAMAPI_INCLUDE_DIR)
    message("Could not find ${DCAMAPI_LIBNAME_STR} headers."
            "Library ${TARGETNAME} will not be built.")
    return()
endif()

set(SOURCEFILES
    dcamutils.cpp
    orcaflash.cpp
)

set(HEADERS
    dcamutils.h
    orcaflash.h
)

add_library(${TARGETNAME} SHARED ${SOURCEFILES})
target_link_libraries(${TARGETNAME} PRIVATE
    qtlab-core
)
target_include_directories(${TARGETNAME} PRIVATE
    ${DCAMAPI_INCLUDE_DIR}
    ${LIBQTLAB_INCLUDE_DIR}
)
target_compile_definitions(${TARGETNAME} PRIVATE DCAMAPI_HEADERS)

if(UNIX)
    target_compile_definitions(${TARGETNAME} PRIVATE LINUX)
endif()

if(DCAMAPI_FOUND)
    target_link_libraries(${TARGETNAME} PRIVATE ${DCAMAPI_LIBRARY})
    target_compile_definitions(${TARGETNAME} PRIVATE WITH_HARDWARE)
else()
    message("Could not find ${DCAMAPI_LIBNAME_STR}. "
            "Library ${TARGETNAME} will be built in demo mode.")
endif()

set(EXPORT_NAME Hamamatsu)
include(install_targets)

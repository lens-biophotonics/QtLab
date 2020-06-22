include(CMakeDependentOption)

find_package(DCAMAPI)
set(EXPORT_NAME Hamamatsu)

set(TARGETNAME qtlab-hw-hamamatsu)

CMAKE_DEPENDENT_OPTION(QTLAB_DCAM_DEMO "DCAM DEMO" ON "QTLAB_DEMO" OFF)

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
set_target_properties(${TARGETNAME} PROPERTIES EXPORT_NAME ${EXPORT_NAME})

target_link_libraries(${TARGETNAME} PUBLIC
    qtlab-core
)
target_include_directories(${TARGETNAME}
    PUBLIC
        ${DCAMAPI_INCLUDE_DIR}
)
target_compile_definitions(${TARGETNAME} PRIVATE DCAMAPI_HEADERS)

if(UNIX)
    target_compile_definitions(${TARGETNAME} PRIVATE LINUX)
endif()

if(DCAMAPI_FOUND)
    target_link_libraries(${TARGETNAME} PUBLIC ${DCAMAPI_LIBRARY})
    target_compile_definitions(${TARGETNAME} PRIVATE WITH_HARDWARE)
else()
    message("Could not find ${DCAMAPI_LIBNAME_STR}. "
            "Library ${TARGETNAME} will be built in demo mode.")
endif()

if(${QTLAB_DCAM_DEMO} OR NOT ${DCAMAPI_FOUND})
    target_compile_definitions(${TARGETNAME} PUBLIC QTLAB_DCAM_DEMO)
endif()

set(${TARGETNAME}_GEN_EXPORT_HEADER TRUE)
include(install_targets)

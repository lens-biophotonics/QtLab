find_package(Aravis)
set(EXPORT_NAME Aravis)

set(TARGETNAME qtlab-hw-aravis)

if(NOT ARAVIS_FOUND)
    message("Could not find ${ARAVIS_LIBNAME_STR}. "
            "Library ${TARGETNAME} will not be built.")
    return()
endif()

set(SOURCE_FILES
    aravis.cpp
)

set(HEADERS
    aravis.h
)

add_library(${TARGETNAME} SHARED ${SOURCE_FILES})
set_target_properties(${TARGETNAME} PROPERTIES EXPORT_NAME ${EXPORT_NAME})

target_link_libraries(${TARGETNAME}
    INTERFACE
        ${ARAVIS_LIBRARIES}
    PUBLIC
        qtlab-core
)
target_include_directories(${TARGETNAME}
    PUBLIC
        ${ARAVIS_INCLUDE_DIR}
)

include(install_targets)

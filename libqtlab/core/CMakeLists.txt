set(TARGETNAME qtlab-core)
add_library(${TARGETNAME} SHARED)

target_sources(${TARGETNAME}
    PRIVATE
        logger.cpp
        logmanager.cpp
)

set(HEADERS
    logger.h
    logmanager.h
)

target_link_libraries(${TARGETNAME} PUBLIC
    Qt5::Core
)
target_include_directories(${TARGETNAME} PRIVATE ${LIBQTLAB_INCLUDE_DIR})

set(EXPORT_NAME Core)
include(install_targets)

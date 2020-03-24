set(TARGETNAME qtlab-core)
set(EXPORT_NAME Core)

add_library(${TARGETNAME} SHARED)
set_target_properties(${TARGETNAME} PROPERTIES EXPORT_NAME ${EXPORT_NAME})

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
target_include_directories(${TARGETNAME} PRIVATE ${QTLAB_INCLUDE_DIR})

include(install_targets)

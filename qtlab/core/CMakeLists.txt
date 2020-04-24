set(TARGETNAME qtlab-core)
set(EXPORT_NAME Core)

set(SOURCE_FILES
    logger.cpp
    logmanager.cpp
)

set(HEADERS
    logger.h
    logmanager.h
)

add_library(${TARGETNAME} SHARED ${SOURCE_FILES})
set_target_properties(${TARGETNAME} PROPERTIES EXPORT_NAME ${EXPORT_NAME})

target_link_libraries(${TARGETNAME} PUBLIC
    Qt5::Core
)

include(install_targets)

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

target_link_libraries(${TARGETNAME} PUBLIC
    Qt5::Core
)

set(${TARGETNAME}_GEN_EXPORT_HEADER TRUE)
include(install_targets)

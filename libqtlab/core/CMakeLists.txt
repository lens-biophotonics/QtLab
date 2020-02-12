set(TARGETNAME qtlab-core)
add_library(${TARGETNAME} SHARED)

target_sources(${TARGETNAME}
    PRIVATE
        logger.cpp
        logmanager.cpp
)

target_link_libraries(${TARGETNAME}
    Qt5::Core
)
target_include_directories(${TARGETNAME} PRIVATE
    ${LIBQTLAB_INCLUDE_DIR}
)


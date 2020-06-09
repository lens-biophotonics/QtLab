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

if(WIN32)
    include(GenerateExportHeader)
    generate_export_header(${TARGETNAME})
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${TARGETNAME}_export.h
            DESTINATION
                ${CMAKE_INSTALL_INCLUDEDIR}/${HEADER_PREFIX}
            COMPONENT
                devel
    )
    target_include_directories(${TARGETNAME}
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    )
endif()

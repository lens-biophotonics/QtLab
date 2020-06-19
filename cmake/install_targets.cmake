get_filename_component(PARENT_DIR ${CMAKE_PARENT_LIST_FILE} DIRECTORY)

file(RELATIVE_PATH HEADER_PREFIX
    ${PROJECT_SOURCE_DIR} ${PARENT_DIR})

set(EXPORT_NAME "${EXPORT_NAME}Targets")

install(TARGETS ${TARGETNAME} DESTINATION ${CMAKE_INSTALL_LIBDIR}
    EXPORT ${EXPORT_NAME}
    COMPONENT ${COMPONENT}
)

install(
  EXPORT ${EXPORT_NAME}
  NAMESPACE QtLab::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QtLab
)

install(FILES ${HEADERS}
        DESTINATION
            ${CMAKE_INSTALL_INCLUDEDIR}/${HEADER_PREFIX}
        COMPONENT
            devel
)

target_include_directories(${TARGETNAME}
    PUBLIC
        $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
)

if(${${TARGETNAME}_GEN_EXPORT_HEADER})
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

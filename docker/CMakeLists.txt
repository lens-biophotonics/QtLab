find_program(Docker_EXECUTABLE docker)

set(TARGETNAME qtlab_wrappers_builder)

add_custom_target(${TARGETNAME} SOURCES Dockerfile
    COMMAND ${Docker_EXECUTABLE} build --tag ${TARGETNAME} ${CMAKE_CURRENT_LIST_DIR}
)

set_target_properties(${TARGETNAME} PROPERTIES EXCLUDE_FROM_ALL TRUE)

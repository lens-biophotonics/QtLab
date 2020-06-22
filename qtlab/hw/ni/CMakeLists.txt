find_package(NIDAQmx)
set(EXPORT_NAME NI)

set(TARGETNAME qtlab-hw-ni)

if(NOT NIDAQMX_INCLUDE_DIR)
    message("Could not find ${NIDAQMX_LIBNAME_STR} headers. "
            "Library ${TARGETNAME} will not be built.")
    return()
endif()

set(SOURCEFILES
    natinst.cpp
    nitask.cpp
)

set(HEADERS
    natinst.h
    nitask.h
    ${CMAKE_CURRENT_BINARY_DIR}/NIDAQmx_wrapper_methods.h
)

add_library(${TARGETNAME} SHARED ${SOURCEFILES} ${CMAKE_CURRENT_BINARY_DIR}/NIDAQmx_wrapper_methods.h)

target_link_libraries(${TARGETNAME} PUBLIC
    qtlab-core
)
target_include_directories(${TARGETNAME}
    PUBLIC
        ${NIDAQMX_INCLUDE_DIR}
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)

if(UNIX)
    target_compile_definitions(${TARGETNAME} PRIVATE LINUX)
endif()

if(NIDAQMX_FOUND)
    target_link_libraries(${TARGETNAME} PRIVATE ${NIDAQMX_LIBRARY})
    target_compile_definitions(${TARGETNAME} PRIVATE WITH_HARDWARE)
else()
    message("Could not find ${NIDAQMX_LIBNAME_STR}. "
            "Library ${TARGETNAME} will be built in demo mode.")
endif()

find_program(docker_EXECUTABLE docker)
find_program(spatch_EXECUTABLE spatch)

set(WRAPPER_COMMAND_OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/NIDAQmx_dummy.cpp ${CMAKE_CURRENT_BINARY_DIR}/NIDAQmx_wrapper_methods.cpp ${CMAKE_CURRENT_BINARY_DIR}/NIDAQmx_wrapper_methods.h)
set(WRAPPER_COMMAND_DEPENDS generate_wrappers.sh wrapper.cocci)

if(spatch_EXECUTABLE)
    message(STATUS "Found coccinelle: ${spatch_EXECUTABLE}")
    set(WRAPPER_COMMAND ./generate_wrappers.sh ${NIDAQMX_INCLUDE_DIR}/NIDAQmx.h ${CMAKE_CURRENT_BINARY_DIR})
else()
    if(docker_EXECUTABLE)
        message(STATUS "Found docker: ${docker_EXECUTABLE}")
        set(WRAPPER_COMMAND docker run --name qtlab_wrappers_builder --rm -v ${CMAKE_CURRENT_LIST_DIR}:/home -v ${NIDAQMX_INCLUDE_DIR}/NIDAQmx.h:/NIDAQmx.h -v ${CMAKE_CURRENT_BINARY_DIR}:/output qtlab_wrappers_builder generate_wrappers.sh /NIDAQmx.h /output)
        set(WRAPPER_COMMAND_DEPENDS qtlab_wrappers_builder ${WRAPPER_COMMAND_DEPENDS})
    else()
        message(WARNING "Neither docker nor spatch found. You need to copy generated wrappers in ${CMAKE_CURRENT_LIST_DIR}")
        set(FILES_TO_BE_COPIED ${CMAKE_CURRENT_LIST_DIR}/NIDAQmx_dummy.cpp ${CMAKE_CURRENT_LIST_DIR}/NIDAQmx_wrapper_methods.cpp ${CMAKE_CURRENT_LIST_DIR}/NIDAQmx_wrapper_methods.h)
        set(WRAPPER_COMMAND COMMAND ${CMAKE_COMMAND} -E copy ${FILES_TO_BE_COPIED} ${CMAKE_CURRENT_BINARY_DIR})
        set(WRAPPER_COMMAND_DEPENDS ${FILES_TO_BE_COPIED})
    endif()
endif()

add_custom_command(
    OUTPUT ${WRAPPER_COMMAND_OUTPUT}
    COMMENT "Generating wrappers for NIDAQmx.h. This may take some time."
    COMMAND ${WRAPPER_COMMAND}
    DEPENDS ${WRAPPER_COMMAND_DEPENDS}
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
)

set_property(SOURCE ${WRAPPER_COMMAND_OUTPUT} PROPERTY SKIP_AUTOMOC ON)

include(install_targets)

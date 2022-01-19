find_package(Qt5 5.8 REQUIRED COMPONENTS
    Widgets
)

find_package(Qwt)
find_package(Qt5 5.8 COMPONENTS SerialPort)

set(TARGETNAME qtlab-pi-widgets)
set(EXPORT_NAME PI-Widgets)


add_library(${TARGETNAME} SHARED ${SOURCE_FILES})
target_include_directories(${TARGETNAME}
    PUBLIC
        ${Qwt_INCLUDE_DIR}
)

if(WIN32)
    target_compile_definitions(${TARGETNAME} PUBLIC QWT_DLL)
endif()

if (QTLAB_HW_PI)
    set(SOURCE_FILES ${SOURCE_FILES}
        picontrollersettingswidget.cpp
        pipositioncontrolwidget.cpp
    )
    target_link_libraries(${TARGETNAME}
        PUBLIC
            qtlab-hw-pi
    )
else()
    message("Could not find PIGCS. PI widgets will not be built")
    return()
endif()

target_sources(${TARGETNAME} PRIVATE ${SOURCE_FILES})

set(HEADERS
    picontrollersettingswidget.h
    pipositioncontrolwidget.h
)

target_link_libraries(${TARGETNAME}
    PUBLIC
        Qt5::Widgets
        qtlab-core
        qtlab-widgets
)

set(${TARGETNAME}_GEN_EXPORT_HEADER TRUE)
include(install_targets)

set(TARGETNAME qtlab-pi-widgets)
set(EXPORT_NAME PI-Widgets)


add_library(${TARGETNAME} SHARED ${SOURCE_FILES})

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
        qtlab-core
        qtlab-widgets
)

set(${TARGETNAME}_GEN_EXPORT_HEADER TRUE)
include(install_targets)

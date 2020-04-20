find_package(Qt5 5.8 REQUIRED COMPONENTS
    Widgets
)

find_package(Qwt)

set(TARGETNAME qtlab-widgets)
set(EXPORT_NAME Widgets)

set(SOURCE_FILES
    aspectratiowidget.cpp
    colormaps.cpp
    customspinbox.cpp
)

add_library(${TARGETNAME} SHARED ${SOURCE_FILES})
set_target_properties(${TARGETNAME} PROPERTIES EXPORT_NAME ${EXPORT_NAME})
target_include_directories(${TARGETNAME}
    PUBLIC
        ${Qwt_INCLUDE_DIR}
)


if (Qwt_FOUND)
    set(SOURCE_FILES ${SOURCE_FILES} cameradisplay.cpp cameraplot.cpp)
else()
    message("Could not find Qwt. Camera widgets will not be built")
endif()

target_sources(${TARGETNAME} PRIVATE ${SOURCE_FILES})

set(HEADERS
    aspectratiowidget.h
    cameradisplay.h
    cameraplot.h

    colormaps.h
    customspinbox.h
)

target_link_libraries(${TARGETNAME}
    PUBLIC
        Qt5::Widgets
        ${Qwt_LIBRARY}
        qtlab-core
)

include(install_targets)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

find_package(Qwt)

set(TARGETNAME qtlab-widgets)
set(EXPORT_NAME Widgets)

set(SOURCE_FILES
    aspectratiowidget.cpp
    pixmapwidget.cpp
    colormaps.cpp
    customspinbox.cpp
    logwidget.cpp
)

add_library(${TARGETNAME} SHARED ${SOURCE_FILES})
target_include_directories(${TARGETNAME}
    PUBLIC
        ${Qwt_INCLUDE_DIR}
)

if(WIN32)
    target_compile_definitions(${TARGETNAME} PUBLIC QWT_DLL)
endif()

if (Qwt_FOUND)
    set(SOURCE_FILES ${SOURCE_FILES} cameradisplay.cpp cameraplot.cpp timeplot.cpp)
    target_link_libraries(${TARGETNAME}
        PUBLIC
        ${Qwt_LIBRARY}
        )
else()
    message("Could not find Qwt. Some widgets will not be built")
endif()

target_sources(${TARGETNAME} PRIVATE ${SOURCE_FILES})

set(HEADERS
    aspectratiowidget.h
    pixmapwidget.h
    cameradisplay.h
    cameraplot.h
    timeplot.h

    colormaps.h
    customspinbox.h

    logwidget.h
)

target_link_libraries(${TARGETNAME}
    PUBLIC
        Qt${QT_VERSION_MAJOR}::Widgets
        qtlab-core
)

set(${TARGETNAME}_GEN_EXPORT_HEADER TRUE)
include(install_targets)

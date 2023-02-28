find_package(TIFF)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

set(TARGETNAME qtlab-io)
set(EXPORT_NAME IO)

if(NOT TIFF_FOUND)
    message(STATUS "${TARGETNAME} will not be built.")
    return()
endif()

set(SOURCEFILES
    tiffwriter.cpp
)

set(HEADERS
    tiffwriter.h
)

add_library(${TARGETNAME} SHARED ${SOURCEFILES})

target_link_libraries(${TARGETNAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    qtlab-core
    TIFF::TIFF
)

include(install_targets)

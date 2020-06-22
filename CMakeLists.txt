cmake_minimum_required(VERSION 3.1.0)

project(QtLab)

find_package(Qt5 5.8 REQUIRED COMPONENTS
    Core
)

message(STATUS "Custom include directories: ${INCLUDE_DIRS}")

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options("/std:c++latest")
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
else()
    set(CMAKE_CXX_STANDARD 14)
endif()

set(CMAKE_AUTOMOC ON)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

set(OTHER_FILES
    .gitignore
    uncrustify.cfg
    LICENSE.txt
    README.md
)

add_custom_target(project-related-files SOURCES ${OTHER_FILES})

include(GNUInstallDirs)

option(BUILD_WIDGETS "Build widgets" ON)
option(QTLAB_DEMO "Demo mode" OFF)

add_subdirectory(qtlab/core)
add_subdirectory(qtlab/hw/hamamatsu)
add_subdirectory(qtlab/hw/ni)
add_subdirectory(qtlab/hw/pi)
add_subdirectory(qtlab/hw/serial)

if(BUILD_WIDGETS)
    add_subdirectory(qtlab/widgets)
endif()

add_subdirectory(docker)

include(CMakePackageConfigHelpers)
configure_package_config_file(
  "Config.cmake.in"
  "QtLabConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QtLab
  PATH_VARS
    CMAKE_INSTALL_LIBDIR
)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/QtLabConfigVersion.cmake
  VERSION 0.0.1
  COMPATIBILITY SameMajorVersion
)

### Install Config and ConfigVersion files
install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/QtLabConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/QtLabConfigVersion.cmake"
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/QtLab"
)

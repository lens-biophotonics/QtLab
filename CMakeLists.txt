cmake_minimum_required(VERSION 3.1.0)

project(libqtlab)

find_package(Qt5 5.8 REQUIRED COMPONENTS
    Core
)

message(STATUS "Custom include directories: ${INCLUDE_DIRS}")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
set(LIBQTLAB_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(OTHER_FILES
    .gitignore
    uncrustify.cfg
    LICENSE.txt
)

set(CMAKE_AUTOMOC ON)

include(GNUInstallDirs)

add_subdirectory(libqtlab/core)
add_subdirectory(libqtlab/hw/hamamatsu)
add_subdirectory(libqtlab/hw/ni)
add_subdirectory(libqtlab/hw/pi)
add_subdirectory(libqtlab/hw/serial)

include(CMakePackageConfigHelpers)
configure_package_config_file(
  "Config.cmake.in"
  "libqtlabConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/libqtlab
  PATH_VARS
    CMAKE_INSTALL_LIBDIR
)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/libqtlabConfigVersion.cmake
  VERSION 0.0.1
  COMPATIBILITY SameMajorVersion
)

### Install Config and ConfigVersion files
install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/libqtlabConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/libqtlabConfigVersion.cmake"
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/libqtlab"
)

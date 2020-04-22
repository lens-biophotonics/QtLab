set(ARAVIS_LIBNAME_STR "Aravis")
set(ARAVIS_LIBRARY_NAMES aravis-0.8)

find_package(PkgConfig)
pkg_check_modules(GLIB glib-2.0)

if (NOT GLIB_FOUND)
    message(STATUS "Could not find glib-2.0, which is needed for Aravis")
    return()
endif()


find_library(ARAVIS_LIBRARIES
    NAMES ${ARAVIS_LIBRARY_NAMES}
    PATHS
    /usr/lib/x86_64-linux-gnu
    /usr/lib
    /usr/local/lib
    "$ENV{LIB_DIR}/lib"
    "$ENV{LIB}"
)

find_path(ARAVIS_INCLUDE_DIR NAMES aravis-0.8/arv.h PATHS
    "${INCLUDE_DIRS}"
    /usr/include
    /usr/local/include
    /usr/local/hamamatsu_dcam/sdk/include/
    "$ENV{LIB_DIR}/include"
    "$ENV{INCLUDE}"
)

if (ARAVIS_INCLUDE_DIR AND ARAVIS_LIBRARIES)
    message(STATUS "Found ${ARAVIS_LIBNAME_STR}: ${ARAVIS_LIBRARIES}")
    set(ARAVIS_FOUND TRUE)
    set(ARAVIS_LIBRARIES ${ARAVIS_LIBRARIES} ${GLIB_LIBRARIES})
    set(ARAVIS_INCLUDE_DIR
        ${ARAVIS_INCLUDE_DIR}
        ${ARAVIS_INCLUDE_DIR}/aravis-0.8
        ${GLIB_INCLUDE_DIRS})
endif ()

if (NOT ARAVIS_FOUND AND ARAVIS_FIND_REQUIRED)
    message(FATAL_ERROR "Could not find ${NIDAQMX_LIBNAME_STR}")
endif ()

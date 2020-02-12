set(DCAMAPI_LIBNAME_STR "Hamamatsu DCAM-API")
set(DCAMAPI_LIBRARY_NAMES dcamapi)

find_library(DCAMAPI_LIBRARY
    NAMES ${DCAMAPI_LIBRARY_NAMES}
    PATHS
    /usr/lib
    /usr/local/lib
    "$ENV{LIB_DIR}/lib"
    "$ENV{LIB}"
)

find_path(DCAMAPI_INCLUDE_DIR NAMES dcamapi.h PATHS
    "${INCLUDE_DIRS}"
    /usr/include
    /usr/local/include
    /usr/local/hamamatsu_dcam/sdk/include/
    "$ENV{LIB_DIR}/include"
    "$ENV{INCLUDE}"
)

if (DCAMAPI_INCLUDE_DIR)
    message(STATUS "Found ${DCAMAPI_LIBNAME_STR} headers in: ${DCAMAPI_INCLUDE_DIR}")
endif ()

if (DCAMAPI_INCLUDE_DIR AND DCAMAPI_LIBRARY)
    set(DCAMAPI_FOUND TRUE)
    message(STATUS "Found ${DCAMAPI_LIBNAME_STR}: ${DCAMAPI_LIBRARY}")
endif ()

if (NOT DCAMAPI_FOUND AND DCAMAPI_FIND_REQUIRED)
    message(FATAL_ERROR "Could not find ${DCAMAPI_LIBNAME_STR}")
endif ()

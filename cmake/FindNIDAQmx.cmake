set(NIDAQMX_LIBNAME_STR "NI-DAQmx")
set(NIDAQMX_LIBRARY_NAMES nidaqmx)

find_library(NIDAQMX_LIBRARY
    NAMES ${NIDAQMX_LIBRARY_NAMES}
    PATHS
    /usr/lib/x86_64-linux-gnu
    /usr/lib
    /usr/local/lib
    "$ENV{LIB_DIR}/lib"
    "$ENV{LIB}"
)

find_path(NIDAQMX_INCLUDE_DIR NAMES NIDAQmx.h PATHS
    "${INCLUDE_DIRS}"
    /usr/include
    /usr/local/include
    /usr/local/hamamatsu_dcam/sdk/include/
    "$ENV{LIB_DIR}/include"
    "$ENV{INCLUDE}"
)

if (NIDAQMX_INCLUDE_DIR)
    message(STATUS "Found ${NIDAQMX_LIBNAME_STR} headers in: ${NIDAQMX_INCLUDE_DIR}")
endif ()

if (NIDAQMX_INCLUDE_DIR AND NIDAQMX_LIBRARY)
    set(NIDAQMX_FOUND TRUE)
    message(STATUS "Found ${NIDAQMX_LIBNAME_STR}: ${NIDAQMX_LIBRARY}")
endif ()

if (NOT NIDAQMX_FOUND AND NIDAQMX_FIND_REQUIRED)
    message(FATAL_ERROR "Could not find ${DCAMAPI_LIBNAME_STR}")
endif ()

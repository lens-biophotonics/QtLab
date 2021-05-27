set(PIGCS_LIBNAME_STR "PI GCS2")
set(PIGCS_LIBRARY_NAMES pi_pi_gcs2 PI_GCS2_DLL_x64)

get_property(INCLUDE_DIRECTORIES DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)

set(WIN_PISDK_DIR "$ENV{ProgramFiles\(x86\)}/Physik Instrumente (PI)/Software Suite/Development/C++/API")

find_library(PIGCS_LIBRARY
    NAMES ${PIGCS_LIBRARY_NAMES}
    PATHS
    /usr/lib/x86_64-linux-gnu
    /usr/lib
    /usr/local/lib
    /usr/local/PI
    "$ENV{LIB_DIR}/lib"
    "$ENV{LIB}"
    "${WIN_PISDK_DIR}"
)

find_path(PIGCS_INCLUDE_DIR NAMES PI_GCS2_DLL.h PATHS
    "${INCLUDE_DIRECTORIES}"
    /usr/local/PI/include
    "$ENV{LIB_DIR}/include"
    "$ENV{INCLUDE}"
    "${WIN_PISDK_DIR}"
)

if (PIGCS_INCLUDE_DIR AND PIGCS_LIBRARY)
    set(PIGCS_FOUND TRUE)
endif ()

if (PIGCS_FOUND)
    message(STATUS "Found ${PIGCS_LIBNAME_STR}: ${PIGCS_LIBRARY} ${PIGCS_INCLUDE_DIR}")
else (PIGCS_FOUND)
    if (PIGCS_FIND_REQUIRED)
        message(STATUS "Could not find ${PIGCS_LIBNAME_STR}. Headers: ${PIGCS_INCLUDE_DIR}")
    endif (PIGCS_FIND_REQUIRED)
endif ()

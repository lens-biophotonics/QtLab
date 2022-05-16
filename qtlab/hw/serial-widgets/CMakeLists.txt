set(TARGETNAME qtlab-serial-widgets)
set(EXPORT_NAME Serial-Widgets)

set(SOURCE_FILES
    aa_aotf_widget.cpp
)

add_library(${TARGETNAME} SHARED ${SOURCE_FILES})

set(HEADERS
    aa_aotf_widget.h
)

target_link_libraries(${TARGETNAME}
    PUBLIC
        qtlab-core
        qtlab-hw-serial
        qtlab-widgets
)

set(${TARGETNAME}_GEN_EXPORT_HEADER TRUE)
include(install_targets)

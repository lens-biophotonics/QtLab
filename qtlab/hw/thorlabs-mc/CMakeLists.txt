set(TARGETNAME qtlab-hw-thorlabs-mc)
set(EXPORT_NAME ThorlabsMC)

set(SOURCEFILES
    api.cpp
)

set(HEADERS
    api.h
    device.h
    messages.h
    message_codes.h
)

add_library(${TARGETNAME} SHARED ${SOURCEFILES})

target_link_libraries(${TARGETNAME} PUBLIC
    qtlab-core
    qtlab-hw-serial
)

set(${TARGETNAME}_GEN_EXPORT_HEADER TRUE)
include(install_targets)

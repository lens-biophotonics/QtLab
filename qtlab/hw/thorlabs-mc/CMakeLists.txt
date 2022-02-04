set(TARGETNAME qtlab-hw-thorlabs-mc)
set(EXPORT_NAME ThorlabsMC)

set(SOURCEFILES
    motorcontroller.cpp
)

set(HEADERS
    motorcontroller.h
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

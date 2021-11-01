add_library(bpforc bpforc.cpp)
set_target_properties(bpforc PROPERTIES PUBLIC_HEADER "bpforc.h")

install(TARGETS bpforc
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ast/bpforc)

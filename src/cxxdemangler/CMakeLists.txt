add_library(cxxdemangler_stdlib cxxdemangler_stdlib.cpp)
add_library(cxxdemangler_llvm cxxdemangler_llvm.cpp)

install(TARGETS cxxdemangler_stdlib cxxdemangler_llvm ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

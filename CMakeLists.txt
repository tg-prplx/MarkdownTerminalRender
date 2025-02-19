cmake_minimum_required(VERSION 3.16)

project(MDTerminalRenderer LANGUAGES C)

add_executable(MDTerminalRenderer main.c
    mdrender.h
    string_buffer.h
    styles.h
    stylestack.h)

include(GNUInstallDirs)
install(TARGETS MDTerminalRenderer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

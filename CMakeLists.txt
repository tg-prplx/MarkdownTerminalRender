cmake_minimum_required(VERSION 3.16)

project(MDTerminalRenderer LANGUAGES C)

add_executable(MDTerminalRenderer
    src/main.c
    src/mdrender.c
    src/string_buffer.c
    src/stylestack.c
    src/styles.c
)

target_include_directories(MDTerminalRenderer PRIVATE include)

include(GNUInstallDirs)
install(TARGETS MDTerminalRenderer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

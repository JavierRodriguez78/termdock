cmake_minimum_required(VERSION 3.10)
# Set the project name
project(TermDock)

add_definitions(-std=c++17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

# Create structure folders
set (GRAPHICAL_INTERFACE graphical/src)


# Add the executable
add_executable(
    TermDock 
    main.cpp
    ${GRAPHICAL_INTERFACE}/panel.cpp
    ${GRAPHICAL_INTERFACE}/terminal.cpp
    ${GRAPHICAL_INTERFACE}/window.cpp
)


find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIRS} )
target_link_libraries( TermDock  -lncurses -lpanel )
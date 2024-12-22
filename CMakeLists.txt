cmake_minimum_required(VERSION 3.10)
# Set the project name
project(TermDock)

add_definitions(-std=c++20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

# Create structure folders
set (GRAPHICAL_INTERFACE graphical/src)
set (DOCKER_INTERFACE docker/src)

# Add the executable
add_executable(
    TermDock 
    main.cpp
    ${GRAPHICAL_INTERFACE}/panel.cpp
    ${GRAPHICAL_INTERFACE}/terminal.cpp
    ${GRAPHICAL_INTERFACE}/window.cpp
    ${DOCKER_INTERFACE}/container.cpp
    ${DOCKER_INTERFACE}/docker.cpp
)


find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIRS} )


# Install http Client
include(FetchContent)

FetchContent_Declare(
    Cpp20HttpClient
    GIT_REPOSITORY https://github.com/avocadoboi/cpp20-http-client.git
)
FetchContent_MakeAvailable(Cpp20HttpClient)

# Install Curl
find_package(CURL REQUIRED)

#Install RapidJSON
find_package(RapidJSON)
target_link_libraries(TermDock PRIVATE Cpp20HttpClient::cpp20_http_client CURL::libcurl -lncurses -lpanel)


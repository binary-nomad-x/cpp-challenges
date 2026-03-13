cmake_minimum_required(VERSION 3.20)
project(learning)

set(CMAKE_CXX_STANDARD 14)

# 1. Find all your exercise files
file(GLOB EXERCISES "basics/*.cpp")

# 2. Loop through them to create individual programs
foreach (sourcefile ${EXERCISES})
    # Get just the filename (e.g., 01-welcome-text-on-screen-line)
    get_filename_component(exe_name ${sourcefile} NAME_WE)

    # Create the executable
    add_executable(${exe_name} ${sourcefile})

    # Optional: Print to the console so you know it's working
    message(STATUS "Created target: ${exe_name}")
endforeach ()

# 3. Also include your main.cpp if you use it
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
    add_executable(main_app main.cpp)
endif ()
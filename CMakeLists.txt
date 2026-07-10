cmake_minimum_required(VERSION 3.20)
project(learning)

set(CMAKE_CXX_STANDARD 14)

# Find all .cpp files recursively
file(GLOB_RECURSE ALL_SOURCES "basics/*.cpp" "exercises/*.cpp" "kirch-prinz/*.cpp")

foreach (sourcefile ${ALL_SOURCES})
    # Use the parent directory name + filename as the target name to avoid conflicts
    get_filename_component(dir ${sourcefile} DIRECTORY)
    get_filename_component(dir_name ${dir} NAME)
    get_filename_component(file_name ${sourcefile} NAME_WE)
    set(exe_name "${dir_name}-${file_name}")

    add_executable(${exe_name} ${sourcefile})
    message(STATUS "Created target: ${exe_name} from ${sourcefile}")
endforeach ()

# Include main.cpp at the root if it exists
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
    add_executable(main_app main.cpp)
endif ()



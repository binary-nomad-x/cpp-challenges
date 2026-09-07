cmake_minimum_required(VERSION 3.20)
project(learning)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
        "basics/*.cpp"
        "exercises/*.cpp"
        "kirch-prinz/*.cpp"
)

foreach (source ${SOURCES})
    get_filename_component(dir "${source}" DIRECTORY)
    get_filename_component(dir_name "${dir}" NAME)
    get_filename_component(file_name "${source}" NAME_WE)

    set(target "${dir_name}-${file_name}")

    add_executable("${target}" "${source}")
    message(STATUS "Target: ${target}")
endforeach ()

if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
    add_executable(main_app main.cpp)
endif ()

cmake_minimum_required(VERSION 3.20)
project(learning)

set(CMAKE_CXX_STANDARD 14)

# 1. Find all .cpp files in 'basics' AND 'exercises' (recursive)
file(GLOB_RECURSE BASIC_FILES "basics/*.cpp")
file(GLOB_RECURSE EXERCISE_FILES "exercises/*.cpp")
file(GLOB_RECURSE BOOK_EXERCISES_AND_EXAMPLE_FILES "kirch-prinz/*.cpp")

# Combine both lists
set(ALL_SOURCES ${BASIC_FILES} ${EXERCISE_FILES} ${BOOK_EXERCISES_AND_EXAMPLE_FILES})

# 2. Loop through all found source files
foreach (sourcefile ${ALL_SOURCES})
    # Get the filename without extension (e.g., my_code)
    get_filename_component(exe_name ${sourcefile} NAME_WE)

    # To avoid naming conflicts if two folders have "main.cpp", 
    # we can prefix the exercise folder name or just use the filename
    add_executable(${exe_name} ${sourcefile})

    message(STATUS "Created target: ${exe_name} from ${sourcefile}")
endforeach ()

# 3. Include main.cpp at the root if it exists
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
    add_executable(main_app main.cpp)
endif ()



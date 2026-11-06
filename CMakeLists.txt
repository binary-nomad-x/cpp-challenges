cmake_minimum_required(VERSION 3.20)
project(learning CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)   # IntelliSense ke liye

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Poore project se .cpp files, build folders ko chhod kar
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
list(FILTER SOURCES EXCLUDE REGEX "/(build|cmake-build-[^/]*)/")

if (NOT SOURCES)
  message(WARNING "Koi .cpp file nahi mili")
endif ()

foreach (source IN LISTS SOURCES)
  # basics/hello.cpp  ->  basics-hello
  file(RELATIVE_PATH rel "${CMAKE_CURRENT_SOURCE_DIR}" "${source}")
  string(REGEX REPLACE "\\.cpp$" "" target "${rel}")
  string(REGEX REPLACE "[/\\\\]" "-" target "${target}")

  add_executable(${target} "${source}")
endforeach ()
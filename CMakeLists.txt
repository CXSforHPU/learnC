cmake_minimum_required(VERSION 3.0)

project(main)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)
set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/lib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/ds_include)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src/ds_src DS_SRC)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LISTS)


add_executable(${PROJECT_NAME} ${SRC_LISTS} ${DS_SRC})

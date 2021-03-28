cmake_minimum_required(VERSION 3.7)
#set(CMAKE_VERBOSE_MAKEFILE on)

project(RayTracingInSeveralWeekends)
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/Source)
set(OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Release)

add_compile_options("-std=c++2a")
add_compile_options("-O3")
#add_compile_options("-g")

include_directories(${PROJECT_SOURCE_DIR})

add_executable(
	RayTracingInSeveralWeekends
	"${PROJECT_SOURCE_DIR}/main.cpp"
	"${PROJECT_SOURCE_DIR}/color.cpp"
	"${PROJECT_SOURCE_DIR}/vector.cpp"
	"${PROJECT_SOURCE_DIR}/sphere.cpp"
)
set_target_properties( RayTracingInSeveralWeekends
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}
)

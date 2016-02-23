cmake_minimum_required(VERSION 2.8.4)
project(ArduinoJson)

if(NOT DEFINED MACHINE)
	enable_testing()
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

if(MSVC)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS -W4)
endif()

if(${COVERAGE})
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -coverage")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage")
endif()

if(DEFINED INC_DIR)
	include_directories(${INC_DIR})
endif()

add_subdirectory(src)

if(NOT DEFINED MACHINE)
	add_subdirectory(test)
endif()
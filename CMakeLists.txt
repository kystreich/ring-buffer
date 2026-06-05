cmake_minimum_required(VERSION 4.3.0)

project(
    RingBuffer
    VERSION 0.0.1
    DESCRIPTION "A simple ring buffer implementation"
    LANGUAGES CXX)

set (CMAKE_EXPORT_COMPILE_COMMANDS ON)
set (CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_STANDARD_REQUIRED on)
set (CMAKE_CXX_EXTENSIONS off)
set (CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES OFF)

set (SOURCES
src/main.cpp
)

set (HEADERS
lib/ringbuffer.h
)

add_executable(RingBuffer ${SOURCES} ${HEADERS})

target_include_directories(RingBuffer PRIVATE
    ${CMAKE_SOURCE_DIR}
)

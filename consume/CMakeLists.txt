cmake_minimum_required(VERSION 3.20.0)
project(xml_reader)
add_compile_options(-std=c++11)

# Using the "cmake" generator
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_executable(xml_reader main.cpp)
target_link_libraries(xml_reader CONAN_PKG::pugixml)

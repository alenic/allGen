cmake_minimum_required(VERSION 3.5)

project(allgen)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O2")

if(WIN32)
  set(CMAKE_GENERATOR_PLATFORM Win64)
endif(WIN32)

# ============================== allgen static ibrary =============================
# Set Source Files
file(GLOB SOURCES "allgen/src/*.cpp")
# Set Include Files
file(GLOB INCLUDES "allgen/include/*.hpp")

# Add Shared library
add_library(allgen STATIC ${SOURCES} ${INCLUDES})
set_target_properties(allgen
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/static_lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/static_lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/static_lib"
)

## ============================== allgen tests =============================
file(GLOB TESTSOURCES "tests/*.cpp")
add_executable(test_main ${TESTSOURCES})
target_link_libraries(test_main allgen)

set_target_properties(test_main PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test")

include_directories("allgen/include/")

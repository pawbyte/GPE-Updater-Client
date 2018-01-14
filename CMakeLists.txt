cmake_minimum_required (VERSION 2.6)
project (GPE_Updater)
add_definitions("-std=c++11")

# Version Number
set (GPEU_VERSION_MAJOR 0)
set (GPEU_VERSION_MINOR 1)
set (GPEU_VERSION_STEP 1)

 #include(${CMAKE_SOURCE_DIR}/conanbuildinfo.cmake)
 #conan_basic_setup()

configure_file (
  "${PROJECT_SOURCE_DIR}/buildsrc/updaterConfig.hpp.in"
  "${PROJECT_BINARY_DIR}/src/updaterConfig.hpp"
  )

add_executable(GPE_Updater src/main.cpp)
#target_link_libraries(GPE_Updater ${CONAN_LIBS})

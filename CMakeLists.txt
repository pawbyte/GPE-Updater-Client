cmake_minimum_required (VERSION 3.0)
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

#find_package(CURL REQUIRED)
#add_executable(curltest code.cpp)
#target_link_libraries(curltest ${CURL_LIBRARIES})
#target_include_directories(curltest PUBLIC ${CURL_INCLUDE_DIRS})


#set(CURL_INCLUDE_DIR "" CACHE FILEPATH "Path to yourlib includes")

#if(NOT CURL_INCLUDE_DIR/curl/curl.h)
#  message(SEND_ERROR "Can't find curl/curl.h in ${CURL_INCLUDE_DIR}")
#endif()

include_directories(${CURL_INCLUDE_DIR})

find_package(curl REQUIRED)

link_directories(${CURL_LIBRARY_DIR})

include_directories(${PROJECT_SOURCE_DIR}/src)
set (SOURCES src/main.cpp src/cli.cpp src/filecheck.cpp src/servercheck.cpp)

add_executable(GPE_Updater ${SOURCES})
target_link_libraries(GPE_Updater libcurl)

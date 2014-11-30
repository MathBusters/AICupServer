project(AICupServer)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
cmake_minimum_required(VERSION 2.8)
FILE(GLOB_RECURSE SRC_LIST  *.cpp *.hpp)
#aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})
# link the libraries to the executable
TARGET_LINK_LIBRARIES(${PROJECT_NAME} boost_system jsoncpp)

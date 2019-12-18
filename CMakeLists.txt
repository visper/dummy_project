cmake_minimum_required(VERSION 3.5.1)
project(dummy_cmake_project)

set(CMAKE_CXX_STANDARD 14)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(AddGoogleTest)

add_executable(project Main.cpp  utils.cpp Calc.cpp )

add_gtest(project)

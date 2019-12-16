cmake_minimum_required(VERSION 3.5.1)
project(commandline_videostore_cpp)

set(CMAKE_CXX_STANDARD 14)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
enable_testing()



set(SOURCES
       utils.cc
       imovie.h
       movie.h
       movie.cc
       irental.h
       rental.h
       rental.cc
       imovie_repo.h
       movie_repo.h
       movie_repo.cc
       rental_factory.h
       rental_factory.cc
       run.h
       run.cpp)
add_library(StoreLib ${SOURCES})

add_executable(commandline_videostore_cpp main.cpp)
target_link_libraries(commandline_videostore_cpp StoreLib)

add_subdirectory(test)

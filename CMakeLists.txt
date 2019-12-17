cmake_minimum_required(VERSION 3.5.1)
project(commandline_videostore_cpp)

set(CMAKE_CXX_STANDARD 14)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
enable_testing()


set(HEADERS
      utils.h
      imovie.h
      movie.h
      irental.h
      rental.h
      imovie_repo.h
      movie_repo.h
      irental_factory.h
      rental_factory.h
      irental_record.h
      rental_record.h
      run.h)

set(SOURCES
      utils.cc
      movie.cc
      rental.cc
      movie_repo.cc
      rental_factory.cc
      rental_record.cc
      run.cpp)

add_library(StoreLib ${SOURCES} ${HEADERS})

add_executable(commandline_videostore_cpp main.cpp)
target_link_libraries(commandline_videostore_cpp StoreLib)

add_subdirectory(test)

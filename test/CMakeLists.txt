include_directories (${CMAKE_SOURCE_DIR})


include(AddGoogleTest)

add_executable (SingleTest singleTest.cpp)
add_gtest(SingleTest )
target_link_libraries(SingleTest PUBLIC StoreLib)
file(COPY ${CMAKE_SOURCE_DIR}/movies.csv
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

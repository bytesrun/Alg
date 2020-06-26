cmake_minimum_required(VERSION 3.0)

project(demo)

add_definitions(-std=c++11)

add_subdirectory(02_01_InsertionSort)
list(APPEND EXTRA_LIBS InsertionSort)

add_subdirectory(04_01_FindMaxSubArray)
list(APPEND EXTRA_LIBS FindMaxSubArray)

add_subdirectory(04_02_MatrixMultiply)
list(APPEND EXTRA_LIBS test_matrix)
aux_source_directory(. SRC)
add_executable(demo ${SRC})
target_link_libraries(demo PUBLIC ${EXTRA_LIBS})

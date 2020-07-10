cmake_minimum_required(VERSION 3.0)

project(demo)

add_definitions(-std=c++11)

option(INSERT_SORT "Usage: Test InsertionSort" OFF)
if (INSERT_SORT)
	add_subdirectory(02_01_InsertionSort)
	list(APPEND EXTRA_LIBS InsertionSort)
endif()

option(FIND_MAX_SUBARRAY "Usage: Test FindMaxSubArray" OFF)
if (FIND_MAX_SUBARRAY)
	add_subdirectory(04_01_FindMaxSubArray)
	list(APPEND EXTRA_LIBS FindMaxSubArray)
endif()

option(MATRIX_MULTIPLY "Usage: Test test_matrix" OFF)
if (MATRIX_MULTIPLY)
	add_subdirectory(04_02_MatrixMultiply)
	list(APPEND EXTRA_LIBS test_matrix)
endif()

option(RANDOMIZE_ARRAY "Usage: Test randomize_array" OFF)
if (RANDOMIZE_ARRAY)
	add_subdirectory(05_02_randomize_array)
	list(APPEND EXTRA_LIBS randomizeArray)
endif()

option(TEST_HEAP "Usage: Test Heap Sort" OFF)
if (TEST_HEAP)
	add_subdirectory(06_TestHeap)
	list(APPEND EXTRA_LIBS heapSort)
endif()

option(TEST_QUICK_SORT "Usage: Test Quick Sort" OFF)
if (TEST_QUICK_SORT)
	add_subdirectory(07_QuickSort)
	list(APPEND EXTRA_LIBS testQuickSort)
endif()

option(LINEAR_TIME_SORT "Usage: Test Linear Time SORT" OFF)
if (LINEAR_TIME_SORT)
	add_subdirectory(08_LinearTimeSort)
	list(APPEND EXTRA_LIBS linearTimeSort)
endif()

option(TEST_SELECT_ALG "Usage: Test Select Alg" OFF)
if (TEST_SELECT_ALG)
	add_subdirectory(09_TestSelectAlg)
	list(APPEND EXTRA_LIBS testSelectAlg)
endif()

option(TEST_BASIC_DS "Usage: Basic Data Structure" OFF)
if (TEST_BASIC_DS)
	add_subdirectory(10_BasicDataStructure)
	list(APPEND EXTRA_LIBS basicDataSt)
endif()

option(TEST_BST "Usage: Test BinarySearchTree" ON)
if (TEST_BST)
	add_subdirectory(12_BinarySearchTree)
	list(APPEND EXTRA_LIBS binarySearchTree)
endif()

configure_file(configure.h.in configure.h)


aux_source_directory(. SRC)
add_executable(demo ${SRC})
target_link_libraries(demo PUBLIC ${EXTRA_LIBS})
target_include_directories(demo PUBLIC 
						${PROJECT_BINARY_DIR})

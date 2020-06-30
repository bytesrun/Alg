aux_source_directory(. SRC)
add_library(testQuickSort ${SRC})
target_include_directories(testQuickSort
					INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
					PRIVATE ${PROJECT_SOURCE_DIR})
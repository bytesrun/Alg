aux_source_directory(. SRC)
add_library(heapSort ${SRC})
target_include_directories(heapSort
					INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
					PRIVATE ${PROJECT_SOURCE_DIR})
aux_source_directory(. SRC)
add_library(binarySearchTree ${SRC})
target_include_directories(binarySearchTree
					INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
					PRIVATE ${PROJECT_SOURCE_DIR})
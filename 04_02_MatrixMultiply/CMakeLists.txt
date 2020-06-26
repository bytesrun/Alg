aux_source_directory(. SRC)
add_library(test_matrix ${SRC})
target_include_directories(test_matrix 
			INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
			PRIVATE ${PROJECT_SOURCE_DIR})
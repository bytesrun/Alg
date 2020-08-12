aux_source_directory(. SRC)
add_library(testUnion ${SRC})
target_include_directories(testUnion
				INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
				PRIVATE ${PROJECT_SOURCE_DIR})
aux_source_directory(. SRC)
add_library(linearTimeSort ${SRC})
target_include_directories(linearTimeSort
				INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
				PRIVATE ${PROJECT_SOURCE_DIR})
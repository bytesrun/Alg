aux_source_directory(. SRC)
add_library(basicDataSt ${SRC})
target_include_directories(basicDataSt
					INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
					PRIVATE ${PROJECT_SOURCE_DIR})
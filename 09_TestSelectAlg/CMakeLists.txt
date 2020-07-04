aux_source_directory(. SRC)
add_library(testSelectAlg ${SRC})
target_include_directories(testSelectAlg
					INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
					PRIVATE ${PROJECT_SOURCE_DIR})
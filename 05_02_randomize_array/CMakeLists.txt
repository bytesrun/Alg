aux_source_directory(. SRC)
add_library(randomizeArray ${SRC})
target_include_directories(randomizeArray 
					INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
					PRIVATE ${PROJECT_SOURCE_DIR})
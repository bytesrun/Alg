add_library(FindMaxSubArray FindMaxSubArray.cpp)

target_include_directories(FindMaxSubArray
			INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
			PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
			PRIVATE ${PROJECT_SOURCE_DIR})

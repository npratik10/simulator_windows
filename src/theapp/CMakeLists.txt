include_directories(${CMAKE_SOURCE_DIR}/../include)
include_directories(${CMAKE_SOURCE_DIR}/libutil/inc)
include_directories(${CMAKE_SOURCE_DIR}/sharedmod)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_executable(theapp main.cpp)

target_link_libraries(theapp debug sharedmod.lib)
target_link_libraries(theapp optimized sharedmod.lib)
target_link_libraries(theapp debug libutil.lib)
target_link_libraries(theapp optimized libutil.lib)
include_directories(${CMAKE_SOURCE_DIR}/libutil/inc)
include_directories(${CMAKE_SOURCE_DIR}/../include)
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

file(GLOB headers *.h)
add_library(sharedmod STATIC model.cpp ${headers})

add_definitions(-DEXPMODULE)

target_link_libraries(sharedmod debug libutil.lib)
target_link_libraries(sharedmod optimized libutil.lib)
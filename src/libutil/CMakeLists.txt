add_library(libutil STATIC random.cpp random.h)

include_directories(${CMAKE_SOURCE_DIR}/../include)
add_definitions(-DEXPMODULE)
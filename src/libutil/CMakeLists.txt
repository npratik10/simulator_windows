include_directories(${CMAKE_SOURCE_DIR}/../include)
include_directories(${CMAKE_SOURCE_DIR}/libutil/inc)
include_directories(${CMAKE_SOURCE_DIR}/libutil/src)

list(APPEND lib_inc
    "${CMAKE_SOURCE_DIR}/libutil/inc/clock.h"
    "${CMAKE_SOURCE_DIR}/libutil/inc/component_queue.h"
    "${CMAKE_SOURCE_DIR}/libutil/inc/component_block.h"
    "${CMAKE_SOURCE_DIR}/libutil/inc/subtract.h"
)

list(APPEND lib_src
    "${CMAKE_SOURCE_DIR}/libutil/src/clock.cpp"
    "${CMAKE_SOURCE_DIR}/libutil/src/subtract.cpp"
)

add_library(libutil STATIC ${lib_src} ${lib_inc})

#target_include_directories(libutil PUBLIC ${CMAKE_SOURCE_DIR}/libutil/inc)
add_definitions(-DEXPMODULE)
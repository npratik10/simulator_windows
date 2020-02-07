include_directories(${CMAKE_SOURCE_DIR}/../include)
include_directories(${CMAKE_SOURCE_DIR}/libutil/inc)

list(APPEND lib_inc
    "${CMAKE_SOURCE_DIR}/libutil/inc/random.h"
    "${CMAKE_SOURCE_DIR}/libutil/inc/clock.h"
)

list(APPEND lib_src
    "${CMAKE_SOURCE_DIR}/libutil/src/random.cpp"
    "${CMAKE_SOURCE_DIR}/libutil/src/clock.cpp"
)

add_library(libutil STATIC ${lib_src} ${lib_inc})

#target_include_directories(libutil PUBLIC ${CMAKE_SOURCE_DIR}/libutil/inc)
add_definitions(-DEXPMODULE)
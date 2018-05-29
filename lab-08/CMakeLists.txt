cmake_minimum_required (VERSION 3.1)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -std=c++11")

add_definitions(-DBOOST_ALL_DYN_LINK)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.54.0 REQUIRED)

# Include path
include_directories(SYSTEM
    ${Boost_INCLUDE_DIRS}
)

# Custom schema validation example
add_executable(example
    example.cpp
)

target_link_libraries(executable ${Boost_LIBRARIES})

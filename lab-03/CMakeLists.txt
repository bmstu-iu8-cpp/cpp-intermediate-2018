cmake_minimum_required (VERSION 2.8)

include_directories(SYSTEM
    ./
)

ADD_DEFINITIONS(
    -std=c++11 -O1 -fsanitize=address
)

# enum your files
add_executable(memory_leak
    memory_leak.cpp
)

# disabled sanitizer
target_link_libraries(memory_leak)

add_executable(raii
    raii.cpp
)

target_link_libraries(raii -fsanitize=address)

add_executable(solution_equation
    solution_equation.cpp
)

target_link_libraries(solution_equation -fsanitize=address)

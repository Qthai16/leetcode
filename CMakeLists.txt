cmake_minimum_required(VERSION 3.16)

project(leetcode C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

set(LINK_LIBS
    ${LINK_LIBS}
    pthread
)

add_executable(leetcode
    test.cpp
)

# notes: -fsanitize=thread cannot use with -fsanitize=address
target_compile_options(leetcode PRIVATE
    $<$<CONFIG:Debug>:-g -fsanitize=address -fno-omit-frame-pointer>
    $<$<CONFIG:Release>:-w -O3>
    # -Wall -Wextra -Wsign-conversion
)

target_include_directories(leetcode PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(leetcode PRIVATE
    ${LINK_LIBS}
    $<$<CONFIG:Debug>:-fsanitize=address>
)

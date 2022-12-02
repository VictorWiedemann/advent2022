cmake_minimum_required(VERSION 3.14)

project(advent2022 LANGUAGES CXX)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
add_executable(advent2022 src/main.cpp )


target_sources(advent2022 
                PUBLIC ${CMAKE_SOURCE_DIR}/src/day01.cpp
                PUBLIC ${CMAKE_SOURCE_DIR}/src/day02.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day03.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day04.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day05.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day06.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day07.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day08.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day09.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day10.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day11.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day12.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day13.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day14.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day15.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day16.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day17.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day18.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day19.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day21.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day22.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day23.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day24.cpp
                # PUBLIC ${CMAKE_SOURCE_DIR}/src/day25.cpp
                ) 


# target_link_directories(advent2022 PUBLIC
#                            ${JSONC_LIB_DIR}
#                        )

# find_package(OpenMP)
# find_package(CUDA 9.0 REQUIRED)

target_link_libraries(advent2022
#     -lrt
#     -lm
    # PUBLIC OpenMP::OpenMP_CXX
    # ${CUDA_LIBRARIES}
)

include_directories(${CMAKE_SOURCE_DIR}/inc
                    )

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall")

include(CPack)
cmake_minimum_required(VERSION 3.14)

project(advent2022 LANGUAGES CXX)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
add_executable(advent2022 src/main.cpp )


target_sources(advent2022 
                PUBLIC ${CMAKE_SOURCE_DIR}/src/day1.cpp
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
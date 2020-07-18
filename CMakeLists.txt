project(algorithms_and_data_structures)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)  # c++11

add_compile_options(-Wall -Wextra -pedantic -Werror)

include_directories(${PROJECT_SOURCE_DIR}/src)

enable_testing()

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${PROJECT_SOURCE_DIR}/tests)

cmake_minimum_required(VERSION 3.1.0)

project(Calculator VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# if(CMAKE_VERSION VERSION_LESS "3.7.0")
#     set(CMAKE_INCLUDE_CURRENT_DIR ON)
# endif()

find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS Charts REQUIRED)

add_executable(Calculator
    qt/calculator.cpp
    qt/credit.cpp
    qt/graph.cpp
    qt/custom_axis.cpp
    qt/main.cpp
    calculations/calc.c
    calculations/pars.c
    calculations/credit_calc.c
    calculations/stack.c
    qt/calculator.ui
    qt/credit.ui
    qt/graph.ui
    qt/custom_axis.ui
    headers/calculator.h
    headers/credit.h
    headers/graph.h
    headers/custom_axis.h
    headers/calc.h
    headers/pars.h
    headers/credit_calc.h
    headers/stack.h
)

target_link_libraries(Calculator Qt6::Widgets Qt6::Core)
target_link_libraries(Calculator Qt6::Charts Qt6::Core)

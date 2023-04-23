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

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Charts REQUIRED)

add_executable(Calculator
    calculator.cpp
    credit.cpp
    graph.cpp
    main.cpp
    calc.c
    pars.c
    credit_calc.c
    stack.c
    calculator.ui
    credit.ui
    graph.ui
)

target_link_libraries(Calculator Qt5::Widgets)
target_link_libraries(Calculator Qt5::Charts)
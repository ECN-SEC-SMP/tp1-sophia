cmake_minimum_required(VERSION 4.0)
project(tp1_annabelle_sophia)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(sources
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lexique.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/utilitaire.cpp
)

include_directories(include)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(tp1_annabelle_sophia ${sources})

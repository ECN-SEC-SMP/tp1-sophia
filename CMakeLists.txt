cmake_minimum_required(VERSION 3.10)
project(TP1_Lexique VERSION 1.0 LANGUAGES CXX)

# Utilise le standard C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tous les fichiers sources
set(SOURCES
    main.cpp
    lexique.cpp
    utilitaire.cpp
)

# Création de l'exécutable "tp1"
add_executable(tp1 ${SOURCES})

# Inclure le dossier courant pour les fichiers .hpp
target_include_directories(tp1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Options de compilation : warnings utiles
if(MSVC)
    target_compile_options(tp1 PRIVATE /W4)
else()
    target_compile_options(tp1 PRIVATE -Wall -Wextra -pedantic)
endif()

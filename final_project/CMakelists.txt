# Version minima de la herramienta

cmake_minimum_required(VERSION 3.24)

# Nombre del proyecto 
project(Carrera_CPP_AVANZADO LANGUAGES CXX)

# Forzamos el uso de C++17 (para auto y templates modernos)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluimos el directorio de los archivos de cabecera (.hpp)
include_directories(include)

# Definimos el ejecutable: (Nombre del programa) (Archivos .cpp necesarios)
add_executable(main  src/main.cpp)



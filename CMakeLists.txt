cmake_minimum_required(VERSION 3.10)

# Устанавливаем имя проекта
project(ChiSquareTest)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 11)

# Указываем исходные файлы
set(SOURCES
    chi_square.cpp
    main.cpp
)

# Создаём исполнимый файл
add_executable(${PROJECT_NAME} ${SOURCES})

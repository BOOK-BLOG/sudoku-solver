# CMakeLists.txt

cmake_minimum_required(VERSION 3.1.0)

project(sudoku-solver)

set(SOURCES
		src/main.cpp		
)

add_executable(sudoku-solver
    ${SOURCES}
)

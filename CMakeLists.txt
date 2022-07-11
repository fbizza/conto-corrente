cmake_minimum_required(VERSION 3.5)
project(conto-corrente)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

set(SOURCE_FILES ContoCorrente.cpp ContoCorrente.h Bonifico.h Bonifico.cpp Investimento.cpp Investimento.h)
add_executable(conto-corrente main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(conto-corrente core)
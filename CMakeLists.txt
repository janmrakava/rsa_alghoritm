cmake_minimum_required(VERSION 3.22)
project(krypto_rsa)

set(CMAKE_CXX_STANDARD 17)

add_executable(krypto_rsa main.cpp)


set(BOOST_ROOT "C:/boost_1_59_0")
set(BOOSTROOT "C:/boost_1_59_0")
find_package(Boost 1.59.0)
set(Boost_INCLUDE_DIR C:/boost_1_59_0/)
set(Boost_LIBRARY_DIR C:/boost_1_59_0/boost)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

set(CMAKE_EXE_LINKER_FLAGS "-static")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

set(SOURCE_FILES main.cpp)







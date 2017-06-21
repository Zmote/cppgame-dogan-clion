cmake_minimum_required(VERSION 3.7)
project(CPPGameDogan)

set(CMAKE_CXX_STANDARD 14)

include_directories(D:/boost_1_63_0/ C:/SFML-2.4.1/include)

link_directories(D:/boost_1_63_0/stage/lib)
link_directories(C:/SFML-2.4.1/lib)
add_definitions(-DSFML_STATIC)

set(SOURCE_FILES main.cpp)
add_executable(CPPGameDogan ${SOURCE_FILES})
target_link_libraries(CPPGameDogan
        sfml-graphics-s-d
        sfml-window-s-d
        sfml-main-d
        opengl32
        sfml-system-s-d
        winmm gdi32
        freetype
        jpeg
        boost_log-mgw61-mt-d-1_63
        boost_thread-mgw61-mt-d-1_63
        boost_system-mgw61-mt-d-1_63)
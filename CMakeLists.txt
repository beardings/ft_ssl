cmake_minimum_required(VERSION 3.12)
project(md5)

set(CMAKE_CXX_STANDARD 98)

add_executable(md5 libft/libft.a
        src/main.c
        src/initdata.c
        src/console.c
        src/print.c
        src/parsing.c)
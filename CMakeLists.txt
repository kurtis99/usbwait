cmake_minimum_required (VERSION 2.8)
project (usbwait)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -std=gnu99")
set (CMAKE_C_FLAGS_RELEASE "-DNDEBUG -Os -Werror")
set (CMAKE_C_FLAGS_DEBUG "-DDEBUG -O0 -ggdb")

add_executable(usbwait usbwait.c)

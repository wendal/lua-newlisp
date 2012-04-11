cmake_minimum_required (VERSION 2.6)

#set(CMAKE_VERBOSE_MAKEFILE ON)
include_directories(${CMAKE_SOURCE_DIR})
 
project(newLISP)
add_library(newLISP SHARED newLISP.c)
TARGET_LINK_LIBRARIES(newLISP newlisp lua)

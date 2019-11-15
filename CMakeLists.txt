cmake_minimum_required(VERSION 3.10)

project(OSdiaTest)

if(UNIX)

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK REQUIRED gtk+-3.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK_LIBRARY_DIRS})

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK_CFLAGS_OTHER})

endif(UNIX)

if(UNIX)
add_library(
  osdialog
  osdialog/osdialog.h
  osdialog/osdialog.c
  osdialog/osdialog_win.c
)
endif(UNIX)

if(WIN32)
add_library(
  osdialog
  osdialog/osdialog.h
  osdialog/osdialog.c
  osdialog/osdialog_win.c
)
endif(WIN32)
    
include_directories(osdialog)

add_executable(Test main.cpp)

target_link_libraries(Test PUBLIC osdialog)

if(UNIX)
TARGET_LINK_LIBRARIES(Test PUBLIC ${GTK_LIBRARIES})
endif(UNIX)

cmake_minimum_required(VERSION 3.10)

project(OSdiaTest)

add_library(
  osdialog
  osdialog/osdialog.h
  osdialog/osdialog.c
  osdialog/osdialog_win.c
)

include_directories(osdialog)

add_executable(Test main.cpp)

target_link_libraries(Test PUBLIC osdialog)
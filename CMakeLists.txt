cmake_minimum_required(VERSION 3.14...3.22)
set(CMAKE_CXX_STANDARD 20)
project(funnyfs LANGUAGES CXX)

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig REQUIRED)
find_package(gflags CONFIG REQUIRED)
find_package(glog CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(leveldb CONFIG REQUIRED)

pkg_check_modules(FUSE3 REQUIRED IMPORTED_TARGET fuse3)

add_subdirectory(src)
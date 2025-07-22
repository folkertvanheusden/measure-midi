cmake_minimum_required(VERSION 3.15)

project(measure-midi)

add_compile_options(-Wall)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 01)
set(KABOEM_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}")


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE RelWithDebInfo)
#set(CMAKE_BUILD_TYPE Debug)

add_executable(
  measure-midi
  midi.cpp
  tester.cpp
  time.cpp
)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads)
target_link_libraries(measure-midi PRIVATE Threads::Threads)

include(FindPkgConfig)

pkg_check_modules(RTMIDI rtmidi)
target_link_libraries(measure-midi PRIVATE ${RTMIDI_LIBRARIES})
target_include_directories(measure-midi PUBLIC ${RTMIDI_INCLUDE_DIRS})
target_compile_options(measure-midi PUBLIC ${RTMIDI_CFLAGS_OTHER})

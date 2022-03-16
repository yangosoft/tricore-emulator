cmake_minimum_required(VERSION 3.10)

set (trimul_VERSION_MAJOR 0)
set (trimul_VERSION_MINOR 1)
project(trimul VERSION ${trimul_VERSION_MAJOR}.${trimul_VERSION_MINOR} LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wsign-promo -Wnon-virtual-dtor -Wctor-dtor-privacy -Woverloaded-virtual -Wold-style-cast -Wpointer-arith -Wshadow -Wunused -Wuninitialized -Winit-self -Wdeprecated -Wfloat-equal")
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(ENABLE_TEST OFF CACHE BOOL "Enable Google Test")
set(ENABLE_GNUTLS OFF CACHE BOOL "Enable GNUTLS link")

if( NOT CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE Debug CACHE STRING       "Choose the type of build, options are: None Debug Release RelWithDebInfo
MinSizeRel."  FORCE )
endif()

if( ENABLE_TEST )
    message("Unit test enabled")
    enable_testing()
endif()

set (SRCS "src/main.cpp"
"src/memory.cpp" )

set (INCS "inc")

add_executable(trimul ${SRCS})
target_include_directories(trimul PRIVATE ${INCS})

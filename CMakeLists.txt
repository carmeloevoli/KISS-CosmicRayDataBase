project(KISS CXX)
cmake_minimum_required(VERSION 3.6)

set( CMAKE_VERBOSE_MAKEFILE off )
set( CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" )
set( CMAKE_C_COMPILER "/usr/local/Cellar/gcc/9.3.0_1/bin/gcc-9" )
set( CMAKE_C_FLAGS "-O3" )
set( CMAKE_CXX_COMPILER "/usr/local/Cellar/gcc/9.3.0_1/bin/g++-9" )
set( CMAKE_CXX_FLAGS "-O3 -ftree-vectorize -std=c++14" )
set( KISS_INCLUDES )
set( KISS_LIBRARIES )

set (CMAKE_CXX_STANDARD 11)
cmake_policy(SET CMP0048 NEW)

# include
include_directories( "${CMAKE_SOURCE_DIR}" )

# GSL (external)
find_package(GSL)
if(GSL_FOUND)
    set(HAVE_LIBGSL 1)
    list(APPEND KISS_INCLUDES ${GSL_INCLUDE_DIR})
    list(APPEND KISS_LIBRARIES ${GSL_LIBRARIES})
else(GSL_FOUND)
    message(FATAL_ERROR "Require GSL: set GSL_HOME")
endif(GSL_FOUND)

# copy data files in build
file(GLOB KISS_DATA "source_tables/nuclei/*.txt")
file(COPY ${KISS_DATA} DESTINATION ${PROJECT_BINARY_DIR}/source/nuclei)

file(GLOB KISS_DATA "source_tables/allparticle/*.txt")
file(COPY ${KISS_DATA} DESTINATION ${PROJECT_BINARY_DIR}/source/allparticle)

# create the output dir
file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/output)

# add source files
set( KISS_SRCS
	src/CrDataset.cpp
	src/CRDB.cpp
	src/KCDC.cpp
	src/mydb.cpp
	src/SSDC.cpp
	src/utils.cpp
)

# make library
include_directories (include ${KISS_INCLUDES})
add_library( KISS_LIB ${KISS_SRCS} ${KISS_INCLUDES} )

# make executables
add_executable(KISS src/main.cpp)
target_link_libraries (KISS KISS_LIB ${KISS_LIBRARIES})

# show summary
message (STATUS "CMAKE_SYSTEM .......... = ${CMAKE_SYSTEM}")
message (STATUS "BUILD_SHARED_LIBS ..... = ${BUILD_SHARED_LIBS}")
message (STATUS "CMAKE_C_COMPILER ...... = ${CMAKE_C_COMPILER}")
message (STATUS "CMAKE_C_FLAGS ......... = ${CMAKE_C_FLAGS}")
message (STATUS "CMAKE_CXX_COMPILER .... = ${CMAKE_CXX_COMPILER}")
message (STATUS "CMAKE_CXX_FLAGS ....... = ${CMAKE_CXX_FLAGS}")
message (STATUS "CMAKE_INCLUDE_PATH .... = ${CMAKE_INCLUDE_PATH}")
message (STATUS "KISS_INCLUDES ...... = ${KISS_INCLUDES}")
message (STATUS "KISS_LIBRARIES ..... = ${KISS_LIBRARIES}")

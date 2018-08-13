cmake_minimum_required(VERSION 3.2)
project(cpp_utils)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest)

# things to be gathered
set(PRJ_INCLUDE_DIRS "")
set(PRJ_LIBRARIES "")
set(PRJ_SOURCES "")

# packages required
find_package(OpenCV REQUIRED)
find_package(Boost COMPONENTS filesystem system)
find_package(OpenSSL REQUIRED COMPONENTS ssl)

# include dirs
list(APPEND PRJ_INCLUDE_DIRS ${Boost_INCLUDE_DIRS})
list(APPEND PRJ_INCLUDE_DIRS ${OpenCV_INCLUDE_DIRS})
list(APPEND PRJ_INCLUDE_DIRS ${OPENSSL_INCLUDE_DIR})
list(APPEND PRJ_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/utils/")
list(REMOVE_DUPLICATES PRJ_INCLUDE_DIRS)
include_directories(${PRJ_INCLUDE_DIRS})

# libraries
list(APPEND PRJ_LIBRARIES ${Boost_LIBRARIES})
list(APPEND PRJ_LIBRARIES ${OpenCV_LIBS})
list(APPEND PRJ_LIBRARIES ${OPENSSL_LIBRARIES})
list(APPEND PRJ_LIBRARIES ${CMAKE_DL_LIBS})

# source files
file(GLOB_RECURSE PRJ_SOURCES1 utils/*.cpp)
list(APPEND PRJ_SOURCES ${PRJ_SOURCES1})
list(APPEND PRJ_SOURCES ${PRJ_SOURCES2})
list(REMOVE_DUPLICATES PRJ_SOURCES)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(run_test test.cpp ${PRJ_SOURCES})
target_link_libraries(run_test ${PRJ_LIBRARIES} gtest_main)
add_test(NAME run_test COMMAND run_test)

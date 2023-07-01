cmake_minimum_required(VERSION 3.20)
project(Sniffer CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")


FIND_PACKAGE(Boost 1.71 COMPONENTS program_options filesystem REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

# Example: source/file.cpp
set(SOURCES apps/main.cpp)

add_executable(Sniff ${SOURCES})
target_include_directories(Sniff PRIVATE ${PROJECT_SOURCE_DIR}/includes)

target_link_libraries(Sniff ${BOOST_LIBRARIES}   ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)



enable_testing()

# Example:
# tests/file.cpp
# source/file.cpp
add_executable(
  tests
  tests/testfile.cpp
)


target_link_libraries(
  tests
  GTest::gtest_main
  GTest::gmock_main
  ${BOOST_LIBRARIES} 
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
)
target_include_directories(tests PRIVATE ${PROJECT_SOURCE_DIR}/includes)
#EXAMPLE of including new directiories in test files: target_include_directories(tests PRIVATE ${PROJECT_SOURCE_DIR}/tests/fileHandlerTests)
include(GoogleTest)
gtest_discover_tests(tests)
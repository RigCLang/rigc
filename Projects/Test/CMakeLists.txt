cmake_minimum_required(VERSION 3.25)

project(JetTestProject VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES
  "Public/*.hpp"
  "Public/*.ixx"
  "Public/*.cpp"

  "Private/*.hpp"
  "Private/*.ixx"
  "Private/*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE JetCompiler JetParser JetCore Jet_Comp_Format gtest gtest_main)

if (MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE "/utf-8")
endif ()
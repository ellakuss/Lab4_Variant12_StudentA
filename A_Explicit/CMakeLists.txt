cmake_minimum_required(VERSION 3.20)
project(A_Explicit LANGUAGES CXX)
add_executable(ExplicitTest main.cpp)
target_compile_features(ExplicitTest PRIVATE cxx_std_20)
add_custom_command(TARGET ExplicitTest POST_BUILD
 COMMAND ${CMAKE_COMMAND} -E copy_if_different
 "${CMAKE_CURRENT_SOURCE_DIR}/../A_Dynamic/SDK/bin/Combinatorics.dll"
 "$<TARGET_FILE_DIR:ExplicitTest>")

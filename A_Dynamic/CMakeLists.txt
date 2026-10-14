cmake_minimum_required(VERSION 3.20)
project(A_Dynamic LANGUAGES CXX)
add_library(Combinatorics SHARED src/Combinatorics.cpp)
target_compile_definitions(Combinatorics PRIVATE COMBI_EXPORTS)
target_include_directories(Combinatorics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(Combinatorics PUBLIC cxx_std_20)
set(SDK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SDK")
file(MAKE_DIRECTORY "${SDK_DIR}/include" "${SDK_DIR}/lib" "${SDK_DIR}/bin")
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/include/Combinatorics.h" "${SDK_DIR}/include/Combinatorics.h" COPYONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/README.md" "${SDK_DIR}/README.md" COPYONLY)
add_custom_command(TARGET Combinatorics POST_BUILD
 COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_FILE:Combinatorics>" "${SDK_DIR}/bin/Combinatorics.dll"
 COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_LINKER_FILE:Combinatorics>" "${SDK_DIR}/lib/Combinatorics.lib"
 COMMENT "Assembling SDK package")

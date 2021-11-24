cmake_minimum_required (VERSION 3.9)

project(plane)


set(SRCS "plane.cpp")

add_executable (plane ${SRCS})

find_package (Threads)

target_compile_features(plane PUBLIC cxx_std_17)
target_link_libraries (plane Threads::Threads)

install(TARGETS thread_example RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/../bin)

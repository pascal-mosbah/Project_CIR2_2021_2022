cmake_minimum_required (VERSION 3.9)
project(SFML_Test)

set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        )

if(MSVC)
	set(SFML_STATIC_LIBRARIES TRUE)
	set(SFML_DIR "${PROJECT_SOURCE_DIR}/../../SFML-2.5.1-static/lib/cmake/SFML")
endif()

SET(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)



find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

set(TEST_SRCS "main.cpp" "Car.cpp")

add_executable (SFML_Test ${TEST_SRCS})
target_link_libraries(SFML_Test sfml-graphics sfml-window)

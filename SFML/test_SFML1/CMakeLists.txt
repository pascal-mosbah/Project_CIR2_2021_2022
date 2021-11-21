cmake_minimum_required (VERSION 3.9)
project(SFML_Test1)

set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        )

SET(IMG_DIRECTORY "IMG=${CMAKE_SOURCE_DIR}/img")

SET(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)

if(MSVC)
    foreach(CompilerFlag ${CompilerFlags})
        string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
    endforeach()
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /D${IMG_DIRECTORY}")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /D${IMG_DIRECTORY}")

    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebug<$<CONFIG:Debug>:Debug>")
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded<$<CONFIG:Release>:Release>")
	set(SFML_STATIC_LIBRARIES TRUE)
	set(SFML_DIR "C:/SFML-2.5.1_windows_VS15.6_static/lib/cmake/SFML")
endif()


find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

set(TEST_SRCS "main.cpp" "Follower.cpp" "Leader.cpp")

add_executable (SFML_Test1 ${TEST_SRCS})
target_link_libraries(SFML_Test1 sfml-graphics sfml-window)



#if(MSVC)
#    set_property(TARGET SFML_Test1 PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded<$<CONFIG:Release>:Release>")
#    set_property(TARGET SFML_Test1 PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreadedDebug<$<CONFIG:Debug>:Debug>")
#endif()
cmake_minimum_required(VERSION 3.8.2 FATAL_ERROR)
project(ASTEROIDS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# begin with compilation of SDL2 copy 
add_subdirectory(libraries/SDL2)
add_subdirectory(libraries/Utils)
add_subdirectory(libraries/Geometry)

# convenient function for easy compilation of Asteroids project
# usage: compilation(EXEC nom_executable SRC fichiers sources .cpp et .h USE_SDL)
# add USE_SDL if you want to use SDL2 library

function(COMPILATION)
    cmake_parse_arguments(COMPILATION_PREFIX "USE_SDL" "EXEC" "SRC" ${ARGN})
    aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/include INCLUDES)
    file(GLOB SOURCES ${COMPILATION_PREFIX_SRC}/*.cpp ${COMPILATION_PREFIX_SRC}/*/*.cpp)
    add_executable(${COMPILATION_PREFIX_EXEC} ${SOURCES} ${INCLUDES})
    target_include_directories(${COMPILATION_PREFIX_EXEC}
        PUBLIC 
            $<INSTALL_INTERFACE:include>    
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    )
    target_sources(${COMPILATION_PREFIX_EXEC} PUBLIC ${SOURCES})
    set_target_properties(${COMPILATION_PREFIX_EXEC} PROPERTIES CXX_STANDARD 17)
    target_link_libraries(${COMPILATION_PREFIX_EXEC} PUBLIC Utils Geometry)
    if (${COMPILATION_PREFIX_USE_SDL})
        target_link_libraries(${COMPILATION_PREFIX_EXEC} PUBLIC SDL2main SDL2-static)
    endif()
endfunction()

#TODO: use aux_source_directory
compilation(EXEC asteroids SRC src USE_SDL)
cmake_minimum_required(VERSION 3.8.2 FATAL_ERROR)
project(ASTEROIDS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(lib/SDL2)
add_subdirectory(lib/nlohmann_json)
add_subdirectory(lib/nlohmann_json_schema_validator)
add_subdirectory(lib/Utils)
add_subdirectory(lib/Geometry)

# find_package(nlohmann_json REQUIRED)
# find_package(nlohmann_json_schema_validator REQUIRED)

# convenient function for easy compilation of Asteroids project
# usage: compilation(EXEC nom_executable SRC fichiers sources .cpp et .h USE_SDL)
# add USE_SDL if you want to use SDL2 library

function(COMPILATION)
    cmake_parse_arguments(COMPILATION_PREFIX "USE_SDL" "EXEC" "SRC" ${ARGN})
    aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/include INCLUDES)
    file(GLOB SOURCES ${COMPILATION_PREFIX_SRC}/*.cpp)
    add_executable(${COMPILATION_PREFIX_EXEC} ${SOURCES} ${INCLUDES})
    target_include_directories(${COMPILATION_PREFIX_EXEC}
        PUBLIC 
            $<INSTALL_INTERFACE:include>    
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    )
    target_sources(${COMPILATION_PREFIX_EXEC} PUBLIC ${SOURCES})
    set_target_properties(${COMPILATION_PREFIX_EXEC} PROPERTIES CXX_STANDARD 17)
    target_link_libraries(${COMPILATION_PREFIX_EXEC} PUBLIC Utils Geometry nlohmann_json::nlohmann_json nlohmann_json_schema_validator) 
    if (${COMPILATION_PREFIX_USE_SDL})
        target_link_libraries(${COMPILATION_PREFIX_EXEC} PUBLIC SDL2main SDL2-static)
    endif()
endfunction()

#TODO: use aux_source_directory
compilation(EXEC asteroids SRC src USE_SDL)
#
# Global Basic C++ Prpject Template for CMake
# 
# This script support the following features:
#   * Please pass a CMAKE_BUILD_TYPE flag to override the default "Debug" type.
#       (example: cmake .. -DCMAKE_BUILD_TYPE=Release)
#
#   * Post make run. This will attempt to execute the built target.
#       (example: make run)

# ;--------------------------------------------------------------------------------
# ; Initials
# ;--------------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.8)
project(myApp)

# ;--------------------------------------------------------------------------------
# ; Set Project Type
# ;--------------------------------------------------------------------------------
#
# Available options are:
#   Command Line Tool
#   Application
set(PROJECT_TYPE "Command Line Tool")

# ;--------------------------------------------------------------------------------
# ; Set Default Build Type
# ;--------------------------------------------------------------------------------
#
# Available options are:
#   Release
#   Debug
if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "CMAKE_BUILD_TYPE not specified, defaulting to [Debug]")
    set(CMAKE_BUILD_TYPE Debug CACHE STRING
        "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel. "
        FORCE
        )
    message(STATUS "CMAKE_BUILD_TYPE is [${CMAKE_BUILD_TYPE}]")
endif()

# ;--------------------------------------------------------------------------------
# ; Platform Detection
# ;--------------------------------------------------------------------------------
set(CURRENT_PLATFORM_IS_OSX FALSE)
set(CURRENT_PLATFORM_IS_LINUX FALSE)
set(CURRENT_PLATFORM_IS_WINDOWS FALSE)

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(CURRENT_PLATFORM "OSX")
    set(CURRENT_PLATFORM_IS_OSX TRUE)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(CURRENT_PLATFORM "LINUX")
    set(CURRENT_PLATFORM_IS_LINUX TRUE)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(CURRENT_PLATFORM "WINDOWS")
    set(CURRENT_PLATFORM_IS_WINDOWS TRUE)
else()
    set(CURRENT_PLATFORM "UNKNOWN")
endif()

# ;--------------------------------------------------------------------------------
# ; Compiler Flags
# ;--------------------------------------------------------------------------------
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_C_FLAGS "")

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++ -D__MACOSX_CORE__")

add_compile_options(-Wno-deprecated-declarations)

# ;--------------------------------------------------------------------------------
# ; Source Files
# ;--------------------------------------------------------------------------------
set(SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/hello.cpp
)

# ;--------------------------------------------------------------------------------
# ; Haders Files
# ;--------------------------------------------------------------------------------
include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

# ;--------------------------------------------------------------------------------
# ; Properties
# ;--------------------------------------------------------------------------------
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/${CMAKE_PROJECT_NAME}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/${CMAKE_PROJECT_NAME}/bin)

# ;--------------------------------------------------------------------------------
# ; Compile
# ;--------------------------------------------------------------------------------
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# ;--------------------------------------------------------------------------------
# ; Generate Compilation Database
# ;--------------------------------------------------------------------------------
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# ;--------------------------------------------------------------------------------
# ; Run Target Definitios
# ;--------------------------------------------------------------------------------
if(CURRENT_PLATFORM_IS_OSX)
    message(STATUS "Run targets specified for type [${PROJECT_TYPE}] on platform [${CURRENT_PLATFORM}]")
    string(TOLOWER "${PROJECT_TYPE}" _project_type)
    if(${PROJECT_TYPE} STREQUAL "Command Line Tool")
        add_custom_target(run
            COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}
            DEPENDS ${PROJECT_NAME}
            WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
            COMMENT "Running generated ${_project_type} ${PROJECT_NAME} from ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
            )
    elseif(${PROJECT_TYPE} STREQUAL "Application")
        message(STATUS "application")
        add_custom_target(run
            COMMAND open ${CMAKE_BUILD_TYPE}/${APP_NAME}.app
            DEPENDS ${PROJECT_NAME}
            COMMENT "Running generated ${_project_type} ${PROJECT_NAME} from ${CMAKE_BUILD_TYPE}/${PROJECT_NAME}.app/Contents/MacOS/${PROJECT_NAME}"
            )
    else()
        message(WARNING "Unknown application type: ${PROJECT_TYPE}")
    endif()
elseif(CURRENT_PLATFORM_IS_LINUX)
    message(STATUS "No run targets specified for ${CURRENT_PLATFORM}")
elseif(CURRENT_PLATFORM_IS_WINDOWS)
    message(STATUS "No run targets specified for ${CURRENT_PLATFORM}")
endif()

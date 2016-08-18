# ;--------------------------------------------------------------------------------
# ; Initials
# ;--------------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.8)
project(working)

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
        src/main.cpp)

# ;--------------------------------------------------------------------------------
# ; Properties
# ;--------------------------------------------------------------------------------
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}/bin)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# ;--------------------------------------------------------------------------------
# ; Generate Compilation Database
# ;--------------------------------------------------------------------------------
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME}
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/compile_commands.json ${PROJECT_SOURCE_DIR}
    )

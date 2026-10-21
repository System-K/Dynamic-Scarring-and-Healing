# It's recommended to set a minimum CMake version.
# If you use CMake features from higher versions, update this to match.
cmake_minimum_required(VERSION 3.21)

# Set your project name. This will be the name of your SKSE .dll file.
project(DynamicScarringAndHealing VERSION 0.0.1 LANGUAGES CXX)


#
# YOU DO NOT NEED TO EDIT ANYTHING BELOW HERE
#
# Please see the "Project setup" section of README.md
#

# If you're not using a mod manager, you probably want the SKSE plugin to go
# inside of your Skyrim "Data" folder.
#
# To do this automatically, set the `SKYRIM_FOLDER` environment variable
# to the path of your Skyrim Special Edition folder
if(DEFINED ENV{SKYRIM_FOLDER} AND IS_DIRECTORY "$ENV{SKYRIM_FOLDER}/Data")
    set(OUTPUT_FOLDER "$ENV{SKYRIM_FOLDER}/Data")
endif()

# If you're using Mod Organizer 2 or Vortex, you might want this to go inside
# of your "mods" folder, inside of a subfolder named "<your mod>".
#
# To do this automatically, set the `SKYRIM_MODS_FOLDER` environment variable
# to the path of your "mods" folder
if(DEFINED ENV{SKYRIM_MODS_FOLDER} AND IS_DIRECTORY "$ENV{SKYRIM_MODS_FOLDER}")
    set(OUTPUT_FOLDER "$ENV{SKYRIM_MODS_FOLDER}/Dynamic Scarring and Healing")
endif()

# Otherwise, you can set OUTPUT_FOLDER to any place you'd like :)
# set(OUTPUT_FOLDER "C:/path/to/any/folder")

# Setup your SKSE plugin as an SKSE plugin!
# SKSE-Hotfixes: build against CommonLibSSE-NG 11 via add_subdirectory (Address Library v5, Skyrim 1.7.104)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(ENABLE_SKYRIM_SE ON CACHE BOOL "" FORCE)
set(ENABLE_SKYRIM_AE ON CACHE BOOL "" FORCE)
set(ENABLE_SKYRIM_VR ON CACHE BOOL "" FORCE)
set(BUILD_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory("$ENV{COMMONLIB_SSE_FOLDER}" "${CMAKE_CURRENT_BINARY_DIR}/_deps/clib-build")
get_target_property(COMMONLIB_SRC_DIR CommonLibSSE SOURCE_DIR)
include("${COMMONLIB_SRC_DIR}/cmake/CommonLibSSE.cmake")
# SKSE-Hotfixes: sources include "Logger.h" / "PluginDetection.h" but the files are logger.h / pluginDetection.h (case-sensitive on Linux) -> include aliases
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/include_alias/Logger.h" "#include \"${CMAKE_CURRENT_SOURCE_DIR}/logger.h\"\n")
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/include_alias/PluginDetection.h" "#include \"${CMAKE_CURRENT_SOURCE_DIR}/pluginDetection.h\"\n")
add_commonlibsse_plugin(${PROJECT_NAME} SOURCES
plugin.cpp
pluginDetection.cpp
overlays.cpp
mcm.cpp
logger.cpp
random.cpp
NAME "DynamicScarringAndHealing" AUTHOR "endermannnn" VERSION 0.0.1
) # <--- specifies plugin.cpp
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/include_alias")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23) # <--- use C++23 standard
target_precompile_headers(${PROJECT_NAME} PRIVATE PCH.h) # <--- PCH.h is required!

# When your SKSE .dll is compiled, this will automatically copy the .dll into your mods folder.
# Only works if you configure DEPLOY_ROOT above (or set the SKYRIM_MODS_FOLDER environment variable)
if(DEFINED OUTPUT_FOLDER)
    # If you specify an <OUTPUT_FOLDER> (including via environment variables)
    # then we'll copy your mod files into Skyrim or a mod manager for you!

    # Copy the SKSE plugin .dll files into the SKSE/Plugins/ folder
    set(DLL_FOLDER "${OUTPUT_FOLDER}/SKSE/Plugins")

    message(STATUS "SKSE plugin output folder: ${DLL_FOLDER}")

    add_custom_command(
        TARGET "${PROJECT_NAME}"
        POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E make_directory "${DLL_FOLDER}"
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:${PROJECT_NAME}>" "${DLL_FOLDER}/$<TARGET_FILE_NAME:${PROJECT_NAME}>"
        VERBATIM
    )

    # If you perform a "Debug" build, also copy .pdb file (for debug symbols)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_custom_command(
            TARGET "${PROJECT_NAME}"
            POST_BUILD
            COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_PDB_FILE:${PROJECT_NAME}>" "${DLL_FOLDER}/$<TARGET_PDB_FILE_NAME:${PROJECT_NAME}>"
            VERBATIM
        )
    endif()
endif()

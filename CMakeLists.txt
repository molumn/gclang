cmake_minimum_required(VERSION 3.27)
project(gclang
        VERSION 0.0.0
        LANGUAGES CXX
)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules")

include(ProjectConfigurations)

add_subdirectory(gclang)




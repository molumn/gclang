















file(GLOB_RECURSE GCLANG_COMMON_SRCS
        "common/*.cpp"
)
file(GLOB_RECURSE GCLANG_FRONTEND_SRCS
        "frontend/*.cpp"
)
file(GLOB_RECURSE GCLANG_MIDDLEWARE_SRCS
        "middleware/*.cpp"
)
file(GLOB_RECURSE GCLANG_BACKEND_SRCS
        "backend/*.cpp"
)


include_directories(
        PUBLIC "${PROJECT_SOURCE_DIR}/include"
)

add_executable(gclang
        ${GCLANG_COMMON_SRCS}
        ${GCLANG_FRONTEND_SRCS}
        ../include/gclang/common/arguments.hpp
        common/arguments.cpp
)
add_executable(gclang-mm
        ${GCLANG_COMMON_SRCS}
        ${GCLANG_MIDDLEWARE_SRCS}
)
add_executable(gclang-vm
        ${GCLANG_COMMON_SRCS}
        ${GCLANG_BACKEND_SRCS}
)

add_custom_command(
        TARGET gclang
        TARGET gclang-mm
        TARGET gclang-vm
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${PROJECT_SOURCE_DIR}/example/.gcl"
        COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:gclang>" "${PROJECT_SOURCE_DIR}/example/.gcl/gclang"
        COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:gclang-mm>" "${PROJECT_SOURCE_DIR}/example/.gcl/gclang-mm"
        COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:gclang-vm>" "${PROJECT_SOURCE_DIR}/example/.gcl/gclang-vm"
)



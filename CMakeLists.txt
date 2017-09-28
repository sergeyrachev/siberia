cmake_minimum_required(VERSION 3.0)
project(siberia)

find_package( wxWidgets CONFIG PATHS deps )

add_executable(siberia WIN32
    src/main.cpp
)

target_include_directories(siberia PRIVATE ${wxWidgets_INCLUDE_DIRS})
target_compile_definitions(siberia PRIVATE ${wxWidgets_DEFINITIONS})
target_link_libraries(siberia ${wxWidgets_LIBRARIES})

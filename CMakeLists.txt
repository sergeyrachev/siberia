cmake_minimum_required(VERSION 3.0)
project(siberia)

find_package( wx CONFIG PATHS deps )
add_executable(siberia WIN32
        src/main.cpp
        src/main_window.cpp src/main_window.h )

target_compile_features( siberia PUBLIC cxx_std_17 )
target_include_directories(siberia PRIVATE ${wxWidgets_INCLUDE_DIRS})
target_compile_definitions(siberia PRIVATE ${wxWidgets_DEFINITIONS})
target_link_libraries(siberia ${wxWidgets_LIBRARIES})

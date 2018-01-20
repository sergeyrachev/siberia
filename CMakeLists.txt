cmake_minimum_required(VERSION 3.0)
project(siberia)

find_package( wx CONFIG PATHS deps )
add_executable(siberia WIN32
        src/main.cpp
        src/main_window.cpp src/main_window.h src/main_menu_bar.cpp src/main_menu_bar.h src/main_tool_bar.cpp src/main_tool_bar.h src/main_status_bar.cpp src/main_status_bar.h )

target_compile_features( siberia PUBLIC cxx_std_17 )
target_include_directories(siberia PRIVATE ${wxWidgets_INCLUDE_DIRS})
target_include_directories(siberia PRIVATE res)
target_compile_definitions(siberia PRIVATE ${wxWidgets_DEFINITIONS} )
target_link_libraries(siberia ${wxWidgets_LIBRARIES})

cmake_minimum_required(VERSION 3.10)
project(07_abstract_factory_pattern)

set(HEADERS include/Dummy.h)

set(SOURCES src/Dummy.cpp src/Widget.cpp include/Widget.h include/CheckBoxKdeWidget.h include/ListKdeWidget.h include/ButtonKdeWidget.h include/CheckBoxGnomeWidget.h include/ListGnomeWidget.h include/ButtonGnomeWidget.h include/KdeWidgetFactory.h include/GnomeWidgetFactory.h include/WidgetFactory.h include/Demo.h src/ButtonGnomeWidget.cpp src/ButtonKdeWidget.cpp src/CheckBoxGnomeWidget.cpp src/CheckBoxKdeWidget.cpp src/Demo.cpp src/GnomeWidgetFactory.cpp src/KdeWidgetFactory.cpp src/ListGnomeWidget.cpp src/ListKdeWidget.cpp src/WidgetFactory.cpp)

add_library(07_abstract_factory_pattern_lib ${HEADERS} ${SOURCES})
target_include_directories(07_abstract_factory_pattern_lib PUBLIC include)

add_executable(07_abstract_factory_pattern src/main.cpp)
target_link_libraries(07_abstract_factory_pattern 07_abstract_factory_pattern_lib)

add_subdirectory(uml)
add_subdirectory(external)
add_subdirectory(test)
add_subdirectory(bench)

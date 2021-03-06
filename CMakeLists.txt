cmake_minimum_required(VERSION 3.13)
project(HousePriceGenerator)
set(CMAKE_CXX_STANDARD 14)

macro(add_example name)
    add_executable(${name} ${name}.cpp)
endmacro()


if (DLIB_NO_GUI_SUPPORT)
    message("No GUI support, so we won't build the sleep_detection example.")
else()
    find_package(OpenCV QUIET)
    if (OpenCV_FOUND)
        include_directories(${OpenCV_INCLUDE_DIRS})
        add_executable(HousePriceGenerator main.cpp src/videoStream.cpp headers/videoStream.h)
        target_link_libraries(HousePriceGenerator ${OpenCV_LIBS} )
    else()
        message("OpenCV not found, so we won't build the sleep_detection example.")
    endif()
endif()
#dke_minimum_required(VERSION 2.4.6)

project(mowerRobot)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wall  -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall  -O3")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

find_package(OpenCV REQUIRED)

include_directories(
        ${PROJECT_SOURCE_DIR}/src
)

add_executable(
    ${PROJECT_NAME}
	src/board_detect.cpp
	src/EdgeDetect.cpp
)
target_link_libraries(
    ${PROJECT_NAME}
	${OpenCV_LIBS}
)

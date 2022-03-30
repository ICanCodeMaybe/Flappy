cmake_minimum_required(VERSION 3.18.1)

project(Flappy)

set(FLAPPY_CPP Flappy/src/main.cpp Flappy/src/entity.cpp)
set(FLAPPY_H Flappy/src/entity.h)

add_executable(${PROJECT_NAME} ${FLAPPY_CPP} ${FLAPPY_H})

add_subdirectory(Little2DRenderer/Little/ Little/)

target_include_directories(${PROJECT_NAME}
    PUBLIC Little2DRenderer/Little/
    PUBLIC Little2DRenderer/Little/include/
)

target_link_directories(${PROJECT_NAME}
    PRIVATE Little2DRenderer/Little/
    PRIVATE Little2DRenderer/Little/src/ 
)

target_link_libraries(${PROJECT_NAME} Little)
cmake_minimum_required(VERSION 3.26)
project(bouncing_ball_game)

set(CMAKE_CXX_STANDARD 17)

include_directories(common components)
add_executable(bouncing_ball_game main.cpp
        common/colors.h
        common/themes.h
        components/settings.h
        components/structs.h
        components/game.h
        components/window.h
        components/filemanage.h
)

target_link_libraries(${PROJECT_NAME} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)
#target_link_libraries(${PROJECT_NAME} -lSDL2 -lSDL2_gfx -lSDL2_image -lSDL2_ttf -lSDL2_mixer)

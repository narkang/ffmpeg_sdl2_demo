cmake_minimum_required(VERSION 3.16)
project(SDL_Learn)

set(CMAKE_CXX_STANDARD 14)

# 声明一个变量 SDL_DIR 为 SDL 安装路径
set(SDL_DIR "D:/ndk_demo/SDL2-devel-2.0.14-mingw.tar/SDL2-devel-2.0.14-mingw/SDL2-2.0.14/x86_64-w64-mingw32")

# 设置要包含的头文件的路径
include_directories(${SDL_DIR}/include)
# 设置要关联的库的路径
link_directories(${SDL_DIR}/lib)

add_executable(SDL_Learn
#        sdl2/main.cpp
#        sdl2/main2.cpp
#        sdl2/main3.cpp
#        sdl2/main4.cpp
#        sdl2/main5.cpp
#        sdl2/main6.cpp
#
#        ffmpeg/main.cpp
#        ffmpeg/main2.cpp
#        ffmpeg/FFmpeg_video_decode.cpp
        ffmpeg/ffplay.c
        )

target_link_libraries(SDL_Learn
        mingw32
        SDL2main
        SDL2
        SDL2_image

        -Wl,--start-group
        avcodec avfilter avformat avutil swresample swscale
        -Wl,--end-group
        )
#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

//https://blog.csdn.net/ronaldinho2014/article/details/104835426
//https://glumes.com/post/ffmpeg/av-beginner-001/
//https://glumes.com/post/ffmpeg/av-beginner-002/
int main2(int argc, char *argv[]){
    cout << "hello sdl2" << endl;

    int width = 400;
    int height = 400;
    SDL_Window *window = SDL_CreateWindow("Hello SDL",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          width,height,
                                          SDL_WINDOW_ALLOW_HIGHDPI);

    SDL_Renderer* pRenderer = NULL;
    // 创建渲染器
    pRenderer = SDL_CreateRenderer(window, -1, 0);
    // 指定渲染颜色
    SDL_SetRenderDrawColor(pRenderer,0,255,0,255);
    // 清空当前窗口的颜色
    SDL_RenderClear(pRenderer);
    // 执行渲染操作，更新窗口
    SDL_RenderPresent(pRenderer);

    SDL_Event windowEvent;
    while (true){
        if (SDL_PollEvent(&windowEvent)){
            if (SDL_QUIT == windowEvent.type){
                //当退出循环时，要执行销毁操作，把创建的 SDL_Window 和 SDL_Renderer 都释放了。
                SDL_DestroyWindow(window);
                SDL_DestroyRenderer(pRenderer);
                SDL_Quit();
                break;
            }
        }
    }

    return 0;
}

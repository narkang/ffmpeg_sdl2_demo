#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

//https://blog.csdn.net/ronaldinho2014/article/details/104835426
//https://glumes.com/post/ffmpeg/av-beginner-001/
//https://glumes.com/post/ffmpeg/av-beginner-002/
//https://glumes.com/post/ffmpeg/av-beginner-003/
//https://glumes.com/post/ffmpeg/av-beginner-004/
int main3(int argc, char *argv[]){

//    SDL 加载并显示一张图片
//  SDL_image下载地址 https://www.libsdl.org/projects/SDL_image/

    int width = 1008;
    int height = 196;
    SDL_Window *pWindow = SDL_CreateWindow("Hello SDL",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          width,height,
                                          SDL_WINDOW_ALLOW_HIGHDPI);

    SDL_Renderer* pRenderer = NULL;
    // 创建渲染器
    pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
    // 指定渲染颜色
    SDL_SetRenderDrawColor(pRenderer,0,255,0,255);
    // 清空当前窗口的颜色
    SDL_RenderClear(pRenderer);
    // 执行渲染操作，更新窗口
    SDL_RenderPresent(pRenderer);

    // 得到 SDL_Window 的 SDL_Surface
    SDL_Surface *pWindowSurface = SDL_GetWindowSurface(pWindow);
    // 根据图片创建一个 SDL_Surface
    SDL_Surface *pImageSurface = IMG_Load("D:\\myProject\\SDL_Learn\\test3.png");

    SDL_Event windowEvent;

    bool bQuit = false;

    while (!bQuit){
        //从消息队列取出消息
        if (SDL_PollEvent(&windowEvent)){
            if (SDL_QUIT == windowEvent.type){
                //当退出循环时，要执行销毁操作，把创建的 SDL_Window 和 SDL_Renderer 都释放了。
                SDL_DestroyWindow(pWindow);
                SDL_DestroyRenderer(pRenderer);
                SDL_Quit();
                break;
            } else if(SDL_KEYDOWN == windowEvent.type){
                if (windowEvent.key.keysym.sym == SDLK_SPACE){
                    cout << "user click space \n" << endl;
                }
            }
        }

        // 将 pImageSurface 的内容传输到 上
        SDL_BlitSurface(pImageSurface, nullptr,pWindowSurface,nullptr);
        // 上屏操作，将 Surface 内容显示到屏幕上
        SDL_UpdateWindowSurface(pWindow);
    }

    return 0;
}

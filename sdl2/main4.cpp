#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

//https://blog.csdn.net/ronaldinho2014/article/details/104835426
//https://glumes.com/post/ffmpeg/av-beginner-001/
//https://glumes.com/post/ffmpeg/av-beginner-002/
//https://glumes.com/post/ffmpeg/av-beginner-003/
//https://glumes.com/post/ffmpeg/av-beginner-004/
//https://glumes.com/post/ffmpeg/av-beginner-005/
int main4(int argc, char *argv[]){

//    SDL 加载并显示一张图片
//  SDL_image下载地址 https://www.libsdl.org/projects/SDL_image/

    int width = 588;
    int height = 121;
    SDL_Window *pWindow = SDL_CreateWindow("Hello SDL",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          width,height,
                                          SDL_WINDOW_ALLOW_HIGHDPI);

    SDL_Renderer* pRenderer = NULL;
    // 创建渲染器
    pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
    //创建纹理
    SDL_Texture* texture = SDL_CreateTexture(pRenderer, SDL_PIXELFORMAT_IYUV, SDL_TEXTUREACCESS_STATIC, width, height);

    // 打开文件
    FILE *pFile = fopen("D:\\myProject\\SDL_Learn\\yuv_filename.yuv", "rb");
    // 读取文件内容到 buffer 中
    unsigned char *yuv_data;
    // yuv420p 格式的文件大小
    int frameSize = width * height * 3 / 2;
    yuv_data = static_cast<unsigned char *>(malloc(frameSize * sizeof(unsigned char)));
    fread(yuv_data,1,frameSize,pFile);
    // 关闭文件
    fclose(pFile);

    SDL_Event windowEvent;

    bool bQuit = false;

    if(texture != nullptr){
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

            // 更新纹理内容，就是把读取的 YUV 数据转换成纹理
            SDL_UpdateTexture(texture, nullptr,yuv_data,width);
            // 清屏操作
            SDL_RenderClear(pRenderer);
            // 将指定纹理复制到要渲染的地方
            SDL_RenderCopy(pRenderer,texture, nullptr, nullptr);
            // 上屏操作
            SDL_RenderPresent(pRenderer);
        }
    }

    return 0;
}

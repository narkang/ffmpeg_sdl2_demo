#include <iostream>
#include <SDL2/SDL.h>

extern "C"{
    #include <libavformat/avformat.h>
}


using namespace std;

/**
 * 环境检验是否成功
 * @param argc
 * @param argv
 * @return
 */
int main1(int argc, char *argv[]){

    SDL_Init();

    int version = avcodec_version();
    cout<<"version:"<<version<<endl;

    return 0;
}

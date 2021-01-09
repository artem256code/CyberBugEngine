#include "render.hpp"

SDL_Renderer* Render::renderer = nullptr;

void Render::createWindow(const std::string title, const int width, const int height){
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL_Init failed: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
    window = SDL_CreateWindow(title.c_str(),
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              width,
                              height,
                              SDL_WINDOW_OPENGL);

    if(window == nullptr){
        std::cout << "SDL_CreateWindow failed: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }


    renderer = SDL_CreateRenderer(window,
                                  -1,
                                  SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr){
        std::cout << "SDL_CreateRenderer failed: " << SDL_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
}

SDL_Renderer* Render::getRenderer(){
    return renderer;
}

void Render::draw(){
    SDL_RenderClear(renderer);
    for(std::list<Object*>::iterator iter = buffer.getBuffer()->begin(); iter != buffer.getBuffer()->end(); iter++){
       SDL_RenderCopy(renderer,
                      (*iter)->getTexture(),
                      nullptr,
                      (*iter)->getRect());
    }
    SDL_RenderPresent(renderer);
}

Render::~Render(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}


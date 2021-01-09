#ifndef RENDER_HPP
#define RENDER_HPP

#include <iostream>
#include <SDL2/SDL.h>

#include "buffer.hpp"

class Render{
private:
    SDL_Window   *window;
    static SDL_Renderer *renderer;
    Buffer buffer;
private:
    void draw();
public:
    void createWindow(const std::string title, const int width, const int height);
    void update();
    static SDL_Renderer *getRenderer();
    ~Render();
};


#endif // RENDER_HPP

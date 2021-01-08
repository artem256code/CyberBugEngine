#ifndef RENDER_HPP
#define RENDER_HPP

#include <iostream>
#include <SDL2/SDL.h>

class Render{
private:
    SDL_Window   *window;
    SDL_Renderer *renderer;
private:
    void clear();
    void draw();
public:
    void createWindow(const std::string title, const int width, const int height);
    void update();
};

#endif // RENDER_HPP

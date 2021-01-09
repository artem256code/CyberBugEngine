#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>
#include <SDL2/SDL.h>


class Object{
private:
    SDL_Rect *rect;
    SDL_Texture* texture;
private:
    SDL_Texture* loadTexture(const std::string pathToTexture);
public:
    SDL_Rect*    getRect();
    SDL_Texture* getTexture();
    Object(const int x, const int y, const int width, const int height, const std::string pathToTexture);
    ~Object();
};

#endif // OBJECT_HPP

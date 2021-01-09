#include <SDL2/SDL_image.h>
#include "render.hpp"
#include "object.hpp"

SDL_Texture* Object::loadTexture(const std::string pathToTexture){
    SDL_Surface * temp_surf = IMG_Load(pathToTexture.c_str());

    if (temp_surf == nullptr) {
        std::cout << "Can't load image: " << IMG_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Render::getRenderer(), temp_surf);
    if(texture == nullptr) {
        std::cout << "Can't convert image to texture: " << IMG_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }
    return texture;
}

SDL_Rect*       Object::getRect()      {return rect;}
SDL_Texture*    Object::getTexture()   {return texture;}

Object::Object(const int x, const int y,
                const int width, const int height, const std::string pathToTexture){
    rect = new SDL_Rect{x, y, width, height};
    texture = loadTexture(pathToTexture);
}

Object::~Object(){
    delete rect;
    SDL_DestroyTexture(texture);
}

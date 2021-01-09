#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <list>
#include <SDL2/SDL.h>

#include "object.hpp"

class Buffer{
private:
    std::list<Object*> buffer;
public:
    std::list<Object*> *getBuffer();
    void pushBack(Object *const object);
    void clear();
};


#endif // BUFFER_HPP

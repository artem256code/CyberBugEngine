#include "buffer.hpp"

std::list<Object*> *Buffer::getBuffer(){
    return &buffer;
}

void Buffer::pushBack(Object *const object){
    buffer.push_back(object);
}

void Buffer::clear(){
    buffer.clear();
}

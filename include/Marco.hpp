#pragma once
#include <Dibujo.hpp>
#include <incurses.h>

class Marco
{
private:
    /* data */
public:
    Marco(/* args */) {}
    ~Marco() {}
    void Dibujar(){
        box(stdscr, '#', '#');
    }
};
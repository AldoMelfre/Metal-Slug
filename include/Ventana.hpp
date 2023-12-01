#pragma once
#include <curses.h>
#include <iostream>
#include <unistd.h>

class Ventana
{
private:
    int x;
    int y;
    bool ejecucion;
    int velocidad;
    int contador;

public:
    Ventana()
    {
        initscr();
        getmaxyx(stdscr, this->y, this->x);
        this->ejecucion = false;
        this->velocidad = 10;
        this->contador = 20;
        curs_set(FALSE);
        cbreak();
        timeout(100);
        noecho();
        keypad(stdscr, TRUE);
    }

    void Actualizar()
    {
        this->contador = this->contador - 1;
        if (this->contador == 0)
        {
            this->Cerrar();
        }
    }
    void Dibujar()
    {
        box(stdscr, 'E', 'Z');
    }
    void Cerrar()
    {
        this->ejecucion = false;
    }
    ~Ventana()
    {
        endwin();
    }
};
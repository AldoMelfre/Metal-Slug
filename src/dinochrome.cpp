#include <Ventana.hpp>
#include <Dibujo.hpp>
#include <Actualizable.hpp>
#include <Controlador.hpp>
#include <Dinosaurio.hpp>
#include <curses.h>
#include <unistd.h>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
    Ventana v;
    Dinosaurio* dino = new Dinosaurio(); 
    Controlador* control = new  Controlador();
    Dibujo* d1 = new Dibujo(1,1,"cow");
    Dibujo* d2 = new Dibujo(15,1,"cowwalk");
    Dibujo* d3 = new Dibujo(5,10,"UFO");
    list<Dibujo*> dibujos;
    dibujos.push_back(d1);
    dibujos.push_back(d2);
    dibujos.push_back(d3);
    dibujos.push_back(dino);
    list<Actualizable*> actualizables;
    actualizables.push_back(control);
    actualizables.push_back(dino);
    bool ejecutar = true;
    while (ejecutar)
    {
        v.actualizar(actualizables);
        v.dibujar(dibujos);
    }

    return 0;
}
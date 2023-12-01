#include <Ventana.hpp>
#include <Dibujo.hpp>
#include <curses.h>
#include <unistd.h>

using namespace std;

int main(int argc, char const *argv[])
{//
    // cout<<"Press 'd' to --> ,  Press 'a' to <-- , Press 'q' to quit "<<endl;
    // Tamaño de pagina recomendado 55%
    Ventana v;

    Dibujo d1(10, 10, "player");
    Dibujo d2(1, 1, "escenario");
    Dibujo d3(1, 1, "bala");//hh
    int coordenadaX = d1.ObtenerX(); // Obtener la coordenada X de d1
    int coordenadaY = d1.ObtenerY(); // Obtener la coordenada Y de d1

    bool ejecucion = true;
    while (ejecucion)
    {
        // ciclo de actualización
        v.Actualizar();
        if (getch() == 'q')
        {
            ejecucion = false;
        }
        if (getch() == 'd')
        {
            d1.AvanzarX(4);
        }
        if (getch() == 'a')
        {
            d1.RetrocederX(4);
        }
        if (getch() == 's')
        {
            d1.BajarY(3);
        }
        if (getch() == 'w')
        {
            d1.SubirY(3);
        }
        if (getch() == 'f') // Disparar
        {
            Dibujo d3(coordenadaX + 5, coordenadaY, "bala");
            d3.Dibujar();
        }

        // ciclo de dibujo
        clear();

        // v.Dibujar();
        d2.Dibujar();
        d1.Dibujar();


        refresh();
        usleep(41000);
    }

    return 0;
}

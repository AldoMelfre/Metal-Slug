#include <Ventana.hpp>
#include <Dibujo.hpp>
#include <Actualizable.hpp>
#include <Controlador.hpp>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main(int argc, char const *argv[])
{ //
    SDL_Surface *ecran = NULL;
    chargement_SDL(&ecran);
    SDL_Surface *menu, *over_game;
    menu = IMG_Load("images/menu.png");
    over_game = IMG_Load("images/game_over.png");
    SDL_Rect position_menu;
    position_menu.x = 0;
    position_menu.y = 0;
    int exit_jeu = 0;
    int debut_stage = 0;
    int game_over = 0;

    bool ejecucion = true;
    while (ejecucion)
    {
        // ciclo de actualización
        v.Actualizar();
        // Movimiento del jugador
        float velocidad = 5.0f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            character.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            character.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            character.move(0, velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            character.move(0, velocidad);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            v.Actualizar();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
        {
            jugador.disparar();
        }

        window.clear();
        window.draw(jugador.sprite);
        window.display();
    }

    return 0;
}

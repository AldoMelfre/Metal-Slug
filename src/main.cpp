#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Soldado.hpp>
#include <Boss.hpp>

int main()
{
    double velocidad = 0.1;

    sf::Texture texture;
    if (!texture.loadFromFile("./assets/images/stage1.png"))
    {
        // Manejar el error si no se puede cargar la imagen
        return -1;
    }
    // Crear un sprite y asignarle la textura
    sf::Sprite sprite(texture);

    sf::Music music;
    if (!music.openFromFile("./assets/music/Metal-slug-2-Soundtrack-1-Judgment.ogg"))
    {
        // Error al cargar el archivo de música
        return -1;
    }

    // Reproducir la música
    music.play();

    // Cargar una fuente de texto
    sf::Font font2;
    if (!font2.loadFromFile("./assets/fonts/Metal Slug Latino Regular.ttf"))
    {
        // Manejar el error si no se puede cargar la fuente
        return -1;
    }
    // Crear un objeto de texto LOTR
    sf::Text text2;
    text2.setFont(font2);
    text2.setString("METAL SLUG");
    text2.setCharacterSize(80);
    text2.setPosition(150, 100);
    text2.setFillColor(sf::Color::Red);

    sf::RenderWindow window(sf::VideoMode(1800, 300), "Metal Slug");

    Soldado prota(sf::Vector2f(200, 300), sf::Color::Red);
    Boss jefe(sf::Vector2f(700, 250), sf::Color::Red);

    //Tamano del sprite reescalado
    prota.setScale(1.5f, 1.5f); 
    // jefe.setScale(1.5f, 1.5f); 

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            prota.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            prota.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            prota.move(0, velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            prota.move(0, velocidad);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            jefe.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            jefe.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            jefe.move(0, velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            jefe.move(0, velocidad);
        }

        // Actualizar animacion pikachu
        prota.update();
        jefe.update();

        window.clear();
        window.draw(sprite);
        prota.draw(window);
        jefe.draw(window);
        window.draw(text2);
        window.display();

        if (music.getStatus() != sf::Music::Playing)
        {
            window.close();
        }
    }

    return 0;
}


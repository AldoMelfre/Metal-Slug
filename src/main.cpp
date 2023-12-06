#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

sf::Color none = sf::Color(0, 0, 0, 0); // Color transparente

class Soldado
{
public:
    Soldado(sf::Vector2f position, sf::Color color)
    {
        shape.setSize(sf::Vector2f(50, 30));
        shape.setPosition(100, 0); // Posición inicial cuadro
        shape.setFillColor(none);

        // Cargar la imagen desde un archivo

        if (!texture.loadFromFile("./assets/images/pack_1_right.png"))
        {
        }

        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(20, 230); // Posición inicial sprite
    }

    void move(float offsetX, float offsetY)
    {
        sprite.move(offsetX, offsetY);
        shape.move(offsetX, offsetY);
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(this->shape);
        window.draw(this->sprite);
    }

    void update()
    {
        // Actualizar el frame de la animación
        if (clock.getElapsedTime().asSeconds() >= frameTime)
        {
            currentFrame = (currentFrame + 1) % numFrames;
            sprite.setTextureRect(sf::IntRect((currentFrame * 100) + 1, 0, 30, 40));
            clock.restart();
        }
    }
 
    //DEFINIENDO LA ESCALA DE LOS SPRITES COMO VARIABLE
    void setScale(float scaleX, float scaleY)
    {
        sprite.setScale(scaleX, scaleY);
    }

private:
    sf::RectangleShape shape;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    float frameTime = 0.08f; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int numFrames = 8; // Número total de frames en la animación
    int frameWidth = 33;
    int frameHeight = 30;
};

class Boss
{
public:
    Boss(sf::Vector2f position, sf::Color color)
    {
        shape.setSize(sf::Vector2f(33, 40));
        shape.setPosition(1500, 10); // Posición inicial cuadro
        shape.setFillColor(none);

        // Cargar la imagen desde un archivo

        if (!texture.loadFromFile("./assets/images/boss.png"))
        {
        }

        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(position); // Posición inicial sprite
    }

    void move(float offsetX, float offsetY)
    {
        sprite.move(offsetX, offsetY);
        shape.move(offsetX, offsetY);
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(this->shape);
        window.draw(this->sprite);
    }

    void update()
    {
        // Actualizar el frame de la animación
        if (clock.getElapsedTime().asSeconds() >= frameTime)
        {
            currentFrame = (currentFrame + 1) % numFrames;
            sprite.setTextureRect(sf::IntRect((currentFrame * 70) + 1, 680, 40, 70));
            clock.restart();
        }
    }

private:
    sf::RectangleShape shape;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Clock clock;
    float frameTime = 0.1f; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int numFrames = 11; // Número total de frames en la animación
    int frameWidth = 40;
    int frameHeight = 40;
};

double velocidad = 0.1;

int main()
{
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
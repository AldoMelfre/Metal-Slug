

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
            sprite.setTextureRect(sf::IntRect((currentFrame * 107) + 3, 107, 81, 49));
            clock.restart();
        }
    }

private:
    sf::Color none = sf::Color(0, 0, 0, 0); // Color tr
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

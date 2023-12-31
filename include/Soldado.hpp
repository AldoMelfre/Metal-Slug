

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
    sf::Color none = sf::Color(0, 0, 0, 0); // Color tr
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

#include <SFML/Graphics.hpp>
#include <chipmunk/chipmunk.h>

int main()
{
    // Crear una ventana de SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ejemplo de Física con Chipmunk y SFML");

    // Crear un espacio de Chipmunk
    cpSpace* space = cpSpaceNew();
    cpSpaceSetGravity(space, cpv(0, 1000)); // Establecer la gravedad

    // Crear un cuerpo estático en el espacio
    cpBody* staticBody = cpSpaceGetStaticBody(space);

    // Crear un suelo estático
    cpShape* ground = cpSegmentShapeNew(staticBody, cpv(0, 500), cpv(800, 500), 0);
    cpShapeSetFriction(ground, 1.0);
    cpSpaceAddShape(space, ground);

    // Crear un cuerpo dinámico
    cpFloat radius = 25.0;
    cpFloat mass = 1.0;
    cpFloat moment = cpMomentForCircle(mass, 0, radius, cpvzero);
    cpBody* ballBody = cpSpaceAddBody(space, cpBodyNew(mass, moment));
    cpBodySetPosition(ballBody, cpv(400, 300));

    // Crear una forma circular para el cuerpo
    cpShape* ballShape = cpCircleShapeNew(ballBody, radius, cpvzero);
    cpShapeSetFriction(ballShape, 0.7);
    cpSpaceAddShape(space, ballShape);

    // Bucle principal del juego
    while (window.isOpen())
    {
        // Procesar eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Controlar la bola con el teclado
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            cpBodyApplyImpulseAtWorldPoint(ballBody, cpv(-100, 0), cpvzero);
            // cpBodyApplyImpulse(ballBody, cpv(-100, 0), cpvzero);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            cpBodyApplyImpulseAtLocalPoint(ballBody, cpv(100, 0), cpvzero);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            cpBodyApplyImpulseAtLocalPoint(ballBody, cpv(0, -100), cpvzero);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            cpBodyApplyImpulseAtLocalPoint(ballBody, cpv(0, 100), cpvzero);

        // Actualizar el espacio de Chipmunk
        // Ajustar el valor de 1.0 / 60.0 para cambiar la velocidad de la simulación fisica
        cpSpaceStep(space, 1.0 / 60.0);

        // Limpiar la ventana
        window.clear();

        // Dibujar el suelo
        sf::RectangleShape groundShape(sf::Vector2f(800, 10));
        groundShape.setPosition(0, 490);
        window.draw(groundShape);

        // Dibujar la bola
        sf::CircleShape ballShape(radius);
        ballShape.setPosition(cpBodyGetPosition(ballBody).x - radius, cpBodyGetPosition(ballBody).y - radius);
        window.draw(ballShape);

        // Mostrar la ventana
        window.display();
    }

    // Liberar la memoria
    cpShapeFree(ground);
    cpShapeFree(ballShape);
    cpSpaceFree(space);

    return 0;
}

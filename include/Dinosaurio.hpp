#pragma once
#include <Dibujo.hpp>
#include <Actualizable.hpp>

class Dinosaurio : public Dibujo, public Actualizable
{
private:
    /* data */
public:
    Dinosaurio(/* args */) : Dibujo("Cow")
    {}
    void Actualizar()
    {

    }
    ~Dinosaurio() {}
};
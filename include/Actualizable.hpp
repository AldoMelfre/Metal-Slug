#pragma once
class Actualizable
{
private:
    /* data */
public:
    Actualizable(/* args */) {}
    virtual void Actualizar() = 0;
    ~Actualizable() {}
};
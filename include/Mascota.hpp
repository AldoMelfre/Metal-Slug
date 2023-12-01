#include <string>

class Mascota{
private:
    int hambre;
    std::string nombre;
    
public:
    Mascota(std::string nombre)
    {
        this->hambre = 0;
        this->nombre = nombre;
    }
    ~Mascota() {}
    void Jugar()
    {
        this->hambre += 5;
    }
    void Comer(int comida)
    {
        this->hambre -= comida;
    }
    std::string DecirNombre()
    {
        return this->nombre;
    }
    int DecirHambre()
    {
        return this->hambre;
    }
};


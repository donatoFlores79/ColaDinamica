#ifndef CONSTANCIA_H_INCLUDED
#define CONSTANCIA_H_INCLUDED

#include <iostream>
#include <string>

class Constancia{
private:
    std::string nombre, carrera;
    int materiasAprobadas;
    float promedio;
public:
    Constancia();
    Constancia(std::string, std::string, int, float);

    std::string getNombre() const;
    std::string getCarrera() const;
    int getMateriasAprobadas() const;
    float getPromedio() const;

    friend std::ostream& operator << (std::ostream& O, Constancia& x);
    friend std::istream& operator >> (std::istream& O, Constancia& x);

    Constancia& operator = (const Constancia&);
};

#endif // CONSTANCIA_H_INCLUDED

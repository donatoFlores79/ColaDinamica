#include "constancia.h"

using namespace std;

Constancia::Constancia(){};

Constancia::Constancia(string _nombre, string _carrera, int _materiasAprobadas, float _promedio){
    nombre = _nombre;
    carrera = _carrera;
    materiasAprobadas = _materiasAprobadas;
    promedio = _promedio;
}

string Constancia::getNombre() const{
    return nombre;
}

string Constancia::getCarrera() const{
    return carrera;
}

int Constancia::getMateriasAprobadas() const{
    return materiasAprobadas;
}

float Constancia::getPromedio() const{
    return promedio;
}

ostream& operator << (ostream& O, Constancia& x){
    O<< x.nombre << " | " << x.carrera << " | " << x. promedio << " | materias aprobadas: " << x.materiasAprobadas;
    return O;
}

istream& operator >> (istream& I, Constancia& x){
    cout<< "Nombre: ";
    I>> x.nombre;
    cout<< "Carrera: ";
    I>> x.carrera;
    cout<< "Materias aprobadas: ";
    I>> x.materiasAprobadas;
    cout<< "Promedio: ";
    I>> x.promedio;
    return I;
}

Constancia& Constancia::operator = (const Constancia& a){
    nombre = a.nombre;
    carrera = a.carrera;
    promedio = a.promedio;
    materiasAprobadas = a.materiasAprobadas;

    return *this;
}

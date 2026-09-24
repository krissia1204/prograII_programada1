#ifndef SATELITE_HPP
#define SATELITE_HPP
#include <string>
class Satelite{
    private:
        std:: string codigo;
        std:: string nombre;
        int tipo;
        int masa;
        int altitud;
        int capacidadE;
        int bateria;
        int potencia;
        int resolucion;
        int cobertura;

    public:
        Satelite(int tipo);
        ~Satelite();
        void mostrar();


};
#endif
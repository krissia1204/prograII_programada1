#ifndef ESTACION_TERRESTRE_HPP
#define ESTACION_TERRESTRE_HPP
#include "Satelite.hpp"
#include <iostream>

class Estacion_Terrestre{

    private:
        std::string codigo;
        std::string nombre;
        std:: string ubicacion;
        int max;
        Satelite* satelites[];
    public:
        Estacion_Terrestre();
        ~Estacion_Terrestre();
        void agregar_Enlace(Satelite* sat) ; 
        void eliminar_Enlace(std::string cod_Sat);
        void listar_sat();
};
#endif
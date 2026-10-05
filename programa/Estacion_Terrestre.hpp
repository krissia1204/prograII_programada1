#ifndef ESTACION_TERRESTRE_HPP
#define ESTACION_TERRESTRE_HPP
#include "Satelite.hpp"
#include <iostream>

class Estacion_Terrestre{

    private:
        std::string codigo;
        std::string nombre;
        std:: string ubicacion;
        static const int max= 5;
        Satelite* satelites[max];
    public:
        Estacion_Terrestre(std:: string cod, std:: string nom, std:: string ubi);
        ~Estacion_Terrestre();
        bool agregar_enlace(Satelite* sat) ; 
        void eliminar_enlace(std::string cod_sat);
        void listar_sat();

        std::string obtener_cod();
        std::string obtener_nombre();
        std:: string obtener_ubi();
};
#endif
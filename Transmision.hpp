#ifndef TRANSMISION_HPP
#define TRANSMISION_HPP
#include "Satelite.hpp"
#include "Estacion_Terrestre.hpp"
#include <string>

class Transmision{

    private:
        Estacion_Terrestre* estacion;
        Satelite* satelite;
        std:: string datos_transferidos;
        int ancho_banda;
        int potencia_empleada;
        int duracion;
        int energia_consumida;
        int tiempo_propagacion;
    public:
        Transmision(Estacion_Terrestre* e, Satelite* s, std::string datos);
        ~Transmision();
        int calcDuracion();
        int calcTP();
        int calcEC();
        void ejecutar();
};
#endif
#ifndef TRANSMISION_HPP
#define TRANSMISION_HPP
#include "Satelite.hpp"
#include "Estacion_Terrestre.hpp"
#include <string>

class Transmision{

    private:
        Estacion_Terrestre* estacion;
        Satelite* satelite;
        int datos_transferidos;
        int ancho_banda;
        int potencia_empleada;
        int duracion;
        int energia_consumida;
        int tiempo_propagacion;
    public:
        Transmision(Estacion_Terrestre* e, Satelite* s,int datos, int ancho_b,int potencia );
        ~Transmision();
        double calc_duracion();
        double calc_TP();
        double calc_EC();
        void ejecutar();
};
#endif
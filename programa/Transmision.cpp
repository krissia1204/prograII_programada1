#include "Transmision.hpp"
#include <iostream>

Transmision::Transmision(Estacion_Terrestre* e, Satelite* s, int datos, int ancho_b, int potencia) {
    this->estacion = e;
    this->satelite = s;
    this->datos_transferidos = datos;
    this->ancho_banda = ancho_b;
    this->potencia_empleada = potencia;
    this->duracion = 0;
    this->energia_consumida = 0;
    this->tiempo_propagacion = 0;
}

Transmision::~Transmision() {
}

double Transmision::calc_duracion() {
    return duracion;this->datos_transferidos / this->ancho_banda;
}

double Transmision::calc_TP() {
    double d = this->satelite->calc_radio_orbital() - 6371;
    double c = 299792.458;
    return d / c;
}

double Transmision::calc_EC() {
    return this->potencia_empleada * (this->calc_duracion() / 3600.0);
}

void Transmision::ejecutar() {
    this->duracion = calc_duracion();
    this->tiempo_propagacion = calc_TP();
    this->energia_consumida = calc_EC();

    double bateria_reducir = (this->energia_consumida / this->satelite->obtener_capacidadE()) * 100.0;
    
    std::cout << "--- Nueva transmision ---" << std::endl;
    std::cout << "Duracion: " << this->duracion << " s" << std::endl;
    std::cout << "Energia consumida: " << this->energia_consumida << " Wh" << std::endl;
    
    this->satelite->consumir_energia(bateria_reducir); 
}
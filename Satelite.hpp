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
        double bateria;
        double potencia;
        int ancho_banda;
        int resolucion;
        int cobertura;
        double historial_bateria[12];
        double historial_temperatura[12];
        int cantidadMuestras;

    public:
        Satelite(std:: string cod, std:: string nom, int tipo, 
            int masa,int altitud, int capcidad_e , double batt,
            double potencia, int ancho_banda  ){

            }
        ~Satelite();
        void agregar_muestra(double b, double t);
        double calc_radio_orbital() const;
        double calc_periodo_orbitalS() const;
        double calc_periodo_orbitalM() const;
        std:: string obtener_estado();
        void consumir_energia(double e);
        void recargarSolar(double potencia, double tiempo,double eficiencia);
        void mostrar_h_telemetria();
        double calc_prom_temp() const;
        double obtener_min_temp()const;
        double obtener_max_temp()const;
        double calc_prom_batt() const;
        double obtener_min_batt()const;
        double obtener_max_batt()const;
        void mostrar_info();

        //getters y setters

        std::string obtener_cod();



};
#endif
#ifndef CENTRO_CONTROL_HPP
#define CENTRO_CONTROL_HPP
#include "Satelite.hpp"
#include "Orbita.hpp"
#include "Estacion_Terrestre.hpp"
#include "Transmision.hpp"

class Centro_Control{

    private:
        static const int max_sat=10 ;
        static const int max_or= 4;
        static const int max_et= 3; 
        static const int max_tra= 20;
        Satelite** satelites;
        Orbita** orbitas;
        Estacion_Terrestre** estaciones;
        Transmision** transmisiones;
        int matriz_enlaces [max_sat][max_et];
    public:
        Centro_Control();
        ~Centro_Control();

        Satelite* buscar_satelite(std::string cod);
        Orbita* buscar_orbita(std::string cod);
        Estacion_Terrestre* buscar_et(std::string cod);

        void registrar_satelite(Satelite* sat);
        void registrar_orbita(Orbita* orb);
        void registrar_et(Estacion_Terrestre* et);

        void listar_sat();
        void listar_orb();

        void asignar_sat_orbita(Orbita* o, Satelite* s);
        bool crear_enlace(Estacion_Terrestre* e, Satelite* s);
        bool eliminar_enlace(Estacion_Terrestre* e, Satelite* s);
        void mostrar_enlaces();

        //obtener enlaces activos

        void realizar_transmision(std:: string cod_sat, std:: string cod_et, double datos, double ancho_b, double potencia);
        void reporte_general();
        // satelites criticos y consumo global

        //telemetria
        void registrar_muestra(Satelite* s,double b, double t );
        void mostrar_h_estadisticas(Satelite* s);

        //control energetico

        void consultar_bateria(Satelite* s);
        void recarga_solar(Satelite* s, double p, double t, double e);
        void listar_critico_fs();

        //auxiliares para el reporte general;
        int contar_sat();
        int contar_orb();
        int contar_est();
        int contar_enlaces();
        int contar_m_telemetria();
        void listar_s_critico();
        
        //transmision
        bool realizar_transmision(Satelite* sat, Estacion_Terrestre* est, int datos, int ancho_banda, int potenciaW);


};
#endif
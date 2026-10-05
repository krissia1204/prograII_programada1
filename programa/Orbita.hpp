#ifndef ORBITA_HPP
#define ORBITA_HPP
#include <string>
#include "Satelite.hpp"
class Orbita{

    private:
        std::string codigo;
        std::string nombre;
        int altitud_ref;
        static const int max_satelites=5;
        Satelite* satelites[max_satelites];
    public:
        Orbita(std::string cod, std::string nom, int alt);
        ~Orbita();
        bool asignarSatelite(Satelite* sat);
        bool contiene_sat(std:: string cod);
        void listar_sat() const;

        std::string obtener_codigo();

        std::string obtener_nombre();
        int obtener_alt();
        

};
#endif 
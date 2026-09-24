#ifndef ORBITA_HPP
#define ORBITA_HPP
#include <string>
#include "Satelite.hpp"
class Orbita{

    private:
        std::string codigo;
        std::string nombre;
        int altitud_Ref;
        int max_Satelites;
        Satelite* satelites[];
    public:
        Orbita();
        ~Orbita();
        

};
#endif 
#include <iostream>
#include "Satelite.hpp"
#include "Orbita.hpp"

Orbita:: Orbita(std::string cod, std::string nom, int alt){

    this->codigo= cod;
    this->nombre= nom;
    this->altitud_ref= alt;
    for(int i=0;i<max_satelites;i++){satelites[i]=nullptr;}

}

Orbita:: ~Orbita(){
    
}

bool Orbita:: asignarSatelite(Satelite* sat){
    bool encontrado= false;
    for(int i= 0; i<max_satelites;i++){
        if(satelites[i]==nullptr){
            
            satelites[i]= sat;
            encontrado= true;
            return encontrado;
        }
    }

    std::cout<<"No hay espacio"<<std::endl;
    return encontrado;  
}

bool Orbita:: contiene_sat(std:: string cod){
    bool encontrado= false;
    for(int i= 0; i<this->max_satelites; i++){
        if(satelites[i]->obtener_cod()==cod){
            encontrado = true;
            return encontrado;
        }
    }
    return encontrado;
}

void Orbita:: listar_sat() const{

    std::cout<<"Satelites en Orbita "<<nombre<<": "<<std::endl;
    for(int i=0; i<max_satelites;i++){
        std::cout<<i+1<<"-";
        satelites[i]->mostrar_info();
    }
}

std::string Orbita:: obtener_codigo(){
    return this->codigo;
}

std::string Orbita:: obtener_nombre(){
    return this->nombre;
}

int Orbita:: obtener_alt(){
    return this->altitud_ref;
}


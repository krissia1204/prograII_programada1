#include <iostream>
#include "Satelite.hpp"
#include "Estacion_Terrestre.hpp"

Estacion_Terrestre:: Estacion_Terrestre(std:: string cod, std:: string nom, std:: string ubi){
    this->codigo= cod;
    this->nombre=nom;
    this->ubicacion= ubi;
    this->max= 10;
    this->satelites[max];
}

Estacion_Terrestre:: ~Estacion_Terrestre(){

}

bool Estacion_Terrestre:: agregar_enlace(Satelite* sat){
    bool encontrado= false;

    for(int i= 0; i<max;i++){
        if(satelites[i]==nullptr){
            satelites[i]= sat;
            encontrado= true;
            return ;
        }
    }

    if(!encontrado){
        std::cout<<"No hay espacio"<<std::endl;
    }

    return encontrado;
 }

void Estacion_Terrestre:: eliminar_enlace(std::string cod_sat){
    bool encontrado= false;
    for(int i= 0; i<this->max; i++){
        if(satelites[i]->obtener_cod()==cod_sat){
            satelites[i]= nullptr;
            encontrado= true;
            return;
        }
    }

    if(!encontrado){
        std::cout <<"Satelite no se encuentra en estación."<<std:: endl;
    }
 }

void Estacion_Terrestre:: listar_sat(){
    std::cout<<"Satelites en Estacion Terrestre"<<nombre<<": "<<std::endl;
    for(int i=0; i<max;i++){
        std::cout<<i+1<<"-";
        satelites[i]->mostrar_info();
    }
}

std::string Estacion_Terrestre:: obtener_cod(){
    return codigo;
}
std::string Estacion_Terrestre::  obtener_nombre(){
    return nombre;
}
std:: string Estacion_Terrestre:: obtener_ubi(){
    return ubicacion;
}
#include <iostream>
#include <string>
#include "Satelite.hpp"

Satelite:: Satelite(std:: string cod, std:: string nom, int tipo, 
            int masa,int altitud, int capacidad , double batt,
            double potencia, int ancho_banda  )
            {
                this->codigo= cod;
                this->nombre= nom;
                this->tipo= tipo;
                this->masa=masa;
                this->altitud=altitud;
                this->capacidadE=capacidad;
                this->bateria= batt;
                this->potencia=potencia;
                this-> ancho_banda= ancho_banda;
                this->resolucion= 0;
                this->cobertura= 0;
                this->historial_bateria[12]= {};
                this->historial_temperatura[12]= {};
                this->cantidadMuestras= 0;
            }
Satelite:: ~Satelite(){

}

void Satelite :: agregar_muestra(double b, double t){
    for(int i=0;i<12;i++){
        if(historial_bateria[i]==0 && historial_temperatura[i]==0){
            historial_bateria[i]=b;
            historial_temperatura[i]=t;
            this->cantidadMuestras++;
        }
        else if(cantidadMuestras=12){
            std:: cout<<"Maximo de muestras alcanzado."<<std::endl;
        }
    }
}

double Satelite:: calc_radio_orbital() const{
    double rt= 6371;
    double radio_orbital= rt+this->altitud;

    return radio_orbital;
}

double Satelite:: calc_periodo_orbitalS() const{
    double pi= 3.14159265 ;
    double T= (2*pi*this->calc_radio_orbital())/5;

    return T;
}

double Satelite:: calc_periodo_orbitalM() const{
    double t_minutos= calc_periodo_orbitalS()/60;

    return t_minutos;
}

std:: string Satelite:: obtener_estado(){
    std:: string estado="";

    if(this->bateria>=50){
        estado= "NORMAL";
    }
    else if (bateria>=20&&bateria<50)
    {
        estado= "PRECAUCION";
    }
    else if (bateria>0&&bateria<20)
    {
        estado= "CRITICO";
    }
    else{
        estado= "FUERA DE SERVICIO";
    }

    return estado;
     
}

void Satelite:: consumir_energia(double e){
    this->bateria-e;
}

 void Satelite:: recargarSolar(double potencia, double tiempo,double eficiencia){

        double recarga= potencia*(tiempo/3600)*eficiencia;

        if(bateria>100){
            std::cout<<"BATERIA TOTALMENTE CARGADA, NO SE PUEDE REALIZAR RECARGA";
        }
        else{
            bateria+=recarga;
        }
 }

void Satelite:: mostrar_h_telemetria(){
    for(int i=0;i<12;i++){
        std::cout<<"MUESTRA N° "<<i+1<<std::endl;

        std::cout<<"BATERIA: "<<historial_bateria[i]<<std::endl;
        std::cout<<"TEMPERATURA: "<<historial_temperatura[i]<<std::endl;
    }

 }

double Satelite:: calc_prom_temp() const{
    double suma= -1;
    for(int i=0;i<12;i++){
        suma+=historial_temperatura[i];
    }
    double prom= suma/12;
    return prom;

}
double Satelite:: obtener_min_temp()const{

    double min= historial_temperatura[0];
    for(int i=1;i<12;i++){
        if(historial_temperatura[i]<min){
            min= historial_temperatura[i];
        }
    }

    return min;

}

double Satelite:: obtener_max_temp()const{
    double max= historial_temperatura[0];
        for(int i=1;i<12;i++){
            if(historial_temperatura[i]>max){
            max= historial_temperatura[i];
            }
        }

    return max;
}

double Satelite::  calc_prom_batt() const{
    double suma= -1;
    for(int i=0;i<12;i++){
        suma+=historial_bateria[i];
    }
    double prom= suma/12;
    return prom;

}
double Satelite::  obtener_min_batt()const{
    double min= historial_bateria[0];
    for(int i=1;i<12;i++){
        if(historial_bateria[i]<min){
            min= historial_bateria[i];
        }
    }

    return min;
}
double Satelite:: obtener_max_batt()const{

    double max= historial_bateria[0];
        for(int i=1;i<12;i++){
            if(historial_bateria[i]>max){
            max= historial_bateria[i];
            }
        }

    return max;
}

void Satelite:: mostrar_info(){
    std::cout<<"Codigo: "<<codigo<<std::endl
    <<"Nombre: "<<nombre<<std::endl
    <<"Tipo: "<<tipo<<std::endl
    <<"Masa: "<<masa<<std::endl
    <<"Altitud: "<<altitud<<std::endl
    <<"Capacidad energetica: "<<capacidadE<<std::endl
    <<"Bateria actual: "<<bateria<<std::endl;
}




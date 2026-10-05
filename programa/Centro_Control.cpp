#include <iostream>
#include "Centro_Control.hpp"

Centro_Control::Centro_Control(){
    
    this->satelites= new Satelite*[max_sat];
    this->orbitas=new Orbita* [max_or];
    this->estaciones= new Estacion_Terrestre* [max_et];
    this->transmisiones= new Transmision*[max_tra];
    
    for(int i=0;i<max_sat;i++){satelites[i]=nullptr;}
    for(int i=0;i<max_or;i++){orbitas[i]=nullptr;}
    for(int i=0;i<max_et;i++){estaciones[i]=nullptr;}
    for(int i=0;i<max_tra;i++){transmisiones[i]=nullptr;}
    
   
    for(int i=0;i<max_sat;i++){
        for(int j=0;j<max_et;j++){
            this->matriz_enlaces[i][j]=0;
        }
    }
    
}
Centro_Control:: ~Centro_Control(){
    if(satelites!=nullptr){
        for(int i=0;i<max_sat;i++){
            delete satelites[i];
        }
    }
    delete[] satelites;
    satelites= nullptr;
    if(orbitas!=nullptr){
        for(int i=0;i<max_or;i++){
            delete orbitas[i];
        }
    }
    delete[] orbitas;
    orbitas= nullptr;

    if(estaciones!=nullptr){
        for(int i=0;i<max_et;i++){
            delete estaciones[i];
        }
    }
    delete[] estaciones;
    estaciones= nullptr;

    if(transmisiones!=nullptr){
        for(int i=0;i<max_et;i++){
            delete transmisiones[i];
        }
    }
    delete []transmisiones;
    transmisiones= nullptr;

}

Satelite* Centro_Control:: buscar_satelite(std::string cod){
    Satelite* buscado= nullptr;
    for(int i=0;i<max_sat;i++){
        if(satelites[i]!=nullptr&&satelites[i]->obtener_cod()==cod){
            buscado= satelites[i];
        }
    }
    return buscado;
}

Orbita* Centro_Control:: buscar_orbita(std::string cod){
    Orbita* buscado= nullptr;
    for(int i=0;i<max_or;i++){
        if(orbitas[i]!=nullptr&&orbitas[i]->obtener_codigo()==cod){
            buscado= orbitas[i];
        }
    }
    return buscado;
}

Estacion_Terrestre* Centro_Control:: buscar_et(std::string cod){
    Estacion_Terrestre* buscado= nullptr;
    for(int i=0;i<max_et;i++){
        if(estaciones[i]!=nullptr&&estaciones[i]->obtener_cod()==cod){
            buscado= estaciones[i];
        }
    }
    return buscado;
}

void Centro_Control:: registrar_satelite(Satelite* sat){
    for(int i=0;i<max_sat;i++){
        if(satelites[i]==nullptr){
            satelites[i]=sat;
            return;
        }
    }
}

void Centro_Control:: registrar_orbita(Orbita* orb){
    for(int i=0;i<max_or;i++){
        if(orbitas[i]==nullptr){
            orbitas[i]=orb;
            return;
        }
    }
}

void Centro_Control:: registrar_et(Estacion_Terrestre* et){
    for(int i=0;i<max_et;i++){
        if(estaciones[i]==nullptr){
            estaciones[i]=et;
            return;
        }
    }
}

void Centro_Control:: asignar_sat_orbita(Orbita* o, Satelite* s){
    for(int i=0;i<max_or;i++){
        if(orbitas[i]!=nullptr&&orbitas[i]->obtener_codigo()==s->obtener_cod()){
            std::cout<<"Satelite registrado en otra orbita, no se puede completar proceso"<<std::endl;
            return;
        }
    }
    o->asignarSatelite(s);
}

void Centro_Control:: listar_sat(){
    std::cout<<"Satelites registrados: "<<std::endl;
    for(int i=0; i<max_sat;i++){
        if(satelites[i]!=nullptr){
            std::cout<<"Satelite "<<i+1<<std::endl; 
            satelites[i]->mostrar_info();
        }
    }
}

void Centro_Control:: listar_orb(){
    std::cout<<"Orbitas registradas: "<<std::endl;
    for(int i=0; i<max_or;i++){
        if(orbitas[i]!=nullptr){
         std::cout<<i+1<<"- ";
         std::cout<< orbitas[i]->obtener_codigo()<<std::endl;
        }
    }
}

bool Centro_Control:: crear_enlace(Estacion_Terrestre* e, Satelite* s){
    bool agregado= false;
    //crear un contador para saber en que posicion está estacion y satelite 
    e->agregar_enlace(s);
    for(int i=0;i<max_sat;i++){
        if(satelites[i]==s){
            for(int j=0;j<max_et;j++){
                if(estaciones[j]==e){
                    matriz_enlaces[i][j]=1;
                    agregado= true;
                }
            }
        }
    }

    return agregado;
}

bool Centro_Control:: eliminar_enlace(Estacion_Terrestre* e, Satelite* s){
    bool eliminado= false;
    //crear un contador para saber en que posicion está estacion y satelite 
    e->eliminar_enlace(s->obtener_cod());
    for(int i=0;i<max_sat;i++){
        if(satelites[i]==s){
            for(int j=0;j<max_et;j++){
                if(estaciones[j]==e){
                    matriz_enlaces[i][j]=0;
                    eliminado= true;
                }
            }
        }
    }

    return eliminado;
}

void Centro_Control:: mostrar_enlaces(){
    std::cout<<"\t ";
    for(int i=0;i<max_et;i++){
         if(estaciones[i]!=nullptr){
            std::cout<<estaciones[i]->obtener_nombre()<<"\t";
    }
    }
    std::cout<<std::endl;
    for(int i=0;i<max_sat;i++){
        if(satelites[i]!=nullptr){
            std::cout<<satelites[i]->obtener_nom()<<"\t ";
            for(int j=0;j<max_et;j++){
                std::cout<<matriz_enlaces[i][j]<<" \t";
        }
    }

        std::cout<<std::endl;
    }
}

void Centro_Control:: registrar_muestra(Satelite* s,double b, double t ){
    s->agregar_muestra(b,t);
}

void Centro_Control:: mostrar_h_estadisticas(Satelite* s){
    s->mostrar_h_telemetria();
    std::cout<<"=== Estadisticas telemetria ==="<<std::endl;

    std::cout<<"Bateria: "<<std::endl;
    std::cout<<"Promedio: "<<s->calc_prom_batt()<<std::endl;
    std::cout<<"Minimo: "<<s->obtener_min_batt()<<std::endl;
    std::cout<<"Maximo: "<<s->obtener_max_batt()<<std::endl;

    std::cout<<"Temperatura: "<<std::endl;
    std::cout<<"Promedio: "<<s->calc_prom_temp()<<std::endl;
    std::cout<<"Minimo: "<<s->obtener_min_temp()<<std::endl;
    std::cout<<"Maximo: "<<s->obtener_max_temp()<<std::endl;

}

void Centro_Control:: consultar_bateria(Satelite* s){
    std::cout<<"Porcentaje de bateria: "<<s->obtener_bateria()<<std::endl;
    s->obtener_estado();
}

void Centro_Control:: recarga_solar(Satelite* s, double p, double t, double e){
    s->recarga_solar(p,t,e);
}

void Centro_Control:: listar_critico_fs(){
    bool e= false;
    for(int i=0; i<max_sat;i++){
        if(satelites[i]!=nullptr&&(satelites[i]->obtener_estado()=="CRITICO"|| satelites[i]->obtener_estado()=="FUERA DE SERVICIO")){
            std::cout<<satelites[i]->obtener_nom()<<std::endl;
            e=true;
        }
    }
    if(!e){
        std::cout<<"No hay satelites en estado critico o fuera de estado"<<std::endl;
    }
 }

int Centro_Control:: contar_sat(){
    int registrados=0;

    for(int i=0;i<max_sat;i++){
        if(satelites[i]!=nullptr){
            registrados++;
        }
    }

    return registrados;
}
int Centro_Control:: contar_orb(){
    int registrados=0;

    for(int i=0;i<max_or;i++){
        if(orbitas[i]!=nullptr){
            registrados++;
        }
    }

    return registrados;
}
int Centro_Control:: contar_est(){
     int registrados=0;

    for(int i=0;i<max_et;i++){
        if(estaciones[i]!=nullptr){
            registrados++;
        }
    }

    return registrados;
}
int Centro_Control:: contar_enlaces(){
    int registrados=0;
    for(int i=0;i<max_sat;i++){
       
        for(int j=0;j<max_et;j++){
           if(matriz_enlaces[i][j]==1){
                registrados++;
           }
        }
    }

    return registrados;
}

void Centro_Control:: listar_s_critico(){
    for(int i=0;i<max_sat;i++){
        if(satelites[i]!=nullptr&&satelites[i]->obtener_estado()=="CRITICO"){
            std::cout<<satelites[i]->obtener_cod()<<std::endl;
        }
    }

}

void Centro_Control:: reporte_general(){

    int comu;
    int meteo;

    for(int i=0;i<max_sat;i++){
        if(satelites[i]!=nullptr&&satelites[i]->obtener_tipo()==1){
            comu++;
        }
        else if(satelites[i]!=nullptr&&satelites[i]->obtener_tipo()==2){
            meteo++;
        }
    }

    std::cout<<"Satelites registrados: "<<contar_sat()<<std::endl;
    std::cout<<"Comunicacion: "<<comu<<"|| "<<"Meteorologico: "<<meteo<<std::endl;
    std::cout<<"Orbitas registradas: "<<contar_orb()<<std::endl;
    std::cout<<"Estaciones registradas: "<<contar_est()<<std::endl;
    std::cout<<"Enlaces activos: "<<contar_enlaces()<<std::endl;

    for(int i=0;i<max_sat;i++){
        if(satelites[i]!=nullptr){
            std::cout<<satelites[i]->obtener_cod()<<"|"<<" Muestras telemetria: "<<satelites[i]->obtener_cant_muestras()<<std::endl;
        }
    }

    std::cout<<"Satelites en estado critico:"<<std::endl;
    listar_s_critico();
}

bool Centro_Control:: realizar_transmision(Satelite* sat, Estacion_Terrestre* est, int datos, int ancho_banda, int potenciaW){
    int f=-1;
    int c=-1;
    for(int i=0;i<max_sat;i++){
        if(satelites[i]==sat){
            f=i;
            for(int j=0;j<max_et;j++){
                if(estaciones[j]==est){
                   c=j;
                }
            }
        }
    }

    if(matriz_enlaces[f][c]!=1){
        std::cout<<"Transmision rechazada, no existe enlace activo"<<std::endl;
        return false;
    }
    if (sat->obtener_bateria() <= 0) {
        std::cout << "Error: Transmisión rechazada. El satélite está FUERA DE SERVICIO.\n";
        return false;
    }
    double duracionSeg =(double) datos / ancho_banda;
    double energiaConsumidaWh = potenciaW * (duracionSeg / 3600.0);
    double porcentajeReducir = (energiaConsumidaWh / sat->obtener_capacidadE()) * 100.0;

    if (sat->obtener_bateria() < porcentajeReducir) {
        std::cout << "Error: Transmisión rechazada. Energía disponible insuficiente (" 
                  << sat->obtener_bateria() << "% disponible vs " 
                  << porcentajeReducir << "% requerido).\n";
        return false;
    }

    Transmision* t = new Transmision(est, sat, datos, ancho_banda, potenciaW);

    t->ejecutar();
    for(int i=0;i<max_tra;i++){
        if(transmisiones[i]==nullptr){
            transmisiones[i]=t;
            return true;
        }
    }

    std::cout<<"Limite de transmisiones alcanzado"<<std::endl;
    delete t;
    return false;


}









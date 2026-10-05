#include "Centro_Control.hpp"
#include <iostream>
#include <string>

int main(){
    
    Centro_Control* cc= new Centro_Control();
    
    int op= -1;
    do{             
        std::cout<<"===== CENTRO DE CONTROL SATELITAL ====="<<std::endl;
        std:: cout<<"1. Gestion de satelites "<<std::endl
        <<"2. Gestion de orbitas "<<std::endl
        <<"3. Estaciones y enlaces "<<std::endl
        <<"4. Telemetria "<<std::endl
        <<"5. Transmisiones"<<std::endl
        <<"6. Control energetico "<<std::endl
        <<"7. Reporte"<<std::endl
        <<"0. Salir "<<std::endl
        <<"Seleccione una opcion"<<std::endl;

        std:: cin>>op;

        switch (op)
        {
        case 1:{
            int op_s = -1;
            std::cout<<"===== Gestion de satelites ====="<<std::endl;
            std::cout<<"1. Registrar satelite"<<std::endl
            <<"2. Buscar satelite "<<std::endl
            <<"3. Listar satelites"<<std::endl
            <<"Seleccione una opcion: "<<std::endl;
            std::cin>>op_s;

            switch (op_s)
            {
                //si no pongo llaves no se puede inicializar variable en case
            case 1: {
                std::string cod;
                std:: string nom;
                int tipo;
                double masa;
                double altitud;
                double capacidad;
                double bateria;
                double potencia;
                double ancho_b;
                std:: cout<<" ==== Registrar satelite ===="<<std::endl;
                std::cout<<"Codigo: "<<std::endl;
                std::cin>>cod;
                std::cout<<"Nombre: "<<std::endl;
                std::cin>>nom;
                std::cout<<"Tipo (1- Comunicacion / 2- Meteorologico): "<<std::endl;
                std::cin>>tipo;
                std::cout<<"Masa (kg): "<<std::endl;
                std::cin>>masa;
                std::cout<<"Altitud (km): "<<std::endl;
                std::cin>>altitud;
                std::cout<<"Capacidad energetica (kw): "<<std::endl;
                std::cin>>capacidad;
                std::cout<<"Bateria Actual (%): "<<std::endl;
                std::cin>>bateria;
                std::cout<<"Potencia de transmision (w): "<<std::endl;
                std::cin>>potencia;
                std::cout<<"Ancho de banda maximo (MB/s): "<<std::endl;
                std::cin>>ancho_b;
            
              Satelite* nuevo= cc->buscar_satelite(cod);
              if(nuevo==nullptr){
              Satelite* s= new Satelite(cod, nom,tipo,masa,altitud,capacidad,bateria,potencia,ancho_b);
              cc->registrar_satelite(s);
             }
              else{
                std::cout<<"Codigo ya existe no se puede registrar, intente de nuevo"<<std::endl;
              }


                break;}
            case 2:{
                std::cout<<"==== Buscar satelite ===="<<std::endl;
                std::string cod;
                std::cout<<"Codigo: "<<std::endl;
                std::cin>>cod;

                cc->buscar_satelite(cod);
            
                break;
            }
            case 3:
                std::cout<<"==== Listando satelites ===="<<std::endl;
                cc->listar_sat();
                break;
            
            default:
                std::cout<<"Digite una opcion correcta"<<std::endl;
                break;
            }

             break;
            }
    
        case 2:{
            int op_s = -1;
            std::cout<<"===== Gestion de orbitas ====="<<std::endl;
            std::cout<<"1. Registrar orbita"<<std::endl
            <<"2. Buscar orbitas "<<std::endl
            <<"3. Listar orbitas"<<std::endl
            <<"4. Agregar satelite a orbita"<<std::endl
            <<"Seleccione una opcion: "<<std::endl;
            std::cin>>op_s;

            switch (op_s)
            {
                //si no pongo llaves no se puede inicializar variable en case
            case 1: {
                std::string cod;
                std:: string nom;
                int alt;
                
                std:: cout<<" ==== Registrar orbita ===="<<std::endl;
                std::cout<<"Codigo: "<<std::endl;
                std::cin>>cod;
                std::cout<<"Nombre: "<<std::endl;
                std::cin>>nom;
                std::cout<<"Altura de referencia: "<<std::endl;
                std::cin>>alt;
                
                Orbita* o= cc->buscar_orbita(cod);
                if(o==nullptr){
                Orbita* b= new Orbita(cod, nom,alt);
                cc->registrar_orbita(b);
                }
                else{
                    std::cout<<"Codgo de orbita ya existe, intente de nuevo "<<std::endl;
                }

                break;}
            case 2:{
                std::cout<<"==== Buscar orbita ===="<<std::endl;
                std::string cod;
                std::cout<<"Codigo: "<<std::endl;
                std::cin>>cod;

                cc->buscar_orbita(cod);
            
                break;
            }
            case 3:
                std::cout<<"==== Listando orbitas ===="<<std::endl;
                cc->listar_orb();
                break;
            case 4:{
                 std::cout<<"==== Agregar satelite a orbita ===="<<std::endl;
                std::string cod;
                std::cout<<"Codigo de orbita: "<<std::endl;
                std::cin>>cod;

                std::string cod_s;
                std::cout<<"Codigo de satelite: "<<std::endl;
                std::cin>>cod_s;

                
                Orbita* o= cc->buscar_orbita(cod);
                Satelite* s= cc->buscar_satelite(cod_s);

                
                if(o!=nullptr&&s!=nullptr){
                    cc->asignar_sat_orbita(o,s);
                }
                else{
                    std::cout<<"Codigo orbita/satelite incorrecto"<<std::endl;
                }

                break;
            }

            default:
                std::cout<<"Digite una opcion correcta"<<std::endl;
                break;
            }
        
            break;
        }
    
        case 3:{
             int op_s = -1;
            std::cout<<"===== Estaciones y enlaces ====="<<std::endl;
            std::cout<<"1. Registrar estacion"<<std::endl
            <<"2. Crear enlace "<<std::endl
            <<"3. Eliminar enlace"<<std::endl
            <<"4. Buscar estacion"<<std::endl
            <<"5. Ver matriz de enlaces "<<std::endl
            <<"Seleccione una opcion: "<<std::endl;
            std::cin>>op_s;

            switch (op_s)
            {
                //si no pongo llaves no se puede inicializar variable en case
            case 1: {
                std::string cod;
                std:: string nom;
                std:: string ubi;
                
                std:: cout<<" ==== Registrar estacion ===="<<std::endl;
                std::cout<<"Codigo: "<<std::endl;
                std::cin>>cod;
                std::cout<<"Nombre: "<<std::endl;
                std::cin>>nom;
                std::cin.ignore(10000, '\n');
                std::cout<<"Ubicacion: "<<std::endl;
                std::getline(std::cin,ubi);
                
                Estacion_Terrestre* e= cc->buscar_et(cod);
                if(e==nullptr){
                    Estacion_Terrestre* et= new Estacion_Terrestre(cod, nom,ubi);
                    cc->registrar_et(et);
                }
                else{
                    std::cout<<"Codigo estacion ya existe, intente de nuevo"<<std::endl;
                }

                break;}
            case 2:{
                std::cout<<"==== Crear enlace ===="<<std::endl;
                std::string cod;
                std::cout<<"Codigo de estacion: "<<std::endl;
                std::cin>>cod;

                std::string cod_s;
                std::cout<<"Codigo de satelite: "<<std::endl;
                std::cin>>cod_s;

                Estacion_Terrestre* et= cc->buscar_et(cod);
                Satelite* s= cc->buscar_satelite(cod_s);

                if(et!=nullptr&&s!=nullptr){
                    cc->crear_enlace(et,s);
                }
                else{
                    std::cout<<"Codigo de estacion/satelite incorrecto "<<std::endl;
                }

                break;
            }

            case 3:
                {
                std::cout<<"==== Eliminar enlace ===="<<std::endl;
                std::string cod;
                std::cout<<"Codigo de estacion: "<<std::endl;
                std::cin>>cod;

                std::string cod_s;
                std::cout<<"Codigo de satelite: "<<std::endl;
                std::cin>>cod_s;

                Estacion_Terrestre* et= cc->buscar_et(cod);
                Satelite* s= cc->buscar_satelite(cod_s);

                if(et!=nullptr&&s!=nullptr){
                    cc->eliminar_enlace(et,s);
                }
                else{
                    std::cout<<"Codigo de estacion/satelite incorrecto "<<std::endl;
                }

                break;
            }
            case 4:{
                std::cout<<"==== Buscar estacion ===="<<std::endl;
                std::string cod;
                std::cout<<"Codigo: "<<std::endl;
                std::cin>>cod;

                cc->buscar_et(cod);
            
                break;
            }
            case 5:
                std::cout<<"==== Matriz de enlaces ===="<<std::endl;
                cc->mostrar_enlaces();
                break;

            default:
                std::cout<<"Digite una opcion correcta"<<std::endl;
                break;
            }
            
            break;
        }

        case 4:{
            int op_s = -1;
            std::cout<<"===== Telemetria ====="<<std::endl;
            std::cout<<"1. Registrar muestra"<<std::endl
            <<"2. Ver historial muestras y estadisticas "<<std::endl
            <<"Seleccione una opcion: "<<std::endl;
            std::cin>>op_s;

            switch (op_s)
            {
            case 1:{
                std::cout<<"==== Agregar muestra ===="<<std::endl;
                std::string cod;
                double batt;
                double temp;
                std::cout<<"Codigo: "<<std::endl;
                std::cin>>cod;
                std::cout<<"Bateria"<<std::endl;
                std::cin>>batt;
                std::cout<<"Temperatura"<<std::endl;
                std::cin>>temp;


                Satelite* s= cc->buscar_satelite(cod);

                if(s!=nullptr){
                    cc->registrar_muestra(s,batt,temp);
                }
                else{
                    std::cout<<"Codigo de satelite incorrecto"<<std::endl;
                }
                break;
            }

            case 2:{
                std::cout<<"==== Historial y estadisticas ===="<<std::endl;
                std::string cod;
                std::cout<<"Codigo: "<<std::endl;
                std::cin>>cod;

                Satelite* s= cc->buscar_satelite(cod);

                 if(s!=nullptr){
                    cc->mostrar_h_estadisticas(s);
                }
                else{
                    std::cout<<"Codigo de satelite incorrecto"<<std::endl;
                }
                break;

            }
            
            default:
                std::cout<<"Digite una opcion correcta"<<std::endl;
                break;
            }

            break;
        }
        case 5:{
            std::string cod_e;
            std::string cod_s;
            int datos;
            int ancho;
            int potencia;
            std::cout<<"Codigo estacion: "<<std::endl;
            std::cin>>cod_e;
            std::cout<<"Codigo satelite: "<<std::endl;
            std::cin>>cod_s;
            std::cout<<"Cantidad de datos (MB): "<<std::endl;
            std::cin>>datos;
            std::cout<<"Ancho banda (MB/s): "<<std::endl;
            std::cin>>ancho;
            std::cout<<"Potencia utilizada: "<<std::endl;
            std::cin>>potencia;

            Satelite* s= cc->buscar_satelite(cod_s);
            Estacion_Terrestre* et= cc->buscar_et(cod_e);

            if(et!=nullptr&&s!=nullptr){
                    cc->realizar_transmision(s,et,datos,ancho,potencia);
                }
                else{
                    std::cout<<"Codigo de estacion/satelite incorrecto "<<std::endl;
                }

            break;
        }
        case 6:{
            int op_s = -1;
            std::cout<<"===== Control energetico ====="<<std::endl;
            std::cout<<"1. Consultar estado de bateria de un satelite"<<std::endl
            <<"2. Recarga solar "<<std::endl
            <<"3. Ver satelites en estado CRITICO o FUERA DE SERVICIO "<<std::endl
            <<"Seleccione una opcion: "<<std::endl;
            std::cin>>op_s;

            switch (op_s)
            {
            case 1:{
                std::cout<<"==== Estado bateria ===="<<std::endl;
                std::string cod;
                std::cout<<"Codigo: "<<std::endl;
                std::cin>>cod;


                Satelite* s= cc->buscar_satelite(cod);

                if(s!=nullptr){
                    cc->consultar_bateria(s);
                }
                else{
                    std::cout<<"Codigo de satelite incorrecto"<<std::endl;
                }
                break;
            }

            case 2:{
                std::cout<<"==== Recargar bateria ===="<<std::endl;
                std::string cod;
                std::cout<<"Codigo: "<<std::endl;
                std::cin>>cod;
                double p;
                double t;
                double e;
                std::cout<<"Potencia: "<<std::endl;
                std::cin>>p;
                std::cout<<"Tiempo: "<<std::endl;
                std::cin>>t;
                std::cout<<"Eficiencia: "<<std::endl;
                std::cin>>e;


                Satelite* s= cc->buscar_satelite(cod);

                 if(s!=nullptr){
                    cc->recarga_solar(s,p,t,e);
                }
                else{
                    std::cout<<"Codigo de satelite incorrecto"<<std::endl;
                }
                break;

            }
            case 3:
                std::cout<<"==== Lista CRITICO/FUERA DE SERVICIO ===="<<std::endl;
                cc->listar_critico_fs();
                break;
            
            default:
                std::cout<<"Digite una opcion correcta"<<std::endl;
                break;
            }

            break;
        }

        case 7:
            cc->reporte_general();
            break;
    
        default:
            std::cout<<"Digite una opcion correcta"<<std::endl;
            break;
        }
}while(op!=0);
    std::cout<<"Liberando recursos del sistema..."<<std::endl;
    delete cc;
    cc=nullptr;
    std::cout<<"Memoria liberada"<<std::endl;
    std::cout<<"===== FIN DE LA EJECUCION ====="<<std::endl;

    return 0;
}
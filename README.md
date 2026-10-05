# prograII_programada1

===== CENTRO CONTROL DE SATELITES =====

Autores: Krissia Santamaría Rodriguez - C5J775
Julian Barrantes Madrigal - C5D034

Resumen del programa: representa un sistema de gestión de satélites, en el que se pueden crear satélites, órbitas, estaciones. Además de agregar un satélite a una órbita específica, crear enlaces entre una estación y un satélite, cargar muestras de telemetría, control energético y realizar reportes del sistema.

---
### Lenguaje:
* *** c++

## Clases y Metodos

### 1. Centro_Control

Clase principal que administra y coordina los arreglos de objetos (satélites, órbitas, estaciones y transmisiones) y la matriz de enlaces.

* **Centro_Control() / ~Centro_Control()**: Constructor y destructor de la clase.
* **buscar_satelite(string cod)**: Busca un satélite por su código.
* **buscar_orbita(string cod)**: Busca una órbita por su código.
* **buscar_et(string cod)**: Busca una estación terrestre por su código.
* **registrar_satelite(Satelite* sat)**: Agrega un satélite al sistema.
* **registrar_orbita(Orbita* orb)**: Agrega una órbita al sistema.
* **registrar_et(Estacion_Terrestre* et)**: Agrega una estación terrestre al sistema.
* **listar_sat()**: Muestra la lista de satélites registrados.
* **listar_orb()**: Muestra la lista de órbitas registradas.
* **asignar_sat_orbita(Orbita* o, Satelite* s): Asigna un satélite a una órbita.
* **crear_enlace(Estacion_Terrestre* e, Satelite* s): Crea un enlace entre una estación y un satélite en la matriz.
* **eliminar_enlace(Estacion_Terrestre* e, Satelite* s): Elimina el enlace entre una estación y un satélite.
* **mostrar_enlaces()**: Muestra la matriz de enlaces activos.
* **realizar_transmision(...)**: Registra y ejecuta una transmisión entre satélite y estación terrestre.
* **reporte_general()**: Genera un reporte completo del estado del sistema.
* **registrar_muestra(Satelite* s, double b, double t)**: Registra una lectura de telemetría (batería y temperatura).
* **mostrar_h_estadisticas(Satelite* s)**: Muestra el historial de estadísticas de telemetría de un satélite.
* **consultar_bateria(Satelite* s)**: Muestra el nivel actual de batería de un satélite.
* **recarga_solar(Satelite* s, double p, double t, double e)**: Procesa una carga de energía solar para el satélite.
* **listar_critico_fs()**: Lista los satélites en estado crítico o fuera de servicio.
* **Métodos de conteo y auxiliares**: `contar_sat()`, `contar_orb()`, `contar_est()`, `contar_enlaces()`, `contar_m_telemetria()`, `listar_s_critico()`.

### 2. Satelite

Modela las características físicas, operativas y de telemetría de un satélite.

* **Satelite(...) / ~Satelite()**: Constructor con parámetros del satélite y destructor.
* **agregar_muestra(double b, double t)**: Guarda una muestra de batería y temperatura en los historiales.
* **calc_radio_orbital()**: Calcula el radio orbital del satélite.
* **calc_periodo_orbitalS()**: Calcula el período orbital en segundos.
* **calc_periodo_orbitalM()**: Calcula el período orbital en minutos.
* **obtener_estado()**: Retorna el estado actual del satélite según su batería.
* **consumir_energia(double e)**: Reduce la energía de la batería del satélite.
* **recarga_solar(double potencia, double tiempo, double eficiencia)**: Incrementa la batería mediante recarga solar.
* **mostrar_h_telemetria()**: Muestra los datos del historial de telemetría.
* **Cálculos estadísticos**: `calc_prom_temp()`, `obtener_min_temp()`, `obtener_max_temp()`, `calc_prom_batt()`, `obtener_min_batt()`, `obtener_max_batt()`.
* **mostrar_info()**: Imprime los datos principales del satélite.
* **Getters**: `obtener_cod()`, `obtener_nom()`, `obtener_bateria()`, `obtener_tipo()`, `obtener_cant_muestras()`, `obtener_capacidadE()`.

### 3. Orbita

Representa una órbita física y la lista de satélites asignados a ella.

* **Orbita(string cod, string nom, int alt) / ~Orbita()**: Constructor y destructor de la órbita.
* **asignarSatelite(Satelite* sat)**: Asigna un satélite a la órbita si hay espacio.
* **contiene_sat(string cod)**: Verifica si un satélite específico está en esta órbita.
* **listar_sat()**: Imprime los satélites asignados a la órbita.
* **Getters**: `obtener_codigo()`, `obtener_nombre()`, `obtener_alt()`.

### 4. Estacion_Terrestre

Modela una estación terrestre encargada de comunicarse con los satélites.

* **Estacion_Terrestre(string cod, string nom, string ubi) / ~Estacion_Terrestre()**: Constructor y destructor.
* **agregar_enlace(Satelite* sat)**: Registra un enlace con un satélite.
* **eliminar_enlace(string cod_sat)**: Elimina el enlace con un satélite por su código.
* **listar_sat()**: Muestra los satélites enlazados a la estación.
* **Getters**: `obtener_cod()`, `obtener_nombre()`, `obtener_ubi()`.

### 5. Transmision

Modela una transmisión de datos individual entre una estación terrestre y un satélite.

* **Transmision(Estacion_Terrestre* e, Satelite* s, int datos, int ancho_b, int potencia) / ~Transmision(): Constructor y destructor.
* **calc_duracion()**: Calcula el tiempo de duración de la transmisión.
* **calc_TP()**: Calcula el tiempo de propagación de la señal.
* **calc_EC()**: Calcula la energía consumida durante la transmisión.
* **ejecutar()**: Procesa la transmisión de datos y aplica los consumos energéticos correspondientes.

### 6. main

Clase que contiene int main(), ejecuta el programa.

---

## Compilacion y Ejecucion

Para compilar el proyecto con g++:

```bash
g++ -std=c++11 *.cpp -o programa

```

Para ejecutar el programa:

```bash
./programa

```
/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */


#include <../include/handlerEstadistica.h>
using std::pair;
using std::string;

HandlerEstadistica::HandlerEstadistica(){
    estadisticas = new map<string, Estadistica*>;
    string etjsn = "Total Jugadores Suscriptos";
    string ethjn = "Total Horas Jugadas";
    Estadistica * etjs = new EstadisticaTotalJugadoresSuscriptos(etjsn,"Cuenta la cantidad de jugadores que se han suscripto a un videojuego"); 
    Estadistica * ethj = new EstadisticaTotalHorasJugadas(ethjn,"Cuenta la cantidad de horas jugadas para un videojuego. Esto es, la suma de la duracion de todas las partidas individuales mas la duracion de las partidas multijugador multiplicadas por los jugadores unidos a la misma.");
    estadisticas->insert(pair<string,Estadistica*>(etjsn,etjs));
    estadisticas->insert(pair<string,Estadistica*>(ethjn,ethj));
}

HandlerEstadistica* HandlerEstadistica::getInstance() {
    static HandlerEstadistica instancia;
    return &instancia;
}

map<string, Estadistica*>* HandlerEstadistica::getEstadistica() {
    //map<string,Estadistica*> * x = new map<string,Estadistica*>;
    //x = estadisticas;
    //return x;
    return estadisticas;
}

Estadistica* HandlerEstadistica::findEstadistica(string nombreEstadistica) {
    return estadisticas->find(nombreEstadistica)->second;
}

void HandlerEstadistica::addEstadistica(Estadistica* est) {
    estadisticas->insert(map<string, Estadistica*>::value_type(est->getNombre(), est));
}

HandlerEstadistica::~HandlerEstadistica() {
    for (map<string, Estadistica*>::iterator it = estadisticas->begin(); it != estadisticas->end(); ++it) {
        delete it->second;
    }
    delete estadisticas;
}

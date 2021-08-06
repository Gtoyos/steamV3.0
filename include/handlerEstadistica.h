/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */


#ifndef HANDLER_ESTADISTICA
#define HANDLER_ESTADISTICA

#include <string>
#include <set>
#include "estadistica.h"
#include "estadisticaTotalHorasJugadas.h"
#include "estadisticaTotalJugadoresSuscriptos.h"

using std::string;
using std::set;

class HandlerEstadistica {
private:
    map<string, Estadistica*>* estadisticas;
    HandlerEstadistica();
public:
    static HandlerEstadistica* getInstance();
    map<string, Estadistica*>* getEstadistica();
    Estadistica* findEstadistica(string);
    void addEstadistica(Estadistica*);
    ~HandlerEstadistica();
};

#endif

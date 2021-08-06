/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef HANDLER_CATALOGO
#define HANDLER_CATALOGO

#include <string>
#include <map>
#include <set>
#include "videojuego.h"

using std::string;
using std::map;
using std::set;

class DtVideojuego;

class HandlerCatalogo {
private:
    map<string, Videojuego*>* videojuegos;
    HandlerCatalogo();
public:
    static HandlerCatalogo* getInstance();
    //set<DtVideojuego>* getDatosInactivos(); funcion deshabilitada
    set<Videojuego*>* getSetComplement(set<Videojuego*>*);

    set<DtVideojuego>* getDtVideojuegos();
    Videojuego* findVideojuego(string);
    void addVideojuego(Videojuego*);
    void remove(Videojuego*);
    ~HandlerCatalogo();
};

#endif

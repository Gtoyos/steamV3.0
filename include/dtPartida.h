/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */


#ifndef DTPARTIDA
#define DTPARTIDA

#include "dtFechaHora.h"

#include <iostream>
using std::string;

class DtPartida {
    protected:
        int id;
        DtFechaHora fecha;
        float duracion;
        bool activa;
    public:
        DtPartida(int,DtFechaHora,float,bool);
        int getId();
        DtFechaHora getFecha();
        float getDuracion();
        bool getActiva();
        bool esActiva();
	    friend bool operator<(const DtPartida,const DtPartida);
        virtual ~DtPartida() { }
};

#endif

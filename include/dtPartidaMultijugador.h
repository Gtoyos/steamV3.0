/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef DTPARTIDAMULTIJUGADOR
#define DTPARTIDAMULTIJUGADOR
#include <string>
#include <set>
#include "dtPartida.h"
#include "dtFechaHora.h"

using std::set;
using std::string;

class DtPartidaMultijugador: public DtPartida {
    private:
        bool transmitidaEnVivo;
    public:
        DtPartidaMultijugador(int,DtFechaHora,float,bool,bool);
	    bool getTransmitidaEnVivo();
};

std::ostream& operator<<(std::ostream&, DtPartidaMultijugador);

#endif

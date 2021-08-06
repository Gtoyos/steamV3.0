/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */


#ifndef DTPARTIDAINDIVIDUAL
#define DTPARTIDAINDIVIDUAL

#include "dtPartida.h"

class DtPartidaIndividual: public DtPartida{
    private:
	    int idPartidaAnterior;
    public:
        DtPartidaIndividual(int,DtFechaHora,float,bool,int);
        int getIdPartidaAnterior();
};

std::ostream& operator<<(std::ostream&,DtPartidaIndividual);

#endif

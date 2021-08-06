/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef PARTIDA_INDIVIDUAL
#define PARTIDA_INDIVIDUAL

#include "dtPartidaIndividual.h"
#include "partida.h"
#include "fechaSistema.h"

class DtFechaHora;
class Jugador;
class Videojuego;
class DtPartida;

class PartidaIndividual: public Partida {
    private:
        PartidaIndividual* partidaAnterior;
    public:
        PartidaIndividual(DtPartidaIndividual);
        float getDuracion();
        void setPartidaAnterior(PartidaIndividual*);
        PartidaIndividual* getPartidaAnterior();
        virtual void asignarHoraFinalizacion();
        ~PartidaIndividual();
};

#endif

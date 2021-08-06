/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef JUGADOR
#define JUGADOR

#include "usuario.h"
#include "dtVideojuego.h"
#include "dtPartida.h"
#include "dtPartidaIndividual.h"
#include "partidaIndividual.h"
#include "partidaMultijugador.h"
#include "partida.h"
#include "suscripcion.h"
#include "dtPartida.h"
#include "dtJugador.h"
#include "jugadorMulti.h"
#include "fechaSistema.h"

#include <string>
#include <set>
#include <map>
#include <vector>

class Jugador: public Usuario {
    private:
        std::set<Suscripcion *> * suscripciones;
        std::map<int,Partida *> * partidas;
        std::map<int,PartidaMultijugador *> * partidasUnido;
        std::string nickname;
        std::string descripcion;
    public:
        Jugador(DtJugador);
        void setNickname(std::string);
        std::string getNickname();
        void setDescripcion(std::string);
        std::string getDescripcion();
        void add(Suscripcion *);
        void remove(Suscripcion *);
        void add(Partida *);
        Partida * findPartida(int);
        void add(PartidaMultijugador *);
        void remove(PartidaMultijugador *);
        PartidaMultijugador * findPartidaMulti(int);

        std::set<Videojuego*> * obtenerDatosVj();
        std::map<int, Partida*>* obtenerPartidas();
        std::vector<PartidaIndividual*> * obtenerHistorialPartidas();
        std::map<int, PartidaMultijugador *> * obtenerPartidasUnido();
        PartidaIndividual * seleccionarContinuacionPartida(int);
        void agregarPartida(Partida *);
        void agregarSuscripcion(Suscripcion *);
        void abandonarPartidaMulti(PartidaMultijugador *);
        void finPartida(int);
        void associate(Partida *);
        void removeSus(Suscripcion *);
        void quitar(Partida *);
	
	set<Suscripcion *>* getSuscripciones();

        ~Jugador();
};

#endif

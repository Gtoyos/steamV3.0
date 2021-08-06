/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef PARTIDA_MULTIJUGADOR
#define PARTIDA_MULTIJUGADOR

#include <string>
#include <map>
#include <vector>
#include "partida.h"
#include "dtPartidaMultijugador.h"
#include "jugadorMulti.h"
#include "fechaSistema.h"

using std::string;
using std::map;
using std::vector;

class DtFechaHora;
class Jugador;
class Videojuego;
class DtPartida;

class PartidaMultijugador : public Partida {
private:
    bool transmitidaEnVivo;
    vector<JugadorMulti*>* jugadoresMultis;
    map<string, Jugador*>* jugadoresUnidos;
public:
    PartidaMultijugador(DtPartidaMultijugador);
    float getDuracion();
    bool getTransmitidaEnVivo();
    void setJugadoresUnidos(map<string, Jugador*>*);
    map<string, Jugador*>* getJugadoresUnidos();
    virtual void asignarHoraFinalizacion();
    void abandonar(JugadorMulti*);
    ~PartidaMultijugador();
};

#endif

/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */


#ifndef IIFPCONTROLLER
#define IIFPCONTROLLER

#include <string>
#include <set>
#include <map>
#include <vector>

class Jugador;
class Videojuego;
class Partida;
class PartidaIndividual;
class DtPartida;
class DtPartidaIndividual;
class DtPartidaMultijugador;
class DtFechaHora;

class IIFPController {
    public:
        virtual void iniciarSesion() = 0;
        virtual int getIdSisActual() = 0;
        virtual void setTipo(bool) = 0;
        virtual bool getTipo() = 0;
        virtual void setHost(Jugador*) = 0;
        virtual Jugador* getHost() = 0;
        virtual void seleccionarVideojuego(std::string) = 0;
        virtual void setVj(Videojuego*) = 0;
        virtual Videojuego* getVj() = 0;
        virtual void seleccionarContinuacionPartida(int) = 0;
        virtual void setPartidaAnterior(PartidaIndividual*) = 0;
        virtual Partida* getPartidaAnterior() = 0;
        virtual void setEnVivo(bool) = 0;
        virtual bool getEnVivo() = 0;
        virtual void add(Jugador *) = 0;
        virtual void remove(Jugador *) = 0;
        virtual void aniadirJugadorPartida(std::string) = 0;
        virtual Jugador* findJugador(std::string) = 0;
		
        virtual std::set<std::string> * obtenerVideojuegosActivos() = 0;
        virtual std::map<int, std::string>* obtenerPartidasActivas() = 0;
        virtual std::set<int>* obtenerHistorialIDPartidas() = 0;
        virtual std::vector<std::string>* obtenerHistorialPartidas() = 0;
        virtual std::map<int, std::string>* obtenerPartidasMultiActivas() = 0;
        virtual std::set<std::string> * obtenerJugadoresSubscriptos() = 0;
        
        virtual void confirmarPartida() = 0;
        virtual void confirmarFinalizarPartida(int) = 0;
	    virtual void confirmarAbandonarPartida(int)=0;
        virtual void clearCache() = 0;

	    virtual ~IIFPController(){}
};

#endif

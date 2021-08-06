/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */


#ifndef IFPCONTROLLER
#define IFPCONTROLLER

#include "iIFPController.h"
#include "dtPartida.h"
#include "dtPartidaIndividual.h"
#include "jugador.h"
#include "partidaIndividual.h"
#include "handlerCatalogo.h"
#include "handlerUsuario.h"
#include "suscripcion.h"

#include <string>
#include <set>
#include <map>

class IFPController: public IIFPController {
    private:
        IFPController();
        bool esIndividual;
        int contadorId;
        Jugador* host;
        Videojuego* vj;
        PartidaIndividual* partidaAnterior;
        std::map<std::string,Jugador*> * jugadoresAUnir;
        bool pCont;
        bool enVivo;
    public:
        static IFPController* getInstance();
        void iniciarSesion();
        int getIdSisActual();
        void setTipo(bool);
        bool getTipo();
        void setHost(Jugador*);
        Jugador* getHost();
        void seleccionarVideojuego(std::string);
        void setVj(Videojuego *);
        Videojuego* getVj();
        void seleccionarContinuacionPartida(int);
        void setPartidaAnterior(PartidaIndividual*);
        Partida* getPartidaAnterior();
        void setEnVivo(bool);
        bool getEnVivo();
        void add(Jugador *);
        void remove(Jugador *);
        void aniadirJugadorPartida(std::string);
        Jugador* findJugador(std::string);

        std::set<std::string> * obtenerVideojuegosActivos();
        std::map<int, std::string>* obtenerPartidasActivas();
        std::set<int>* obtenerHistorialIDPartidas();
        std::vector<std::string>* obtenerHistorialPartidas();
        std::map<int, std::string>* obtenerPartidasMultiActivas();
        std::set<std::string> * obtenerJugadoresSubscriptos();
        
        void confirmarPartida();
        void confirmarFinalizarPartida(int);
        void confirmarAbandonarPartida(int);
        void clearCache();

        ~IFPController();
};

#endif

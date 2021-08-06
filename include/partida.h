/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */


#ifndef PARTIDA
#define PARTIDA

#include "dtFechaHora.h"
#include "dtPartida.h"
#include "fechaSistema.h"

class Jugador;
class Videojuego;

class Partida {
    private:
        int identificador;
        DtFechaHora fecha;
        bool activa;
        Jugador* host;
        Videojuego* videogame;
    protected:
        float duracion;
        Partida(DtPartida);
    public:
        int getId();
        Jugador* getHost();
        DtFechaHora getDtFechaHora();
        virtual float getDuracion() = 0;
        void setDuracion(float);
        void setActiva(bool);
        bool esActiva();
        void setHost(Jugador*);
        void remove(Jugador*);
        void setVideojuego(Videojuego*);
        Videojuego* getVideojuego();
        virtual void asignarHoraFinalizacion()=0;
        void finalizarPartida();
        virtual ~Partida();
};

#endif

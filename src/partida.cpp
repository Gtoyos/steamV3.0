/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include <../include/partida.h>

Partida::Partida(DtPartida datos) {
    identificador = datos.getId();
    fecha = datos.getFecha();
    duracion = datos.getDuracion();
    activa = datos.getActiva();
    host = NULL;
    videogame = NULL;
}

int Partida::getId() { return identificador; }

DtFechaHora Partida::getDtFechaHora() { return fecha; }

void Partida::setDuracion(float f){duracion=f;}

void Partida::setActiva(bool act) { activa = act; }

bool Partida::esActiva() { return activa; }

void Partida::setHost(Jugador* player) {
    host = player;
}

Jugador* Partida::getHost() { return host; }

void Partida::remove(Jugador* player) { 
    if (player == host)
        host = NULL; 
}

void Partida::setVideojuego(Videojuego* vj) {
    videogame = vj;
}

Videojuego* Partida::getVideojuego() { return videogame; }

void Partida::finalizarPartida() {
    activa = false;
    this->asignarHoraFinalizacion();
}

Partida::~Partida() { }
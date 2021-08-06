/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */


#include "../include/partidaMultijugador.h"

PartidaMultijugador::PartidaMultijugador(DtPartidaMultijugador datos) : Partida(DtPartida(datos.getId(), datos.getFecha(),
        datos.getDuracion(), datos.getActiva())) {
    transmitidaEnVivo = datos.getTransmitidaEnVivo();
    jugadoresUnidos = NULL;
    jugadoresMultis = new vector<JugadorMulti*>;
}
    
float PartidaMultijugador::getDuracion() { 
    if (this->esActiva()) {
        float sum = 0;
        int cont = 0;
        for (vector<JugadorMulti*>::iterator it = jugadoresMultis->begin(); it != jugadoresMultis->end(); ++it) {
            cont++;
            sum += this->getDtFechaHora().diffHoras((*it)->getDesconexion());
        }
        cont = jugadoresUnidos->size() - cont;
        sum += (this->getDtFechaHora().diffHoras(fechaSistema::fecha)) * (cont + 1); //Correccion para usar fechaSistema
        return sum;
    } else {
        return duracion;
    }
}

bool PartidaMultijugador::getTransmitidaEnVivo(){ return transmitidaEnVivo; }

void PartidaMultijugador::setJugadoresUnidos(map<string, Jugador*>* jAUnir) {
    jugadoresUnidos = jAUnir;
}

map<string, Jugador*>* PartidaMultijugador::getJugadoresUnidos() { 
    return jugadoresUnidos; 
}

void PartidaMultijugador::asignarHoraFinalizacion() {
    float sum=0;
    for (vector<JugadorMulti*>::iterator it = jugadoresMultis->begin(); it != jugadoresMultis->end(); ++it) {
        sum += this->getDtFechaHora().diffHoras((*it)->getDesconexion());
    }
    sum += this->getDtFechaHora().diffHoras(fechaSistema::fecha); //Correccion para usar fechaSistema
    this->setDuracion(sum);
}

void PartidaMultijugador::abandonar(JugadorMulti* jMulti) {
    jugadoresMultis->insert(jugadoresMultis->begin(), jMulti);
}

PartidaMultijugador::~PartidaMultijugador() {
    for (vector<JugadorMulti*>::iterator it = jugadoresMultis->begin(); it != jugadoresMultis->end(); ++it) {
        delete *it;
    }
    delete jugadoresMultis;
    delete jugadoresUnidos;
}

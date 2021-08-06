/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/dtPartidaMultijugador.h"
#include "../include/dtPartida.h"
#include "../include/dtFechaHora.h"

DtPartidaMultijugador::DtPartidaMultijugador(int id,DtFechaHora fecha,float duracion,bool activa,bool trans): DtPartida(id,fecha,duracion,activa) {
    transmitidaEnVivo = trans;
}

bool DtPartidaMultijugador::getTransmitidaEnVivo(){
    return transmitidaEnVivo;
}

std::ostream & operator << (std::ostream &o,DtPartidaMultijugador p) {
    o << "ID: " << p.getId() << "\n" << "Duracion: " << p.getDuracion() << " horas."
    << "\n" << "Fecha de creacion: " << p.getFecha() << "\n";
    if (p.getActiva()) 
        o << "La partida se encuentra en curso.\n";
    else 
        o << "La partida ha finalizado.\n";
    if(p.getTransmitidaEnVivo()) 
        o << "Se esta transmitiendo en vivo\n";
    else 
        o << "No se ha transmitido en vivo\n";
    o << "\n";
    return o;
}

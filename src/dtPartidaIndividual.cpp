/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/dtPartidaIndividual.h"
#include "../include/dtFechaHora.h"

DtPartidaIndividual::DtPartidaIndividual(int id,DtFechaHora fecha,float duracion,bool activa,int w): DtPartida(id,fecha,duracion,activa) {
    idPartidaAnterior = w;
}

int DtPartidaIndividual::getIdPartidaAnterior() {
    return idPartidaAnterior;
}

std::ostream & operator<<(std::ostream &o, DtPartidaIndividual p) {
    o << "ID: " << p.getId() << "\n" << "Duracion: " << p.getDuracion() 
    << "\n" << "Fecha de creacion: " << p.getFecha() << "\n";
    if (p.getActiva()) 
        o << "La partida se encuentra en curso.\n";
    else 
        o << "La partida ha finalizado.\n";
    if (p.getIdPartidaAnterior() == -1)
        o << "No es continuacion de otra partida \n";
    else
        o << "ID partida anterior: " << p.getIdPartidaAnterior() << "\n";
    o << "\n";
    return o;
}
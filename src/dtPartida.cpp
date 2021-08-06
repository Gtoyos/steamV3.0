/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/dtPartida.h"
#include "../include/dtFechaHora.h"

DtPartida::DtPartida(int id,DtFechaHora fecha,float duracion, bool activa) {
    this->id = id;
    this->fecha = fecha;
    this->duracion = duracion;
    this->activa = activa;
}

int DtPartida::getId() {
    return id;
}

DtFechaHora DtPartida::getFecha() {
    return fecha;
}

float DtPartida::getDuracion() {
    return duracion;
}

bool DtPartida::getActiva() {
    return activa;
}

bool DtPartida::esActiva() { // alias
    return getActiva();
}

bool operator<(const DtPartida p1,const DtPartida p2){
    return p1.fecha < p2.fecha;
}
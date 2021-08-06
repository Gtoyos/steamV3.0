/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include <../include/partidaIndividual.h>

PartidaIndividual::PartidaIndividual(DtPartidaIndividual datos) : Partida(DtPartida(datos.getId(), datos.getFecha(),
        datos.getDuracion(), datos.esActiva())) { 
    partidaAnterior = NULL;
}

float PartidaIndividual::getDuracion() { 
    if (this->esActiva()) {
        return this->getDtFechaHora().diffHoras(fechaSistema::fecha);
    } else {
        return duracion;
    }
}

void PartidaIndividual::setPartidaAnterior(PartidaIndividual* pAnt) {
    partidaAnterior = pAnt;
}

PartidaIndividual* PartidaIndividual::getPartidaAnterior() { return partidaAnterior; }

void PartidaIndividual::asignarHoraFinalizacion() {
    this->setDuracion(this->getDtFechaHora().diffHoras(fechaSistema::fecha));
}

PartidaIndividual::~PartidaIndividual() { }

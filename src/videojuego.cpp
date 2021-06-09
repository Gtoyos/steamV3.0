/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include <string>
#include <map>
#include <set>

#include "../include/videojuego.h"

using std::string;
using std::map;
using std::set;

Videojuego::Videojuego(DtVideojuego datos, map<string,Categoria*> *categorias): costoSuscripciones(datos.getDtPrecios()){
    this->nombre = datos.getNombre();
    this->descripcion = datos.getDescripcion();
    this->totalHorasJugadas = 0;
    this->puntaje = 0;
    this->totalJugadoresSuscriptos = 0;
    this->categorias = categorias;
}

Videojuego::~Videojuego() {
    eliminarInfoAsociada();
    delete this->categorias;
    delete this->partidas;
    delete this->suscripciones;
}

DtVideojuego Videojuego::obtenerDatosVideojuego() {
    /*No se puede acceder asi a los miembros ni instanciarlos. ver constructores en los .h
    DtVideojuego dtVid();
    dtVid.nombre = this->getNombre();
    dtVid.descripcion = this->getDescripcion();
    dtVid.costos = this->getCostoSuscripciones();
    return dtVid;
    */
    return DtVideojuego("","",0,0,0,0);
}

set<Jugador*>* Videojuego::obtenerJugadoresSuscriptos() {
    set<Jugador*>* setJugadores = new set<Jugador*>;
    for (set<Suscripcion*>::iterator it = suscripciones->begin(); it != suscripciones->end(); ++it) {
        setJugadores->insert((*it)->getComprador()); 
    }
    return setJugadores;
}

bool Videojuego::estaActivo() {
    if (this->partidas->empty()) {
        return false;
    } else {
        return true;
    }
}
//Las partidas individuales no necesariamente tienen que tener una continuacion. Hay que aplicar la el  overloading a la funcion. Es decir un confirmar para individual y otro para multijugador con parametros distintos
void Videojuego::confirmarPartida(Jugador* host,int id,PartidaIndividual* pCont,bool enVivo,map<string,Jugador*>* jUnidos) {
   /* if (pCont != NULL) {
        DtPartidaIndividual dtPInd(id,fechaHoraActual,0,true);
        PartidaIndividual* pInd = new PartidaIndividual(dtPInd); 
        pInd->setHost(host);
        pInd->setPartidaAnterior(pCont);
        pInd->setVideojuego(this);
        host->agregarPartida(pInd); 
        this->partidas->insert(pInd);
    } else {
        DtPartidaMultijugador dtPMulti(id,fechaHoraActual,0,true,enVivo);
        PartidaMultijugador* pMulti = new PartidaMultijugador(dtPMulti);
        pMulti->setHost(host);
        pMulti->setJugadoresUnidos(jUnidos);
        host->agregarPartida(pMulti);
        for (map<string,Jugador*>::iterator it = jUnidos->begin(); it != jUnidos->end(); ++it) {
            it->second->associate(pMulti);
        }
        this->partidas->insert(pMulti);
    }
    */
}

void Videojuego::cancelarSuscripcion(Jugador* host) {
    for (set<Suscripcion*>::iterator it = suscripciones->begin(); it != suscripciones->end(); ++it) {
        if ((*it)->esDeJugador(host)) {
            static_cast<SuscripcionTemporal*>((*it))->cancelarSuscripcion();
        }
    }
}

void Videojuego::confirmarSuscripcion(Jugador* host,TipoValido tipoVal,TipoPago tipoPago) {
    DtFechaHora fechaHoraActual(); 
    if (tipoVal != TipoValido::Vitalicia) {
        SuscripcionTemporal* nuevaSus = new SuscripcionTemporal(tipoVal,TipoEstado::Activa,fechaSistema::fecha,tipoPago,host,this);
	host->agregarSuscripcion(nuevaSus);
	this->suscripciones->insert(nuevaSus);
    } else {
        SuscripcionVitalicia* nuevaSus = new SuscripcionVitalicia(fechaSistema::fecha,tipoPago,host,this);
	host->agregarSuscripcion(nuevaSus);
        this->suscripciones->insert(nuevaSus);
    }
}

void Videojuego::eliminarInfoAsociada() {
    for (map<int,Partida*>::iterator it = partidas->begin(); it != partidas->end(); ++it) {
        it->second->eliminarAssoc();
        delete it->second;
    }
    for (set<Suscripcion*>::iterator it = suscripciones->begin(); it != suscripciones->end(); ++it) {
        (*it)->eliminarAssoc();
        delete *it;
    }
}

//--- Getters ---
string Videojuego::getNombre() {
    return this->nombre;
}

string Videojuego::getDescripcion() {
    return this->descripcion;
}

DtPrecios Videojuego::getCostoSuscripciones() {
    return this->costoSuscripciones;
}

float Videojuego::getTotalHorasJugadas() {
    return this->totalHorasJugadas;
}

float Videojuego::getPuntaje() {
    return this->puntaje;
}

int Videojuego::getTotalJugadoresSuscriptos() {
    return this->totalJugadoresSuscriptos;
}

//Aca habria que retornar un set?
Suscripcion* Videojuego::getSuscripciones() {
    //return this->suscripciones;
    return nullptr; //temporal para que compile
}

map<int,Partida*>* Videojuego::getPartidas() {
    return this->partidas;
}

//Mismop problema que en get suscripciones. retorno nullptr para que compile...
Categoria* Videojuego::getCategorias() {
//    return this->categorias;
    return nullptr;
}

//--- Setters ---
void Videojuego::setNombre(string nombre) {
    this->nombre = nombre;
}

void Videojuego::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

void Videojuego::setCostoSuscripciones(DtPrecios costoSuscripciones) {
    this->costoSuscripciones = costoSuscripciones;
}

void Videojuego::setTotalHorasJugadas(float totalHorasJugadas) {
    this->totalHorasJugadas = totalHorasJugadas;
}

void Videojuego::setPuntaje(float puntaje) {
    this->puntaje = puntaje;
}

void Videojuego::setTotalJugadoresSuscriptos(int totalJugadoresSuscriptos) {
    this->totalJugadoresSuscriptos = totalJugadoresSuscriptos;
}

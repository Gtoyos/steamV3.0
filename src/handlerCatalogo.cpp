/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include <../include/handlerCatalogo.h>

HandlerCatalogo::HandlerCatalogo() {
    videojuegos = new map<string, Videojuego*>;
}

HandlerCatalogo* HandlerCatalogo::getInstance() {
    static HandlerCatalogo instancia;
    return &instancia;
}
/* Guille: Esta funcion no estaba bien hecha (Desde el propio UML) Lo que tiene que retornar es el complemento del set de videojuegos activos que DEBIO haberse pasado por parametro
set<DtVideojuego>* HandlerCatalogo::getDatosInactivos() {
    set<DtVideojuego>* dtInactivos = new set<DtVideojuego>;
    for (map<string, Videojuego*>::iterator it = videojuegos->begin(); it != videojuegos->end(); ++it) {
        if (!(it->second->estaActivo())) {
            dtInactivos->insert(it->second->obtenerDatosVideojuego());
        }
    }
    return dtInactivos;
}
*/
set<Videojuego*> * HandlerCatalogo::getSetComplement(set<Videojuego*> * actv){
    set<Videojuego*>* x = new set<Videojuego*>;
    for(map<string,Videojuego*>::iterator it = videojuegos->begin();it!=videojuegos->end();++it){
	if(actv->find(it->second) == actv->end())
	    x->insert(it->second);
    }
    return x;
}

set<DtVideojuego>* HandlerCatalogo::getDtVideojuegos(){
    set<DtVideojuego>* dts = new set<DtVideojuego>;
    for (map<string, Videojuego*>::iterator it = videojuegos->begin(); it != videojuegos->end(); ++it)
	dts->insert(it->second->obtenerDatosVideojuego());
    return dts;
}

Videojuego* HandlerCatalogo::findVideojuego(string nombreVideojuego) {
    map<string, Videojuego*>::iterator it = videojuegos->find(nombreVideojuego);
    if(it == videojuegos->end())
	return nullptr;
    else
	return it->second;
}

void HandlerCatalogo::addVideojuego(Videojuego* vj) {
    videojuegos->insert(map<string, Videojuego*>::value_type(vj->getNombre(), vj));
}

void HandlerCatalogo::remove(Videojuego* vj) {
    map<string, Videojuego*>::iterator it = videojuegos->find(vj->getNombre());
    delete it->second;
    videojuegos->erase(it); 
}

HandlerCatalogo::~HandlerCatalogo() {
    for (map<string, Videojuego*>::iterator it = videojuegos->begin(); it != videojuegos->end(); ++it) {
        delete it->second;
    }
    delete videojuegos;
}

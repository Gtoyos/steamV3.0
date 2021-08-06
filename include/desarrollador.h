/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef DESARROLLADOR
#define DESARROLLADOR

#include "usuario.h"
#include "categoria.h"
#include "estadistica.h"
#include "videojuego.h"
#include "dtEstadistica.h"
#include "dtDesarrollador.h"

#include <string>
#include <set>
#include <map>

class Desarrollador: public Usuario {
    private:
        std::string empresa;
        std::map<std::string,Videojuego *> * videojuegosDesarrollados;
        std::map<std::string,Estadistica *> * estadisticas;
    public:
        Desarrollador(DtDesarrollador);
        void setEmpresa(std::string);
        std::string getEmpresa();
        void add(Videojuego *);
        void remove(Videojuego *);
        Videojuego * findVideojuego(std::string); 
        void add(Estadistica *);
        void remove(Estadistica *);
        Estadistica * findEstadistica(std::string);
	std::set<Estadistica *> * getEstadisticas(); 
        std::set<std::string> * getVjSinPartidasActivas();
        std::set<std::string> * getVideojuegosDesarrollados();
        Videojuego * publishVideogame(DtVideojuego,std::map<std::string,Categoria *> *);
        void suscribirEstadistica(Estadistica *);
        std::set<DtEstadistica> * solicitarEstadisticas(Videojuego *);
	void resetEstadisticas();
        ~Desarrollador();
};

#endif

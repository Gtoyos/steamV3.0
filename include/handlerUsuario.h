/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */


#ifndef HANDLER_USUARIO
#define HANDLER_USUARIO

#include <string>
#include <map>
#include "usuario.h"
#include "jugador.h"

using std::string;
using std::map;

class HandlerUsuario {
private:
    static HandlerUsuario* instancia;
    Usuario* loggedUser;
    map<string, Usuario*>* usuarios;
    HandlerUsuario();
public:
    static HandlerUsuario* getInstance();
    void setLoggedUser(Usuario*);
    Usuario* getLoggedUser();
    Usuario* findUsuario(string);
    Jugador* findJugador(string);
    bool existeUsuario(string);
    void addUsuario(Usuario*);
    bool hayUsuarios();
    map<string, Usuario*>* obtenerUsuarios();
    ~HandlerUsuario();
};

#endif

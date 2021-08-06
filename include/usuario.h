/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef USUARIO
#define USUARIO

#include "dtUsuario.h"
#include <string>
using std::string;

class Usuario {
    protected:
        std::string email;
        std::string contrasenia;
    public:
        Usuario(DtUsuario);
	Usuario(std::string,std::string);
	string getEmail();
	string getContrasenia();
	virtual ~Usuario(){}
};

#endif

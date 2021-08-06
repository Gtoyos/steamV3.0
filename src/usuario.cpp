/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include "../include/usuario.h"
#include "../include/dtUsuario.h"

#include <string>

Usuario::Usuario(DtUsuario du) {
    email = du.getEmail();
    contrasenia = du.getContrasenia();
}
Usuario::Usuario(string nam, string pass){
    email = nam;
    contrasenia = pass;
}
std::string Usuario::getEmail(){
    return email;
}
std::string Usuario::getContrasenia(){
    return contrasenia;
}

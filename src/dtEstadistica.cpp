/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */
#include <../include/dtEstadistica.h>

using std::string;

DtEstadistica::DtEstadistica(string nom, string des, float vit) {
    valor = vit;
    nombre = nom;
    descripcion = des;
}

float DtEstadistica::getValor() const{
    return valor; 
}

string DtEstadistica::getNombre() const{ 
    return nombre;
}

string DtEstadistica::getDescripcion() const{
    return descripcion;
}

//corregir luego :^)
ostream& operator<<(ostream& o, DtEstadistica p) {
    o << "Lista de precios: en desarrollo...\n";
    return o;
}

bool operator<(const DtEstadistica v1,const DtEstadistica v2){
    return (v1.nombre < v2.nombre);
}



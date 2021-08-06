/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */


#ifndef DT_ESTADISTICA
#define DT_ESTADISTICA

#include <iostream>
#include <string>

using std::ostream;
using std::string;

class DtEstadistica{
private:
    string nombre,descripcion;
    float valor;
public:
    DtEstadistica(string,string, float);
    float getValor() const;
    string getDescripcion() const;
    string getNombre() const;
    friend bool operator<(const DtEstadistica,const DtEstadistica);
};

// Sobrecarga del operador de flujo.
ostream& operator<<(ostream&, DtEstadistica);

#endif

/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef DT_PRECIOS
#define DT_PRECIOS

#include <iostream>
#include <string>

using std::ostream;
using std::string;

class DtPrecios {
private:
    float mensual, trimestral, anual, vitalicia;
public:
    DtPrecios(float, float, float, float);
    float getMensual();
    float getTrimestral();
    float getAnual();
    float getVitalicia();
};

// Sobrecarga del operador de flujo.
ostream& operator<<(ostream&, DtPrecios);

#endif

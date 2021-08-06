/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#ifndef DT_FECHAHORA
#define DT_FECHAHORA

#include <iostream>
#include <string>

using std::ostream;
using std::string;

class DtFechaHora {
private:
    int anio, mes, dia, hora, min;
public:
    DtFechaHora(); // Devuelve la fecha actual.
    DtFechaHora(int, int, int, int, int);
    int getAnio();
    int getMes();
    int getDia();
    int getHora();
    int getMinuto();
    float diffHoras(DtFechaHora); // Devuelve la diferencia entre fechas en horas. ATENCION: La fecha ingresada debe ser mayor a la actual.
    friend bool operator<(const DtFechaHora, const DtFechaHora);
    string getString();
};

// Sobrecarga del operador de flujo.
ostream& operator<<(ostream&, DtFechaHora);

#endif

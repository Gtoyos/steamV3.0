/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */

#include <../include/dtPrecios.h>

using std::string;

DtPrecios::DtPrecios(float men, float tri, float an, float vit) {
    mensual = men;
    trimestral = tri;
    anual = an;
    vitalicia = vit;
}

float DtPrecios::getMensual() { return mensual; }

float DtPrecios::getTrimestral() { return trimestral; }

float DtPrecios::getAnual() { return anual; }

float DtPrecios::getVitalicia() { return vitalicia; }

ostream& operator<<(ostream& o, DtPrecios p) {
    o << "Lista de precios: \n" << "\tMensual: " << p.getMensual() << "$\n" << "\tTrimestral: " << p.getTrimestral()
        << "$\n" << "\tAnual: " << p.getAnual() << "$\n" << "\tVitalicia: " << p.getVitalicia() << "$\n";
    return o;
}

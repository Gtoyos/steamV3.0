/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class implementation 
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */
#include <../include/dtFechaHora.h>

#include <ctime>

DtFechaHora::DtFechaHora() {
    time_t now = time(0);
	tm* time = localtime(&now);
	dia = time->tm_mday;
	mes = time->tm_mon + 1; // tm_mon devuelve el mes donde enero es igual a 0 (por lo tanto se suma uno).
	anio = time->tm_year + 1900; // tm_year devuelve los anios despues de 1900 (por lo tanto hay que sumarlos).
    hora = time->tm_hour;
	min = time->tm_min;
    //segundo = time->tm_min;
}

DtFechaHora::DtFechaHora(int a, int m, int d, int hh, int mm) {
    if( (d < 1 || d > 31) || (m < 1 || m > 12) || (a < 1900) ) {
	    throw std::invalid_argument("La fecha indicada no es valida");
    }
    dia = d;
    mes = m;
    anio = a;
    hora = hh;
    min = mm;
}

int DtFechaHora::getAnio() { return anio; }

int DtFechaHora::getMes() { return mes; }

int DtFechaHora::getDia() { return dia; }

int DtFechaHora::getHora() { return hora; }

int DtFechaHora::getMinuto() { return min; }

//int DtFechaHora::getSegundo() { return segundo; }

float DtFechaHora::diffHoras(DtFechaHora fFinal) {
    struct tm inicial = {0};
    inicial.tm_hour = hora;   
    inicial.tm_min = min; 
    //inicial.tm_sec = segundo;
    inicial.tm_year = anio - 1900; 
    inicial.tm_mon = mes - 1; 
    inicial.tm_mday = dia;
    struct tm ultimo = {0};
    ultimo.tm_hour = fFinal.hora;   
    ultimo.tm_min = fFinal.min; 
    //ultimo.tm_sec = fFinal.segundo;
    ultimo.tm_year = fFinal.anio - 1900; 
    ultimo.tm_mon = fFinal.mes - 1; 
    ultimo.tm_mday = fFinal.dia;
    float diff = difftime(mktime(&ultimo), mktime(&inicial)) / 60.0 / 60.0;
    return diff;
}

bool operator<(const DtFechaHora dt1, const DtFechaHora dt2) {
    int min1, min2 = 0;
    min1 = dt1.min + (dt1.hora + (dt1.dia + (dt1.mes + (dt1.anio) * 12) * 31) * 24) * 60;
    min2 = dt2.min + (dt2.hora + (dt2.dia + (dt2.mes + (dt2.anio) * 12) * 31) * 24) * 60;
    return (min1 < min2);
}

string DtFechaHora::getString() {
    string texto = "";
    texto = texto + std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio) + " - ";
    if (hora < 10)
        texto = texto + "0";
    texto = texto + std::to_string(hora) + ":";
    if (min < 10)
        texto = texto + "0";
    texto = texto + std::to_string(min);
    return texto;
}

ostream& operator<<(ostream& o, DtFechaHora d) {
    o << d.getDia() << "/" << d.getMes() << "/" << d.getAnio() << " - ";
    if (d.getHora() < 10)
        o << "0";
    o << d.getHora() << ":";
    if (d.getMinuto() < 10)
        o << "0";
    o << d.getMinuto();
    //if (d.getSegundo() < 10)
    //    o << "0";
    //o << d.getSegundo();
    return o;
}
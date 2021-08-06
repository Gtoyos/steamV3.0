/* Laboratorio Programacion IV - INCO/FING/UDELAR
 * Laboratorio 4 - Class declaration
 * Autores (por nombre):
 * 	Alexis Baladon
 * 	Guillermo Toyos
 * 	Jorge Machado
 * 	Juan Jose Mangado
 * 	Mathias Ramilo
 */


#ifndef HANDLER_CATEGORIA
#define HANDLER_CATEGORIA

#include <string>
#include <map>
#include <set>
#include "categoria.h"
#include "genero.h"
#include "plataforma.h"

using std::string;
using std::map;
using std::set;

class DtCategoria;

class HandlerCategoria {
private:
    static HandlerCategoria* instancia;
    map<string, Categoria*>* categorias;
    HandlerCategoria();
public:
    static HandlerCategoria* getInstance();
    set<DtCategoria>* getDtGenders();
    set<DtCategoria>* getDtPlatforms();
    set<DtCategoria>* getDtCategories();
    Genero* findGender(string);
    Plataforma* findPlatform(string);
    Categoria* findCategory(string);
    void addCategoria(Categoria*);
    ~HandlerCategoria();
};

#endif

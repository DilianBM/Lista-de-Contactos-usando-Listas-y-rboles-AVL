#ifndef NODO_H
#define NODO_H
#include "Contacto.h"

class Nodo
{
public:
    Nodo();
    virtual ~Nodo();
    Nodo(Contacto *);
    void append(Contacto *);
    string buscar(string nom);

    void borrar(string nom);
    Nodo * cabeza();
    void modifique(string nom,int op,string dato);
    string show();
    void ordenar();

    bool used;
    Nodo *next;
    Contacto *persona;

protected:

private:
};

#endif // NODO_H

#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <iostream>
#include "BTreeG2.h"
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <Interfaz.h>

#include <cstring>

class Interfaz
{
public:
    Interfaz();
    virtual ~Interfaz();
    void menu(Nodo *,BTreeG2 *);




protected:

private:
};

#endif // INTERFAZ_H

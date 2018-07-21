#ifndef BTREEG2_H
#define BTREEG2_H
#include <string>       //string
#include <sstream>      //ostringstream
#include <new>          //new, delete
#include <iostream>     //cin, cout
#include "Nodo.h"


using namespace std;

class BTreeG2
{
public:
    BTreeG2();
    BTreeG2(Contacto *h );
    // BTreeG2(Listas *h);
    virtual ~BTreeG2();
    void add(Contacto *h);
    string getTraverseIPD();
    void rotateLL ();
    void rotateRR();
    void rotateLR();
    void rotateRL();
    void balancear();
    int altura();

    string buscar(string nom);
    int fe();
    string showTree(string);
    void migra(Nodo *);

    Contacto *persona;
    BTreeG2 *izq;
    BTreeG2 *der;
    bool used;
protected:

private:
};

#endif // BTREEG2_H

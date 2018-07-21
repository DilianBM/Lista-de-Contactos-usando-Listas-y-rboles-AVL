#ifndef CONTACTO_H
#define CONTACTO_H
#include "NumTelefono.h"
#include <string>
class Contacto
{
public:
    Contacto(string,string,string,NumTelefono*);
    Contacto();
    Contacto(Contacto *h);
    virtual ~Contacto();
    string  busquephone();
    string nombre="";
    string tipocontacto="";
    string correo="";
    NumTelefono* phone;

protected:

private:
};

#endif // CONTACTO_H

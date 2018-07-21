/*Dilian Badilla, Alberto soto
  clase Contacto
  versión 1
  esta clase Contacto tiene las caracteristicas del contacto como nombre,numero,correo,etc y crea un contacto con estos atributos
*/
#include "Contacto.h"

Contacto::Contacto(string n, string tip,string corre,NumTelefono* num)//crea un contacto con todos estos atributos
{
    nombre=n;
    tipocontacto=tip;
    phone=num;
    correo=corre;
}
Contacto::Contacto()
{
    nombre="";
    phone=nullptr;
}
/*
constructor que clona contactos
*/
Contacto::Contacto(Contacto *h)
{
    nombre=h->nombre;
    tipocontacto=h->tipocontacto;
    correo=h->correo;
    phone=h->phone;
}
Contacto::~Contacto()
{
    //dtor
}
/*
busca los posibles numeros de contacto y los devuelve en una string
*/
string Contacto::busquephone()
{
    string h="-";//funciona como identificador que el contacto no tiene numero
    string result;
    if(phone->celular.compare(h)!=0)
    {
        result=result+"celular: "+phone->celular+" ";
    }
    if(phone->hogar.compare(h)!=0)
    {
        result=result+"hogar: "+phone->hogar+" ";
    }
    if(phone->trabajo.compare(h)!=0)
    {
        result=result+"trabajo: "+phone->trabajo+" ";
    }
    return result;
}

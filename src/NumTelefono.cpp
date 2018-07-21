/*Dilian Badilla, Alberto soto
  clase NumTelefono
  versión 1
  esta clase contiene diversos numeros de telefono ya que cada contacto puede poseer tres tipos de numeros
*/
#include "NumTelefono.h"
#include <string>
#include <sstream>
NumTelefono::NumTelefono()
{
    //ctor
}

NumTelefono::~NumTelefono()
{
    //dtor
}
/*
no retorna nada y asigna el numero de celular
*/
void NumTelefono::setcel(string phone)
{
    celular+=phone;
}
/*
no retorna nada y asigna el numero de telefono de hogar
*/
void NumTelefono::setnumhogar(string phone)
{
    hogar=phone;
}
/*
no retorna nada y asigna el numero de telefono de trabajo
*/
void NumTelefono::setnumtrabajo(string phone)
{
    trabajo=phone;
}

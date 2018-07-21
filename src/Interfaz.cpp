/*Dilian Badilla, Alberto soto
  clase Interfaz
  versión 1
  esta clase es la encargada de mostrar el menu al usuario y de llamar a los metodos de todas las clases
*/
#include "Interfaz.h"
#include <iostream>
#include "BTreeG2.h"
#include <stdio.h>
#include <string.h>
#include "Nodo.h"
#include "Contacto.h"
#include "NumTelefono.h"
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <exception>


Interfaz::Interfaz()
{
    //ctor
}

Interfaz::~Interfaz()
{
    //dtor
}
/*
menu el cual recibe un objeto de la clase nodo y uno de la clase arbol y llama a todos los metodos
*/
void Interfaz::menu(Nodo *prue,BTreeG2 *arbol)
{


    Contacto *cont= new Contacto();
    NumTelefono *e=new NumTelefono();
    e->setcel(" ");
    cout << "Ingrese la opcion que desea ejecutar: \n 1.Agregar un contacto. \n 2.Buscar datos de contacto. \n 3.Modificar datos de contacto. \n 4.Borrar Contacto. \n 5.Mostrar lista ordenada ascendente. \n 6.Migrar datos a un arbol balanceado. \n 7.Buscar en arbol balanceado . \n 8. para Salir.";
    string numero;
    cin >>numero;
    int opcion=atoi(numero.c_str());
    string nom=" ";
    string tipcon= " ";
    string correo=" ";
    string phone;
    int op;

    bool error=true;
    string nuevovalor;
    while(opcion!=9)
    {
        switch (opcion)
        {
        case 1:
            while(error==true)
            {
                try
                {

                    cout << "Ingrese el nombre y el apellido sin espacio y presione enter."<<endl;
                    cin>>nom;
                    //throw 1;

                    error=false;
                }
                catch (exception& e)
                {
                    cout << "Error ";
                    error =true;

                }
            }

            cout << "Si desea agregar un correo electronico, ingreselo. Sino, ingrese un guion (-) y presione enter."<<endl;
            cin>>correo;

            cout << "Si desea agregar un tipo de contacto, ingreselo (familiar, trabajo, amigo, comercial o profesional). Sino, ingrese un guion (-) y presione enter."<<endl;
            cin>>tipcon;

            cout << "Si desea agregar un numero de celular, ingreselo. Sino, ingrese un guion (-) y presione enter."<<endl;
            cin>>phone;
            e->setcel(phone);

            cout << "Si desea agregar un numero de hogar, ingreselo. Sino, ingrese un guion (-) y presione enter."<<endl;
            cin>>phone;
            e->setnumhogar(phone);

            cout << "Si desea agregar un numero de trabajo, ingreselo. Sino, ingrese un guion (-) y presione enter."<<endl;
            cin>>phone;
            e->setnumtrabajo(phone);

            for(int i = 0; i < nom.length(); i++)
            {
                nom[i] = tolower(nom[i]);
            }

            cont=new Contacto(nom,tipcon,correo,e);
            prue->append(cont);
            menu(prue,arbol);

            break;

        case 2:

            cout<< "Ingrese el nombre y el apellido de la persona que desea buscar sin espacio y presione enter."<<endl;
            cin>>nom;

            for(int i = 0; i < nom.length(); i++)
            {
                nom[i] = tolower(nom[i]);
            }

            cout<<prue->buscar(nom)<<endl;
            menu(prue,arbol);

            break;

        case 3:

            op;
            nuevovalor;
            cout<<"Ingrese el nombre y el apellido de la persona que desea modificar sin espacio."<<endl;
            cin>>nom;

            cout<<"Escoja mediante el indice, que quiere modificar de ese contacto. \n 1.Correo electronico. \n 2.Tipo de contacto (familiar, trabajo, comercial, amigo, trabajo). \n 3.Numero de celular. \n 4.Numero de hogar. \n 5.Numero de trabajo."<<endl;
            cin>>op;

            cout<<"Ingrese el nuevo valor para el atributo escojido"<<endl;
            cin>>nuevovalor;

            for(int i = 0; i < nom.length(); i++)
            {
                nom[i] = tolower(nom[i]);
            }

            prue->modifique(nom, op, nuevovalor);
            menu(prue,arbol);

            break;

        case 4:
            cout<<"Ingrese el nombre y apellido sin espacioos del contacto que desea borrar"<<endl;
            cin>>nom;

            for(int i = 0; i < nom.length(); i++)
            {
                nom[i] = tolower(nom[i]);
            }

            prue->borrar(nom);
            menu(prue,arbol);
            break;

        case 5:

            prue->ordenar();
            cout<<prue->show()<<endl;
            menu(prue,arbol);
            break;


        case 6:
            arbol->migra(prue->cabeza());
            cout<<"arbol: \n"<<arbol->showTree("")<<endl;
            menu(prue,arbol);
            break;

        case 7:

            cout<<"Ingrese el nombre y apellido de la persona que desea buscar sin espacio y presione enter."<<endl;
            cin>>nom;
            for(int i = 0; i < nom.length(); i++)
            {
                nom[i] = tolower(nom[i]);
            }
            cout<<"Datos de la persona:"<<arbol->buscar(nom)<<endl;
            menu(prue,arbol);
            break;

        default :
            exit(0);






        }

    }

}


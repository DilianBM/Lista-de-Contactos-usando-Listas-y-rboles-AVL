/*Dilian Badilla, Alberto soto
  clase Nodo
  versión 1
  esta clase es donde se crea la lista,se modifican datos de este, se borran contactos,se ordenan,etc
*/
#include "Nodo.h"
#include <string>
#include <sstream>
#include "NumTelefono.h"
#include "BTreeG2.h"
#include "Contacto.h"
#include <ctype.h>
using namespace std;
Nodo::Nodo()
{
    used=false;
    next=nullptr;
}

Nodo::~Nodo()
{
    Nodo *iter=this;        //iterador de nodos. Inicia en la cabeza de la lista
    Nodo *aBorrar;              //protege el apuntador a borrar
    while (iter!=nullptr)             //mientras hallan nodos
    {
        aBorrar=iter;           //marque el nodo a borrar
        iter=iter->next;   //itere al siguiente nodo
        delete aBorrar;
    }

}


/*
Costructor que crea los nodo de la listas con el contacto que le entra como parametro
*/
Nodo::Nodo(Contacto *per)
{
    persona=per;
    used=true;
    next=nullptr;
}
Nodo * Nodo::cabeza()
{
    Nodo *p=this;
    return p;
}
/*
no retorna nada y recibe una string con el nombre y apellido y cual dato es el que va a modificar y
el dato que va a reemplazar
*/
void Nodo::modifique(string nom,int op,string dato)
{
    bool encontrado=false;
    Nodo *p=this;
    if(p->used==false)
    {
        cout<<"no puede modificar algo que no existe";
    }
    else
    {
        while(p!=nullptr && encontrado==false)
        {
            if(p->persona->nombre.compare(nom)==0)
            {
                encontrado=true;

            }
            else
            {
                p=p->next;
            }
        }
        if(op==1 && encontrado==true && p->used==true)
        {
            p->persona->correo=dato;

        }
        if(op==2 && encontrado==true && p->used==true)
        {
            p->persona->tipocontacto=dato;
        }
        if(op==3 && encontrado==true && p->used==true)
        {
            p->persona->phone->celular=dato;

        }
        if(op==4 && encontrado==true && p->used==true)
        {
            p->persona->phone->hogar=dato;

        }
        if(op==5 && encontrado==true && p->used==true)
        {

            p->persona->phone->trabajo=dato;
        }
    }

}


/*
agrega nodos al final de la lista y recibe un contacto con el cual crea el nodo y no retorna nada
*/
void Nodo::append(Contacto *per )  //agregue al final un nuevo nodo
{

    if(used==false)//caso en el que este vacia
    {
        persona=per;
        used=true;
    }
    else
    {
        if(next==nullptr)//caso en el que al menos ahi un elemento
        {
            next= new Nodo(per);
        }
        else
        {
            Nodo *iter=this;        //iter es el nodo actual
            while(iter->next!=nullptr)  //si nodo actual no apunta hacia nulo que itere
            {
                iter=iter->next;
            }
            iter->next=new Nodo(per); //nodo actual apunte hacia nuevo nodo
        }
    }

}
/*
no recibe nada y retorna una string con toda la informacion de los nodos de la lista
*/
string Nodo::show()
{
    Nodo *iter=this;
    string result="";
    ostringstream os;
    bool fin=false;
    while(!fin  && used!=false)
    {

        os<<iter->persona->nombre<<"  "<<iter->persona->correo<<" "<<iter->persona->phone->celular<<" "<<iter->persona->phone->hogar<<" "<<iter->persona->phone->trabajo<<" "<<iter->persona->tipocontacto<<"\n"<<endl;

        result=os.str();

        if(iter->next==nullptr)
        {
            fin=true;
        }
        else
        {
            iter=iter->next;
        }

    }
    return result;
}

/*
recibe una string con el nombre y apellido y busca ese contacto y mete toda su imformacion en la string que retorna
*/
string Nodo::buscar(string nom)
{
    Nodo *iter=this;
    string result="";
    ostringstream os;

    if(iter->used==false)
    {
        os<<"ese contacto no existe";
        result=os.str();
    }
    else
    {
        while((iter->persona->nombre.compare(nom)!= 0) && (iter->next!=nullptr))//mientras no lo haya encontrado y no llegue al final
        {
            iter=iter->next;
        }
        if(iter->persona->nombre.compare(nom)==0)
        {
            string numero = iter->persona->busquephone();
            os<<"Nombre: "<<iter->persona->nombre<<" "<<" Tipo de contacto: "<<iter->persona->tipocontacto<<" "<<" Correo electronico: "<<iter->persona->correo<<" "<< "Numero(s): "<<numero<<endl,
              result=os.str();
        }
        else
        {
            os<<"ese contacto no esta en tu lista de contactos";
            result=os.str();
        }

    }


    return result;
}
/*
no recibe ni retorna nada solo ordena la lista de manera ascendente
*/
void Nodo::ordenar()
{
    Nodo *iter=this;

    while(iter!=nullptr)
    {
        Nodo *ptr=iter->next;
        while(ptr!=nullptr)
        {

            if(iter->persona->nombre.compare(ptr->persona->nombre)>0)
            {

                Contacto *temp=new Contacto(iter->persona);

                iter->persona->nombre=ptr->persona->nombre;// asigna informacion de otro nodo lista
                iter->persona->tipocontacto=ptr->persona->tipocontacto;
                iter->persona->correo=ptr->persona->correo;
                iter->persona->phone=ptr->persona->phone;

                ptr->persona=temp;
            }
            ptr=ptr->next;
        }

        iter=iter->next;
    }


}
/*
no retorna nada y recibe una string con el nombre de un contacto y lo borra
*/
void Nodo::borrar(string nom)
{
    bool encontrado=false;
    Nodo *auxiliar =this ;
    Nodo *anterior=nullptr;
    Nodo *puntero;
    if(auxiliar->used == false)
    {
        cout<<"El contacto no existe."<<endl;
    }
    else
    {
        if(auxiliar!=nullptr)
        {
            while(auxiliar->next!=nullptr && auxiliar->persona->nombre!=nom)
            {
                anterior = auxiliar;
                auxiliar = auxiliar->next;


            }

            if(auxiliar->used == false)
            {
                cout<<"El contacto no existe."<<endl;
            }
            else if(anterior==nullptr)
            {
                if(auxiliar->next==nullptr)
                {
                    auxiliar->used=false;
                }
                else
                {
                    auxiliar->persona->nombre =  auxiliar->next->persona->nombre;
                    auxiliar->persona->tipocontacto =  auxiliar->next->persona->tipocontacto;
                    auxiliar->persona->correo =  auxiliar->next->persona->correo;
                    auxiliar->persona->phone =  auxiliar->next->persona->phone;
                    puntero =  auxiliar->next->next;
                    auxiliar->next->next=nullptr;
                    auxiliar->next->used = false;
                    auxiliar->next=puntero;
                }
            }
            else
            {
                anterior->next = auxiliar->next;
                auxiliar->next = nullptr;
                auxiliar->used = false;
            }
        }
    }
}


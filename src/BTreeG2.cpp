/*Dilian Badilla, Alberto soto
  clase BTreeG2
  versión 1
  esta clase es la encargada de migrar los datos al arbol y contiene los metodos para buscar y balancear el arbol
*/
#include "BTreeG2.h"
#include <sstream>
#include <string>

using namespace std;
BTreeG2::BTreeG2()
{
    used=false;
    izq=nullptr;
    der=nullptr;
}

/*
constructor que recibe un nodo de una lista y crea un nodo del arbol
*/
BTreeG2::BTreeG2(Contacto *h)
{
    persona=h;
    izq=nullptr;
    der=nullptr;
    used=true;
}
/*
destructor destruye el arbol en forma IPD
*/
BTreeG2::~BTreeG2()
{
    if (izq != nullptr)
    {
        if(izq->izq=nullptr)
        {
            delete izq;
        }
        else
        {
            izq->~BTreeG2();
        }
    }
    delete persona;
    if (der != nullptr)
    {
        if(der->der=nullptr)
        {
            delete der;
        }
        else
        {
            der->~BTreeG2();
        }
    }
}
/*
no retorna nada y recibe contacto y crea un nodo de un arbol con  base en el contacto de parametro
*/
void BTreeG2::add(Contacto *p)
{
    if(used==false)
    {
        persona= new Contacto(p);
        used=true;

    }
    else
    {
        if(persona->nombre.compare(p->nombre)<0)
        {
            if(der==nullptr)
            {
                der = new BTreeG2(p);

            }
            else
            {
                der->add(p);
            }
        }
        else
        {
            if(persona->nombre.compare(p->nombre)>0)
            {
                if(izq==nullptr)
                {
                    izq = new BTreeG2(p);


                }
                else
                {
                    izq->add(p);
                }
            }
        }

    }

}
/*
recibe una string con el nombre y apellido del contacto y retorna toda la informacion de este en una string
*/
string BTreeG2::buscar(string nom)
{
    string result="";
    ostringstream os;
    string numero="";
    if(persona->nombre=="")
    {
        cout<< "no existe ese elemento"<<endl;

    }
    else
    {


        if(persona->nombre.compare(nom)==0)//pregunta si el contenido de la raiz es el que busca
        {
            numero = persona->busquephone();
            os<<"Nombre:  "<<persona->nombre<<"  correo:  "<<persona->correo<<" tipo de contacto:  "
              <<persona->tipocontacto<<"  numero;  "<<numero<<endl;
        }
        else
        {

            if(persona->nombre.compare(nom)>0)//pregunta si el nombre es menor al nombre que contiene la raiz
            {
                if(izq!=nullptr)
                {
                    return izq->buscar(nom);
                }
            }
            if(persona->nombre.compare(nom)<0)//pregunta si el nombre es mayor al nombre que contiene la raiz
            {
                if(der!=nullptr)
                {
                    return der->buscar(nom);
                }
            }
        }

    }
    return os.str();
}
/*
no recibe nada y retorna en una string el arbol de manera ascendente
*/
string BTreeG2::getTraverseIPD()
{
    string hilera="";
    ostringstream o;
    if (used==false)
    {
        o<<"";
    }
    else
    {
        if (izq != nullptr)
        {
            o<<"  "<<izq->getTraverseIPD()<<" "<<endl;

        }
        o<<" "<<persona->nombre<<"  "<<persona->correo<<persona->phone->celular<<" "<<persona->tipocontacto<<"\n";
        if (der != nullptr)
        {
            o<<der->getTraverseIPD();
        }
    }
    return o.str();
}
/*
recibe la cabeza de la lista y va migrando los nodos de la lista a un arbol Balanceado
*/
void BTreeG2::migra(Nodo *p)
{
    if(p->used!=false ){
    while(p!=nullptr)
    {
        this->add(p->persona);
        this->balancear();
        p=p->next;

    }}

}
/*
imprime el arbol de forma DPI con una serie de tabs que permiten apreciar la forma del arbol
*/
string BTreeG2::showTree(string t)
{
    ostringstream hilera;
    if (used==false)
    {
        hilera<<"";
    }
    else
    {
        if (der != nullptr)
        {
            hilera<<der->showTree(t+"\t");
        }
        hilera<<t<<persona->nombre<<"\n";

        if (izq != nullptr)
        {
            hilera<<izq->showTree(t+"\t");
        }
    }
    return hilera.str();
}
/*
este metodo no recibe ni retorna nada, solo balancea el arbol cuando este
tiene un desbalance hacia la izquierda
*/
void BTreeG2::rotateLL ()
{
    Contacto *temp;
    BTreeG2 *ptr;
    temp=new Contacto(persona);
    persona=izq->persona;
    ptr=izq;
    izq=izq->izq;
    ptr->izq=ptr->der;
    ptr->der=der;
    der=ptr;
    der->persona=temp;
}
/*
este metodo no recibe ni retorna nada, solo balancea el arbol cuando este
tiene un desbalance hacia la derecha
*/
void BTreeG2::rotateRR()
{
    Contacto *temp;
    BTreeG2 *ptr;
    temp= new Contacto(persona);
    persona=der->persona;
    ptr=der;
    der=der->der;
    ptr->der=ptr->izq;
    ptr->izq=nullptr;
    ptr->izq=izq;
    izq=ptr;
    izq->persona=temp;

}
/*
realiza la doble rotacion izquierda-derecha y no recibe ni retorna nada
*/
void BTreeG2:: rotateLR()
{
    BTreeG2 *ptr;
    ptr=izq->der;
    izq->der=ptr->izq;
    ptr->izq=izq;
    izq=ptr;
    rotateLL();


}
/*
realiza la doble rotacion derecha-izquierda y no recibe ni retorna nada
*/
void BTreeG2:: rotateRL()
{
    BTreeG2 *ptr;
    ptr=der->izq;
    der->izq=nullptr;
    der->izq=ptr->der;
    ptr->der=nullptr;
    ptr->der=der;
    der=nullptr;
    der=ptr;
    rotateRR();
}
/*
no recibe nada y retorna un entero con la altura del arbol
*/
int BTreeG2::altura()
{
    int altura=0;
    int alturaDer=0;
    int alturaizq=0;
    if(izq!=nullptr)
    {
        alturaizq +=izq->altura();
    }
    if(der!=nullptr)
    {
        alturaDer +=der->altura();

    }
    if(alturaizq>alturaDer)
    {
        altura=alturaizq+1;
    }
    else
    {
        altura=alturaDer+1;

    }
    return altura;
}
/*
no recibe nada y retorna un entero con el Factor de Equlibrio del arbol
*/
int BTreeG2:: fe()
{
    int fe;
    int alder=0;
    int alizq=0;
    if(der!=nullptr)
    {
        alder= der->altura();
    }
    if(izq!=nullptr)
    {
        alizq=izq->altura();
    }
    fe=alder-alizq;
    return fe;
}
/*
metodo que integra los 4 metodos anteriores de balanceo y con
el  FE del arbol ve en que parte esta el desbalance
*/
void BTreeG2::balancear()
{

    if(izq!=nullptr )
    {

        if(this->fe()==-2)
        {

            if(izq->izq!=nullptr)
            {
                if(izq->fe()<=-1)
                {
                    rotateLL();

                }
                else
                {
                    if(izq->fe()>=1)
                    {
                        rotateLR();
                    }

                }
            }
        }
    }

    if(der!=nullptr )
    {
        if(this->fe()==2)
        {
            if(der->der!=nullptr)
            {
                if(der->fe()<=-1)
                {
                    rotateRL();

                }
                else
                {
                    if(der->fe()>=1)
                    {
                        rotateRR();

                    }
                }
            }


        }
    }


}

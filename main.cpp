/*Dilian Badilla, Alberto soto
  main
  versión 1
  aqui se llama a todo a ejecucion y se utiliza para probar si los metodos funcionan
*/
#include <stdio.h>
#include "Nodo.h"
#include "BTreeG2.h"
#include "Interfaz.h"
#include <vector>

using namespace std;

int main()
{
    string show;
     try
    {
        vector<int> v = {42, 43, 35, 27};
        //v.at(4) = 1;
        v.at(74) = 1;
    }

    catch (exception& e)
    {
        cout << "error" << endl;
    }

    Nodo *prue=new Nodo();
    BTreeG2* p=new BTreeG2();
    Interfaz *interfaz= new Interfaz();
    interfaz->menu(prue,p);

    //pruebas a para ver si los metodos no se caen
    /*
        NumTelefono* e=new NumTelefono();
        e->setcel("CELULAR");
        Contacto *per1 = new Contacto("d","k","alfa",e);
        Contacto *per2 = new Contacto("k","a","70",e);
        Contacto *per3 = new Contacto("p","amigo","70",e);
        Contacto *per4 = new Contacto("r","amigo","70",e);
        Contacto *per5 = new Contacto("z","amigo","70",e);
        Contacto *per6 = new Contacto("a","amigo","70",e);
        Contacto *per7 = new Contacto("f","amigo","70",e);
        Contacto *per8 = new Contacto("q","amigo","70",e);
        Contacto *per9 = new Contacto("h","amigo","70",e);
        Contacto *per10 = new Contacto("w","amigo","70",e);



        prue->append(per1);
        prue->append(per2);
        prue->append(per3);
        prue->append(per4);
        prue->append(per5);
        prue->append(per6);
        prue->append(per7);
        prue->append(per8);
        prue->append(per9);
        prue->append(per10);
        prue->ordenar();
        show = prue->show();
        // cout<<show<<endl;
        //prue->modifique("maria", 2, "familia" );
        prue->cabeza();
        p->migra(prue->cabeza());
        cout<< p->buscar("l");
        //cout<<" "<<p->getTraverseIPD()<<" "<<endl;
        cout<<"arbol: "<<p->showTree("");
        // Contacto *per11 = new Contacto("ana","amigo","70",e);
        // Contacto *per12 = new Contacto("mar","amigo","70",e);
        // Contacto *per13 = new Contacto("carlos","amigo","70",e);



        // prue->append(per11);
        // prue->append(per12);
        // prue->append(per13);
        p->migra(prue->cabeza());
        cout<<"arbol: "<<p->showTree("");
        Contacto *per14 = new Contacto("sara","amigo","70",e);
        Contacto *per15 = new Contacto("tati","amigo","70",e);
        Contacto *per16 = new Contacto("angelica","amigo","70",e);
        prue->append(per14);
        prue->append(per15);
        prue->append(per16);
        p->migra(prue->cabeza());
        prue->borrar("angelica");
        prue->borrar("9");
        prue->modifique("maca",2,"j");
        prue->modifique("asadfdfsdfsdf",2,"j");
        cout<<"arbol: "<<p->showTree("");
        p->migra(prue->cabeza());
        cout<<"arbol: "<<p->showTree("");
        cout <<prue->show();

    */
    return 0;

}

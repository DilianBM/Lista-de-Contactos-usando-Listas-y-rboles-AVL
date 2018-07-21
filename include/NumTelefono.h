#ifndef NUMTELEFONO_H
#define NUMTELEFONO_H
#include <string>
#include <sstream>
using namespace std;
class NumTelefono
{
    public:
        NumTelefono();
        virtual ~NumTelefono();
        string celular="";
        string hogar="";
        string trabajo="";
        void setcel(string );
        void setnumhogar(string );
        void setnumtrabajo(string );


    protected:

    private:
};

#endif // NUMTELEFONO_H

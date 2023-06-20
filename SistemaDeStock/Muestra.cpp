#include "Muestra.h"
#include "Fecha.h"
#include <iostream>
#include <cstring>
#include "rlutil.h"
using namespace std;

void Muestra::setID(int id)
{
    _ID = id;
}
void Muestra::setNombreCliente(string NombreCliente)
{
    strcpy(_NombreCliente, NombreCliente.c_str());
}
void Muestra::setFecha(Fecha aux){
    _fecha= aux;
}

Fecha Muestra::getFecha(){

return _fecha;
}

int Muestra::getID()
{
    return _ID;
}
string Muestra::getNombreCliente()
{
    return _NombreCliente;
}

void Muestra::mostrar(int Aumentar)
{
        rlutil::locate(0,Aumentar);
         cout << "|";
         rlutil::locate(4,Aumentar);
         cout << _ID;
         rlutil::locate(10,Aumentar);
         cout << "|";
         rlutil::locate(13,Aumentar);
         cout << _NombreCliente;
         rlutil::locate(39,Aumentar);
         cout << "|";
         rlutil::locate(42,Aumentar);
         cout << _fecha.toString();
         rlutil::locate(57,Aumentar);
         cout << "|"<<endl;
}

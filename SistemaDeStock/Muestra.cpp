#include "Muestra.h"
#include "Fecha.h"
#include <iostream>
#include <cstring>
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

void Muestra::mostrar()
{
    cout << "   "<<_ID<<"     ";
    cout << _NombreCliente<<"   ";
    cout << _fecha.toString()<<"       "<<endl;
}

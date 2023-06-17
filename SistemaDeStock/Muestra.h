#ifndef MUESTRA_H
#define MUESTRA_H
#include "ArticuloArchivo.h"
#include "ClienteArchivo.h"
#include "Fecha.h"

class Muestra
{
private:
    int _ID;
    char _NombreCliente[50];
    Fecha _fecha;
public:
    void setID(int id);
    void setNombreCliente(string NombreCliente);
    void setNombCliente(Cliente NombreCliente);
    int getID();
    Fecha getFecha();
    void setFecha(Fecha aux);
    string getNombreCliente();
    void mostrar();
};

#endif // MUESTRA_H

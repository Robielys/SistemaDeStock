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
    int _IDcliente;
    Fecha _fecha;
public:
    void setID(int id);
    void setNombreCliente(string NombreCliente);
    void setIDcliente(int idcliente);
    void setFecha(Fecha aux);
    int getID();
    string getNombreCliente();
    int getIDcliente();
    Fecha getFecha();
    void mostrar(int Aumentar);
};

#endif // MUESTRA_H

#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "Domicilio.h"

class Cliente{
private:
    int _ID;
    char _NombreEmpresa[50];
    long _Cuit;
    char _Correo[50];
    Domicilio domicilioCliente;
    bool _Estado;
public:
    void setID(int id);
    void setNombreEmpresa(string NombreEmpresa);
    void setCuit(long Cuit);
    void setCorreo(string Correo);
    void setEstado(bool Estado);
    int getID();
    string getNombreEmpresa();
    long getCuit();
    string getCorreo();
    bool getEstado();
    void Cargar();
    void Mostrar(int c);
};

#endif // CLIENTE_H_INCLUDED

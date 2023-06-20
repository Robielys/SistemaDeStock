#include<iostream>
#include<string.h>
#include<cstring>
#include <istream>
using namespace std;
#include "Cliente.h"
#include "Funciones.h"
#include "rlutil.h"

void Cliente::setID(int id)
{
    _ID = id;
}

void Cliente::setNombreEmpresa(string NombreEmpresa)
{
    strcpy(_NombreEmpresa, NombreEmpresa.c_str());
}
void Cliente::setCuit(long long Cuit)
{
    _Cuit = Cuit;
}
void Cliente::setCorreo(string Correo)
{
    strcpy(_Correo, Correo.c_str());
}
void Cliente::setEstado(bool Estado)
{
    _Estado = Estado;
}

int Cliente::getID()
{
    return _ID;
}
string Cliente::getNombreEmpresa()
{
    return _NombreEmpresa;
}
long long Cliente::getCuit()
{
    return _Cuit;
}
string Cliente::getCorreo()
{
    return _Correo;
}
bool Cliente::getEstado()
{
    return _Estado;
}

void Cliente::Cargar()
{
    rlutil::cls();
    int validar=0;
    cout << "Ingresar Nombre de Empresa: ";
    cin >> _NombreEmpresa;
    do{
    cout << "Ingresar Cuit: ";
    cin>>_Cuit;
    }while(ValidarCuit(_Cuit)==false);
    cout << "Ingresar Correo: ";
    cin >> _Correo;
    _Estado = true;
}
void Cliente::Mostrar(int Aumentar)
{
    if(_Estado == true)
    {
        rlutil::locate(0,Aumentar);
         cout << "|";
         rlutil::locate(4,Aumentar);
         cout << _ID;
         rlutil::locate(10,Aumentar);
         cout << "|";
         rlutil::locate(12,Aumentar);
         cout << _Cuit;
         rlutil::locate(22,Aumentar);
         cout << "|";
         rlutil::locate(24,Aumentar);
         cout << _NombreEmpresa;
         rlutil::locate(43,Aumentar);
         cout << "|";
         rlutil::locate(45,Aumentar);
         cout << _Correo;
         rlutil::locate(73,Aumentar);
         cout << "|"<<endl;

    }

}

void Cliente::MostrarBaja(int Aumentar){
     if(_Estado == false)
    {
        rlutil::locate(0,Aumentar);
         cout << "|";
         rlutil::locate(4,Aumentar);
         cout << _ID;
         rlutil::locate(10,Aumentar);
         cout << "|";
         rlutil::locate(12,Aumentar);
         cout << _Cuit;
         rlutil::locate(22,Aumentar);
         cout << "|";
         rlutil::locate(24,Aumentar);
         cout << _NombreEmpresa;
         rlutil::locate(43,Aumentar);
         cout << "|";
         rlutil::locate(45,Aumentar);
         cout << _Correo;
         rlutil::locate(73,Aumentar);
         cout << "|"<<endl;

    }

}

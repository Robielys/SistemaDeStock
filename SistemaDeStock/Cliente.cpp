#include<iostream>
#include<string.h>
#include<cstring>
#include <istream>
using namespace std;
#include "Cliente.h"
#include "Funciones.h"

void Cliente::setID(int id)
{
    _ID = id;
}

void Cliente::setNombreEmpresa(string NombreEmpresa)
{
    strcpy(_NombreEmpresa, NombreEmpresa.c_str());
}
void Cliente::setCuit(int Cuit)
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
int Cliente::getCuit()
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
    int validar=0;
    cout << "Ingresar Nombre de Empresa: ";
    cin >> _NombreEmpresa;
    do{
    cout << "Ingresar Cuit: ";
    cin>>_Cuit;
    }while(ValidarCuit(_Cuit)==true);
    cout << "Ingresar Correo: ";
    cin >> _Correo;
    _Estado = true;
}
void Cliente::Mostrar()
{
    if(_Estado == true)
    {
        cout<<_ID<<" "<<_NombreEmpresa<< " " <<_Cuit<< " "<<_Correo<<endl;
    }

}

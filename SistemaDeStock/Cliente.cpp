#include<iostream>
#include<string.h>
using namespace std;
#include "Cliente.h"
#include "ArchivoCliente.h"
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
void Cliente::setCuit(long Cuit)
{
    Cuit = Cuit;
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
long Cliente::getCuit()
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
    cout << "Ingresar Nombre de Empresa: ";
    cin >> _NombreEmpresa;
    cout << "Ingresar Cuit: ";
    cin >> _Cuit;
    cout << "Ingresar Correo: ";
    cin >> _Correo;
    _Estado = true;
}
void Cliente::Mostrar(int c)
{
    if(_Estado == true)
    {
        if(c==1){
        cout << espacio(1,2) <<_ID << espacio(sizeof(Cliente)/55,0) << _NombreEmpresa << espacio(sizeof(Cliente)/70,0)
        << _Cuit << espacio(sizeof(Cliente)/60,0) << _Correo << endl;
        /*cout << _ID << _NombreEmpresa << _Cuit << _Correo << endl;*/
        }
        else{
            cout << "  Cuit: " << _Cuit << "  Empresa: " << _NombreEmpresa << "  Correo: " <<_Correo << endl;
        }
    }

}

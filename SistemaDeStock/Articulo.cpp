#include<iostream>
#include <string.h>
using namespace std;
#include "Articulo.h"
#include "ArticuloArchivo.h"
#include "Funciones.h"
#include "rlutil.h"

void Articulo::setID(int ID)
{
    _ID =ID;
}
void Articulo::setCategoria(const char* Categoria)
{
    strcpy(_Categoria, Categoria);
}
void Articulo::setModelo(const char* Modelo)
{
    strcpy(_Modelo, Modelo);
}
void Articulo::setTipoDeMaterial(const char* TipoDeMaterial)
{
    strcpy(_TipoDeMaterial, TipoDeMaterial);
}
void Articulo::setCapacidad(int Capacidad)
{
    _Capacidad = Capacidad;
}
void Articulo::setDiametro(int Diametro)
{
    _Diametro = Diametro;
}
void Articulo::setStock(int Stock)
{
    if(Stock > 0)
    {
        _Stock += Stock;
    }
}
int Articulo::descontarStock(int stock)
{
    if(stock<= _Stock)
        {
            _Stock -= stock;
            return stock;
        }
        else
        {
            cout << "Cantidad ingresada es mayor al stock disponible"<< endl;
            cout << "Ingrese una cantidad menor o igual al Stock disponible"<< endl;
            cout << "El stock disponible es: " << _Stock << endl;
        }
   /* int validar=0;
    while(validar==0)
    {
        if(_Stock >= stock)
        {
            _Stock -= stock;
            validar=1;
            return stock;
        }
        else
        {
            cout << "Cantidad ingresada es mayor al stock disponible"<< endl;
            cout << "Ingrese una cantidad menor o igual al Stock disponible"<< endl;
            cout << "El stock disponible es: " << _Stock << endl;
        }
    }*/
}
void Articulo::setEstado(bool Estado)
{
    _Estado = Estado;
}
int Articulo::getID()
{
    return _ID;
}
const char* Articulo::getCategoria()
{
    return _Categoria;
}
const char* Articulo::getModelo()
{
    return _Modelo;
}
const char* Articulo::getTipoDeMaterial()
{
    return _TipoDeMaterial;
}
int Articulo::getCapacidad()
{
    return _Capacidad;
}
int Articulo::getDiametro()
{
    return _Diametro;
}
int Articulo::getStock()
{
    return _Stock;
}
bool Articulo::getEstado()
{
    return _Estado;
}

void Articulo::Cargar()
{
    rlutil::cls();
    ArticuloArchivo reg;
    int validar=0;
    cout << "Ingresar Categoria: ";
    cin >> _Categoria;
    do{
    cout << "Ingresar Modelo: ";
    cin >> _Modelo;
    }while(ValidarModelo(_Modelo)==true);
    cout << "Ingresar Tipo de Material: ";
    cin >> _TipoDeMaterial;
    cout << "Ingresar Capacidad: ";
    cin >> _Capacidad;
    cout << "Ingresar Diametro: ";
    cin >> _Diametro;
    cout << "Ingresar Stock: ";
    cin >> _Stock;
    _Estado = true;
}
void Articulo::Mostrar(int Aumentar)
{
    if(_Estado == true)
    {
         rlutil::locate(0,Aumentar);
         cout << "|";
         rlutil::locate(4,Aumentar);
         cout << _ID;
         rlutil::locate(10,Aumentar);
         cout << "|";
         rlutil::locate(13,Aumentar);
         cout << _Categoria;
         rlutil::locate(22,Aumentar);
         cout << "|";
         rlutil::locate(24,Aumentar);
         cout << _Modelo;
         rlutil::locate(31,Aumentar);
         cout << "|";
         rlutil::locate(33,Aumentar);
         cout << _TipoDeMaterial;
         rlutil::locate(42,Aumentar);
         cout << "|";
         rlutil::locate(44,Aumentar);
         cout << _Capacidad;
         rlutil::locate(54,Aumentar);
         cout << "|";
         rlutil::locate(56,Aumentar);
         cout << _Diametro;
         rlutil::locate(65,Aumentar);
         cout << "|";
         rlutil::locate(67,Aumentar);
         cout << _Stock;
         rlutil::locate(73,Aumentar);
         cout << "|" << endl;
    }
}

void Articulo::Mostrar2(int cant, int Aumentar)
{
    if(_Estado == true)
    {
        /*  rlutil::locate(2,Aumentar);
         cout << "|";
         rlutil::locate(4,Aumentar);
         cout << _ID;
         rlutil::locate(7,Aumentar);
         cout << "|";
         rlutil::locate(10,Aumentar);
         cout << _Categoria;
         rlutil::locate(19,Aumentar);
         cout << "|";
         rlutil::locate(22,Aumentar);
         cout << _Modelo;
         rlutil::locate(28,Aumentar);
         cout << "|";
         rlutil::locate(31,Aumentar);
         cout << _TipoDeMaterial;
         rlutil::locate(39,Aumentar);
         cout << "|";
         rlutil::locate(43,Aumentar);
         cout << _Capacidad;
         rlutil::locate(51,Aumentar);
         cout << "|";
         rlutil::locate(54,Aumentar);
         cout << _Diametro;
         rlutil::locate(62,Aumentar);
         cout << "|";
         rlutil::locate(65,Aumentar);
         cout << cant;
         rlutil::locate(72,Aumentar);
         cout << "|" << endl;*/

    }
}
void Articulo::MostrarBaja(int Aumentar)
{
    if(_Estado==false)
    {

        /*  rlutil::locate(2,Aumentar);
          cout << "|";
          rlutil::locate(4,Aumentar);
          cout << _Categoria;
          rlutil::locate(15,Aumentar);
          cout << "|";
          rlutil::locate(22,Aumentar);
          cout << _Modelo;
          rlutil::locate(28,Aumentar);
          cout << "|"<< endl;*/

           rlutil::locate(0,Aumentar);
         cout << "|";
         rlutil::locate(4,Aumentar);
         cout << _ID;
         rlutil::locate(10,Aumentar);
         cout << "|";
         rlutil::locate(13,Aumentar);
         cout << _Categoria;
         rlutil::locate(22,Aumentar);
         cout << "|";
         rlutil::locate(24,Aumentar);
         cout << _Modelo;
         rlutil::locate(31,Aumentar);
         cout << "|";
         rlutil::locate(33,Aumentar);
         cout << _TipoDeMaterial;
         rlutil::locate(42,Aumentar);
         cout << "|";
         rlutil::locate(44,Aumentar);
         cout << _Capacidad;
         rlutil::locate(54,Aumentar);
         cout << "|";
         rlutil::locate(56,Aumentar);
         cout << _Diametro;
         rlutil::locate(65,Aumentar);
         cout << "|";
         rlutil::locate(67,Aumentar);
         cout << _Stock;
         rlutil::locate(73,Aumentar);
         cout << "|" << endl;
    }



}
bool Articulo::modificar()
{
    int validar=1;
    do{
        cout << "Ingresar Stock: ";
        cin >> _Stock;
        if(_Stock>0){
            validar=0;
        }
        else{
            cout<<"La cantidad ingresada no puede ser negativa"<<endl;
        }
    }while(validar!=0);

}

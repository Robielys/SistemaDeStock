#include<iostream>
#include <string.h>
using namespace std;
#include "Articulo.h"
#include "ArticuloArchivo.h"

void Articulo::setID(int ID)
{
    _ID =ID;
}
void Articulo::setCategoria(string Categoria)
{
    strcpy(_Categoria, Categoria.c_str());
}
void Articulo::setModelo(string Modelo)
{
    strcpy(_Modelo, Modelo.c_str());
}
void Articulo::setTipoDeMaterial(string TipoDeMaterial)
{
    strcpy(_TipoDeMaterial, TipoDeMaterial.c_str());
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
    if(Stock > 0){
    _Stock += Stock;
    }
}
void Articulo::descontarStock(int stock){
    if(_Stock >= stock){
        _Stock -= stock;
    }else{
        cout << "Cantidad ingresada es mayor al stock disponible"<< endl;
        cout << "Ingrese una cantidad menor o igual al Stock disponible"<< endl;
        cout << "El stock disponible es: " << _Stock << endl;
    }
}
void Articulo::setEstado(bool Estado)
{
    _Estado = Estado;
}
int Articulo::getID()
{
    return _ID;
}
string Articulo::getCategoria()
{
    return _Categoria;
}
string Articulo::getModelo()
{
    return _Modelo;
}
string Articulo::getTipoDeMaterial()
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
    ArticuloArchivo reg;
    int validar=0;
    cout << "Ingresar Categoria: ";
    cin >> _Categoria;
    cout << "Ingresar Modelo: ";
    cin >> _Modelo;
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
       /* rlutil::locate(2,Aumentar);
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
        cout << _Stock;
        rlutil::locate(69,Aumentar);
        cout << "|" << endl;*/
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
void Articulo::Mostrar3(int Aumentar){
    if(_Estado==true){

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
    }
}
bool Articulo::modificar(){
    cout << "Ingresar Stock: ";
    cin >> _Stock;
}

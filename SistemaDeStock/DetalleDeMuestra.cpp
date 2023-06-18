#include "DetalleDeMuestra.h"
#include <string>
#include <cstring>
using namespace std;
#include <iostream>


void DetalleDeMuestra::setIDmuestra(int idmuestra)
{
    _IDmuestra= idmuestra;
}
void DetalleDeMuestra::setIDproducto(int idproducto)
{
    _IDproducto= idproducto;
}
void  DetalleDeMuestra::setCategoria( string categoria)
{
    strcpy(_Categoria, categoria.c_str());
}
void  DetalleDeMuestra::setModelo(string modelo)
{
    strcpy(_Modelo, modelo.c_str());
}
void  DetalleDeMuestra::setTipoDeMaterial(string tipoDematerial)
{
    strcpy(_TipoDeMaterial, tipoDematerial.c_str());
}
void DetalleDeMuestra::setCapacidad(int capacidad)
{
    _Capacidad= capacidad;
}
void DetalleDeMuestra::setDiametro(int diametro)
{
    _Diametro= diametro;
}
void DetalleDeMuestra::setStock(int stock)
{
    _Stock= stock;
}

int DetalleDeMuestra::getIDmuestra()
{
    return _IDmuestra;
}
int DetalleDeMuestra::getIDproducto()
{
    return _IDproducto;
}
string DetalleDeMuestra::getCategoria()
{
    return _Categoria;
}
string DetalleDeMuestra::getModelo()
{
    return _Modelo;
}
string DetalleDeMuestra::getTipoDeMaterial()
{
    return _TipoDeMaterial;
}

int DetalleDeMuestra::getCapacidad()
{
    return _Capacidad;
}
int DetalleDeMuestra::getDiametro()
{
    return _Diametro;
}
int DetalleDeMuestra::getStock()
{
    return _Stock;
}

void DetalleDeMuestra:: mostrar(){
cout<<"muestra";
}



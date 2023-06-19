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
void  DetalleDeMuestra::setCategoria(const char *categoria)
{
    strcpy(_Categoria,categoria);

}
void  DetalleDeMuestra::setModelo(const char *modelo)
{
    strcpy(_Modelo, modelo);
}
void  DetalleDeMuestra::setTipoDeMaterial(const char *tipoDematerial)
{
    strcpy(_TipoDeMaterial,tipoDematerial);
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
const char* DetalleDeMuestra::getCategoria()
{
    return _Categoria;
}
const char* DetalleDeMuestra::getModelo()
{
    return _Modelo;
}
const char* DetalleDeMuestra::getTipoDeMaterial()
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
cout<<endl;
cout<<_IDmuestra<< " "<<_IDproducto<<" "<<_Categoria<<" "<<_Modelo<<" "<<_Capacidad<<" "<< _TipoDeMaterial<<" "<<_Diametro<<" "<<_Stock;
cout<<endl;
cout<<endl;
}



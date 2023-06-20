#include "DetalleDeMuestra.h"
#include <string>
#include <cstring>
using namespace std;
#include <iostream>
#include "rlutil.h"


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

void DetalleDeMuestra:: mostrar(int Aumentar)
{
    rlutil::locate(1,Aumentar);
    cout << "|";
    rlutil::locate(3,Aumentar);
    cout << _IDproducto;
    rlutil::locate(16,Aumentar);
    cout << "|";
    rlutil::locate(18,Aumentar);
    cout << _Categoria;
    rlutil::locate(28,Aumentar);
    cout << "|";
    rlutil::locate(30,Aumentar);
    cout << _Modelo;
    rlutil::locate(37,Aumentar);
    cout << "|";
    rlutil::locate(39,Aumentar);
    cout << _TipoDeMaterial;
    rlutil::locate(48,Aumentar);
    cout << "|";
    rlutil::locate(50,Aumentar);
    cout << _Capacidad<<" ml";
    rlutil::locate(60,Aumentar);
    cout << "|";
    rlutil::locate(62,Aumentar);
    cout << _Diametro<<" cm";
    rlutil::locate(71,Aumentar);
    cout << "|";
    rlutil::locate(73,Aumentar);
    cout << _Stock;
    rlutil::locate(79,Aumentar);
    cout << "|" << endl;
}



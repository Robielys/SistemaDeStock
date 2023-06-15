#include <string>
#include <iostream>
using namespace std;
#include "ArticuloMenu.h"
#include "ArticuloArchivo.h"
#include "Articulo.h"


void ArticuloMenu::Mostrar()
{
    int Opcion;
    do
    {
        cout<< "-----------" << " Menu de articulos " << "-----------" << endl;
        cout<< " 1.Lista de todos los articulos" << endl;
        cout<< " 2.Cargar nuevo articulo" << endl;
        cout<< " 3.Dar de baja un articulo" << endl;
        cout<< " 4.Modificar un articulo" << endl;
        cout<< "-----------------------------------------" << endl;
        cout<< " 0. Volver al menu principal" << endl;
        cout<< endl;
        cout<< " Ingresar el Numero de la Opcion: ";
        cin>>Opcion;

        switch(Opcion)
        {

        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        }
    }
    while(Opcion!=0);
}

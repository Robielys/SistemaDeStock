#include <string>
#include <iostream>
using namespace std;
#include "ArticuloMenu.h"
#include "ArticuloArchivo.h"
#include "Articulo.h"

void ArticuloMenu::Listar()
{
    ArticuloArchivo archivo;
    int cantidad = archivo.getCantidad();
    Articulo* Art= new Articulo[cantidad];

    archivo.Listar(Art, cantidad);

    int Aumentar = 4;
    for(int i=0; i<cantidad; i++)
    {
        Art[i].Mostrar(Aumentar);
        Aumentar++;
    }
    delete[] Art;

    system("pause");
}
void ArticuloMenu::guardar()
{
    Articulo Art;
    ArticuloArchivo CarArt;
    Art.Cargar();
    if(CarArt.guardar(Art))
    {
        cout << "Articulo guardado sastifactoriamente" << endl;
    }
    else
    {
        cout << "No se pudo guardar el articulo" << endl;
    }

    system("pause");
}

void ArticuloMenu::baja()
{
    ArticuloArchivo CarArt;
    Articulo Art;
    int ID, posicion;
    cout << "Ingresar ID del articulo que desea dar de baja: ";
    cin >> ID;

    posicion =CarArt.buscar(ID);

    if(posicion != -1)
    {
        cout << "Si existe" << endl;
        Art=CarArt.BuscarArt(posicion);
        Art.Mostrar(4);
        Art.setEstado(false);
        if(CarArt.guardarModificacion(Art, posicion))
        {
            cout<< "Se dio de baja correctamente" <<endl;
        }
        else
        {
            cout << "Ocurrio un error inesperado y no se pudo dar de baja" << endl;
        }
    }
    system("pause");
}

void ArticuloMenu::editar()
{
    ArticuloArchivo CarArt;
    Articulo Art;
    int ID, posicion, can, opcion;
    cout << " ¿Que accion desea realizar?"<< endl;
    cout << " 1.Aumentar Stock"<< endl;
    cout << " 2.Disminuir Stock" << endl;
    cin >> opcion;
    if (opcion == 1)
    {

        cout << "Ingresar ID que desea Modificar: ";
        cin >> ID;

        posicion =CarArt.buscar(ID);

        if(posicion != -1)
        {
            cout << "Si existe" << endl;

            Art=CarArt.BuscarArt(posicion);
            Art.Mostrar(4);
            cout << "Cantidad a ingresar: ";
            cin >> can;
            Art.setStock(can);
            if(CarArt.guardarModificacion(Art, posicion))
            {
                cout<< "Se modifico correctamente" <<endl;
            }
            else
            {
                cout << "No se pudo guardar" << endl;

            }
        }
        else
        {
            cout << "No existe ID";
        }
    }
    else
    {
        if (opcion == 2)
        {

            cout << "Ingresar ID que desea Modificar: ";
            cin >> ID;

            posicion =CarArt.buscar(ID);

            if(posicion != -1)
            {
                cout << "Si existe" << endl;

                Art=CarArt.BuscarArt(posicion);
                Art.Mostrar(4);
                cout << "Cantidad a ingresar: ";
                cin >> can;
                Art.descontarStock(can);
                if(CarArt.guardarModificacion(Art, posicion))
                {
                    cout<< "Se modifico correctamente" <<endl;
                }
                else
                {
                    cout << "No se pudo guardar" << endl;

                }
            }
            else
            {
                cout << "No existe ID";
            }
        }
        else
        {

        }
    }
    system("pause");

}

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

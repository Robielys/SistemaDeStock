#include <string>
#include <iostream>
using namespace std;
#include "ArticuloMenu.h"
#include "ArticuloArchivo.h"
#include "Articulo.h"
#include "Funciones.h"
#include "rlutil.h"

void ArticuloMenu::Listar()
{
    ArticuloArchivo archivo;
    int cantidad = archivo.getCantidad();
    Articulo* Art= new Articulo[cantidad];

    archivo.Listar(Art, cantidad);

    int Aumentar = 7;
    rlutil::cls();
    TituloArticulos();
    EncabezadoDeArticulos();
    for(int i=0; i<cantidad; i++)
    {
        if(Art[i].getEstado()){
        Art[i].Mostrar(Aumentar);
        Aumentar++;
        }
    }
    cout<<"-------------------------------------------------------------------------"<<endl;
    delete[] Art;

    system("pause");
}
void ArticuloMenu::guardar()
{
    int Numero;
    do
    {
        Articulo Art,articulo;
        ArticuloArchivo CarArt;
        Art.Cargar();
        if(CarArt.guardar(Art))
        {
        int cantidad=CarArt.getCantidad();
        for(int x=0; x<cantidad; x++)
        {
            articulo=CarArt.BuscarArt(x);
            if(articulo.getID()==Art.getID()){

            rlutil::cls();
            TituloArticuloNuevo();
            EncabezadoDeArticulos();
            Art.Mostrar(7);
            }
        }
            cout << "Articulo guardado sastifactoriamente" << endl;
        }
        else
        {
            cout << "No se pudo guardar el articulo" << endl;
        }
        cout<<endl;
        cout<< "SI DESEA TERMINAR LA CARGA INGRESE 0: ";
        cin>> Numero;


    }
    while(Numero!=0);

}

void ArticuloMenu::baja()
{
    rlutil::cls();
    ArticuloArchivo CarArt;
    Articulo Art;
    int ID, posicion;
    cout << "Ingresar ID del articulo que desea dar de baja: ";
    cin >> ID;

    posicion =CarArt.buscar(ID);

    if(posicion != -1)
    {
        ///cout << "Si existe" << endl;
        Art=CarArt.BuscarArt(posicion);
        Art.Mostrar(4);
        Art.setEstado(false);
        if(CarArt.guardarModificacion(Art, posicion))
        {
            rlutil::cls();
            EncabezadoDeArticulos();
            Art.MostrarBaja(4);
            cout<<endl;
            cout<< "Se dio de baja este articulo correctamente" <<endl;
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
    rlutil::cls();
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
            rlutil::cls();
            Art=CarArt.BuscarArt(posicion);
            TituloArticulos();
            EncabezadoDeArticulos();
            Art.Mostrar(7);
            cout << "Cantidad a ingresar: ";
            cin >> can;
            Art.setStock(can);
            if(CarArt.guardarModificacion(Art, posicion))
            {
                rlutil::cls();
                EncabezadoDeArticulos();
                Art.Mostrar(4);
                cout<< "Se modifico correctamente" <<endl;
            }
            else
            {
                cout << "No se pudo guardar modificacion" << endl;

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
            rlutil::cls();
            cout << "Ingresar ID que desea Modificar: ";
            cin >> ID;

            posicion =CarArt.buscar(ID);

            if(posicion != -1)
            {
                rlutil::cls();
                Art=CarArt.BuscarArt(posicion);
                EncabezadoDeArticulos();
                Art.Mostrar(4);
                cout << "Cantidad a ingresar: ";
                cin >> can;
                Art.descontarStock(can);
                if(CarArt.guardarModificacion(Art, posicion))
                {
                    rlutil::cls();
                    EncabezadoDeArticulos();
                    Art.Mostrar(4);
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

void ArticuloMenu::ConsultaStock()
{
    Articulo articulo;
    ArticuloArchivo archivo;
    int cantidadArticulos = archivo.getCantidad();

    int Cantidad=0,aumentar=4,opcion;
    do{
    rlutil::cls();
    cout<<"¿Como desea filtrar?"<<endl;
    cout<<"1.Categoria"<<endl;
    cout<<"2.Stock"<<endl;
    cin>>opcion;
    }while(ValidarOpcionMenuPrincipal(3,opcion)==false);
    if(opcion==1){

        BuscarCategoria();
    }
    if(opcion==2){
    cout<< "Ingrese hasta que cantidad de Stock desea filtrar: ";
    cin>>Cantidad;
    rlutil::cls();
    EncabezadoDeArticulos();
    int validacion=0;
    for(int i=0; i<cantidadArticulos; i++)
    {
        articulo = archivo.BuscarArt(i);

        if(articulo.getStock()<=Cantidad&& articulo.getEstado())
        {
            articulo.Mostrar(aumentar);
            aumentar++;
        }

    }
    cout<<"-------------------------------------------------------------------------"<<endl;
}
system("pause");
}

void ArticuloMenu::Mostrar()
{
    int Opcion;
    do
    {
        rlutil::cls();
        cout<< "-----------" << " Menu de articulos " << "-----------" << endl;
        cout<< " 1.Lista de todos los articulos" << endl;
        cout<< " 2.Cargar nuevo articulo" << endl;
        cout<< " 3.Dar de baja un articulo" << endl;
        cout<< " 4.Modificar un articulo" << endl;
        cout<< " 5.Consulta de Stock" << endl;
        cout<< "-----------------------------------------" << endl;
        cout<< " 0. Volver al menu principal" << endl;
        cout<< endl;
        cout<< " Ingresar el Numero de la Opcion: ";
        cin>>Opcion;
        if(ValidarOpcionMenuPrincipal(6,Opcion))
        {
            switch(Opcion)
            {

            case 1:
                Listar();
                break;
            case 2:
                guardar();
                break;
            case 3:
                baja();
                break;
            case 4:
                editar();
                break;
            case 5:
                ConsultaStock();
                break;
            }
        }
    }
    while(Opcion!=0);
}

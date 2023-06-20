#include <string>
#include <iostream>
using namespace std;
#include "Muestra.h"
#include "DetalleDeMuestra.h"
#include "MuestraArchivo.h"
#include "DetalleDeMuestraArchivo.h"
#include "MuestraMenu.h"
#include "Articulo.h"
#include "ArticuloArchivo.h"
#include "Cliente.h"
#include "ClienteArchivo.h"
#include "Fecha.h"
#include "Funciones.h"
#include "rlutil.h"

void MuestraMenu::Listar()
{
    MuestraArchivo archivo;
    int cantidad = archivo.getCantidad();
    Muestra* muestra = new Muestra[cantidad];
    archivo.listar(muestra, cantidad);
    rlutil::cls();
    EncabezadoDeMuestras();
    int aumentar= 4;
    for(int x=0; x<cantidad; x++)
    {
        muestra[x].mostrar(aumentar);
        aumentar++;
    }
    cout<<"---------------------------------------------------------"<<endl;
    delete [] muestra;
    system("pause");
}
void MuestraMenu::guardar()
{
    rlutil::cls();
    Fecha fecha;
    Muestra muestra;
    MuestraArchivo archivomuest;
    Cliente cliente;
    ClienteArchivo archivocli;
    Articulo articulo;
    ArticuloArchivo archivoarticulo;
    DetalleDeMuestra detalleM;
    DetalleDeMuestraArchivo archivodetalle;
    int numCliente=0;
    int numMuestra=0;
    cout<<"Ingrese numero de cliente : "<< endl;
    cin>>numCliente;
    int posicion2=0;
    posicion2=archivocli.buscar(numCliente);
    cliente=archivocli.BuscarCliente(posicion2);
    muestra.setNombreCliente(cliente.getNombreEmpresa());
    muestra.setFecha(fecha);
    muestra.setIDcliente(cliente.getID());
    archivomuest.guardar(muestra);
    rlutil::cls();
    EncabezadoDeMuestras2(archivomuest.getCantidad(),cliente);
    EncabezadoDetallesM();
    int codigoArticulo, limite=0, aumentar=12;

    for(int x=0; x<10; x++)
    {
        int posicion=0;
        int cantidad=0;

        rlutil::locate(1,26);
        cout<<"Ingresar codigo de articulo: ";
        cin>>codigoArticulo;
        if(codigoArticulo>0)
        {
            detalleM.setIDmuestra(archivomuest.getCantidad());
            posicion=archivoarticulo.buscar(codigoArticulo);
            articulo=archivoarticulo.BuscarArt(posicion);
            detalleM.setCategoria(articulo.getCategoria());
            detalleM.setModelo(articulo.getModelo());
            detalleM.setCapacidad(articulo.getCapacidad());
            detalleM.setDiametro(articulo.getDiametro());
            detalleM.setIDproducto(articulo.getID());
            detalleM.setTipoDeMaterial(articulo.getTipoDeMaterial());
            rlutil::locate(34,26);
            cout<<"|  Ingresar la cantidad: ";
            cin>>cantidad;
            articulo.descontarStock(cantidad);
            detalleM.setStock(cantidad);
            archivodetalle.Guardar(detalleM);
            detalleM.mostrar(aumentar);
            aumentar++;
            limite++;
        }

        if(limite>=10 || codigoArticulo==0)
        {
            x=10;
        }
    }
        cout<<"----------------------------------------------------------------------------------------"<<endl;
    if(limite ==10)
    {
        cout<<endl;
        cout<< "SE ALCANZO LIMITE DE MUESTRAS PARA CLIENTE"<<endl;
        system("pause");
    }

}
void MuestraMenu::ListarDetalle()
{
    MostrarMuestras();
    Muestra muestra;
    MuestraArchivo archivoMuestra;
    Cliente cliente;
    ClienteArchivo archivocli;
    DetalleDeMuestraArchivo archivoDetalle;
    int CantidadMuestraDetalle= archivoDetalle.CantidadRegistros();
    int Numero;
    cout << "¿Cual numero de muestra desea ver?";
    cin >> Numero;
    int posicion2= archivoMuestra.buscar(Numero);
    muestra=archivoMuestra.BuscarMuestra(posicion2);
    int posicion=archivocli.buscar(muestra.getIDcliente());
    cliente=archivocli.BuscarCliente(posicion);
    rlutil::cls();
    EncabezadoDeMuestras3(Numero,muestra,cliente);
    EncabezadoDetallesM();
    int aumentar=12;
    for(int x=0; x<CantidadMuestraDetalle; x++)
    {
        DetalleDeMuestra obj=archivoDetalle.Leer(x);

        if(obj.getIDmuestra()==Numero)
        {
            obj.mostrar(aumentar);
            aumentar++;
        }
    }
     cout << "-------------------------------------------------------------------------------"<< endl;
    system("pause");

}
void MuestraMenu::Mostrar()
{
    int opcion;
    do
    {
        rlutil::cls();
        cout<< "-----------" << " Menu de Muestras " << "-----------" << endl;
        cout<< " 1.Lista de pedidos de muestras" << endl;
        cout<< " 2.Cargar nueva muestra" << endl;
        cout<< " 3.Buscar detalle de muestra" << endl;
        cout<< "----------------------------------------" << endl;
        cout<< " 0.Volver al menu principal" << endl;
        cout<< endl;
        cout<< " Ingresar el Numero de la Opcion: ";
        cin>> opcion;

        switch(opcion)
        {
        case 1:
            Listar();
            break;
        case 2:
        {
            guardar();
        }
        break;
        case 3:
        {
            ListarDetalle();
        }
        break;
        }
    }
    while(opcion!=0);

}


#include<iostream>
using namespace std;
#include "Funciones.h"
#include "Articulo.h"
#include "ArticuloArchivo.h"
#include "Cliente.h"
#include "ClienteArchivo.h"
#include "Fecha.h"
#include "Muestra.h"
#include "MuestraArchivo.h"
#include "rlutil.h"
void BuscarTipoCategoria(const char *Tipo){
    int aumentar=4;
    Articulo articulo;
    ArticuloArchivo archivo;
    int cantidadArticulos = archivo.getCantidad();

    rlutil::cls();
    EncabezadoDeArticulos();
    int validacion=0;
    for(int i=0; i<cantidadArticulos; i++)
    {
        articulo = archivo.BuscarArt(i);

        if(strcmp(articulo.getCategoria(),Tipo)==0&& articulo.getEstado())
        {
            articulo.Mostrar(aumentar);
            aumentar++;
        }

    }
    cout<<"-------------------------------------------------------------------------"<<endl;

}

void BuscarCategoria()
{
    int tipoCategoria;
    do
    {
        cout<< "1.Tapa"<<endl;
        cout<< "2.Envase"<<endl;
        cout<< "3.Gatillo"<<endl;
        cout<< "4.Valvula"<<endl;
        cout<< "5.Gotero"<<endl;
        cout<< "6.Cremera"<<endl;
        cout<< "7.Pote"<<endl;
        cout<< "Que categoria quiere ver: ";
        cin>>tipoCategoria;
    }
    while(ValidarOpcionMenuPrincipal(8,tipoCategoria)==false);
    switch(tipoCategoria)
    {
    case 1:
        BuscarTipoCategoria("Tapa");
        break;
    case 2:
        BuscarTipoCategoria("Envase");
        break;
    case 3:
        BuscarTipoCategoria("Gatillo");
        break;
    case 4:
        BuscarTipoCategoria("Valvula");
        break;
    case 5:
        BuscarTipoCategoria("Gotero");
        break;
    case 6:
        BuscarTipoCategoria("Cremera");
        break;
    case 7:
        BuscarTipoCategoria("Pote");
        break;
    }

}
void MostrarRanking(int *vecArticulo,int *vecTotal, int cantidad)
{
    int cantidadTotal=0;
    cout<<"**************************************************************"<<endl;
    cout<<"       Consulta de cantidad de articulos entregados           "<<endl;
    cout<<"=============================================================="<<endl;

    for(int i=0; i<cantidad; i++)
    {
        cout<<"Numero de Articulo: " <<vecArticulo[i] <<" "<< "Cantidad de muestras entregadas: "<<vecTotal[i]<<endl;
        cantidadTotal+=vecTotal[i];
    }
    cout<<endl;
    cout<<"Cantidad total de articulos entregados al dia de hoy : "<< cantidadTotal<<endl;

}
void MostrarMuestras()
{
    MuestraArchivo archivoMuestra;
    int CantidadMuestra= archivoMuestra.getCantidad();
    Muestra *muestra = new Muestra[CantidadMuestra];
    archivoMuestra.listar(muestra,CantidadMuestra);
    int aumentar=7;
    rlutil::cls();
    TituloDeMuestras();
    EncabezadoDeMuestras();
    for(int i=0; i<CantidadMuestra; i++)
    {
        muestra[i].mostrar(aumentar);
        aumentar++;
    }
    delete[] muestra;

}
bool ValidarCuit(long long cuit)
{
    if (cuit>9999999999 && cuit<100000000000)
    {
        Cliente cliente;
        ClienteArchivo archivoC;
        int cantidad= archivoC.getCantidad();
        for(int i=0; i<cantidad; i++)
        {
            cliente=archivoC.BuscarCliente(i);
            if(cliente.getCuit()== cuit)
            {
                cout<<"Este CUIT ya existe"<< endl;
                return false;
            }

        }
        return true;

    }
    else
    {
        cout<<"Ingrese un CUIT valido"<<endl;
        return false;
    }
}

bool ValidarModelo( const char *modelo)
{
    Articulo articulo;
    ArticuloArchivo archivoA;
    int cantidad= archivoA.getCantidad();
    for(int x =0; x<cantidad; x++)
    {
        articulo=archivoA.BuscarArt(x);
        if(articulo.getModelo()== modelo)
        {
            cout<<"Este modelo ya existe";
            cout<<endl;
            return true;
        }
    }
    return false;
}

bool ValidarOpcionMenuPrincipal(int menu,int opcion)
{
    int x=0;
    for(x=0; x<menu; x++)
    {
        if(opcion<=menu-1&&opcion>=0)
        {
            return true;
        }
    }
    cout<<"Ingrese una opcion valida de menu"<<endl;
    system("pause");
    return false;
}

bool ValidarArticulo(int codigoArticulo)
{
    Articulo articulo;
    ArticuloArchivo archivo;
    int cantidad= archivo.getCantidad();
    for(int x=0; x<cantidad; x++)
    {
        articulo=archivo.BuscarArt(x);
        if(articulo.getID()==codigoArticulo&&articulo.getEstado())
        {
            return true;
        }
    }
    cout<<"Codigo de articulo no existe"<< endl;
    return false;

}

bool ValidarCantidad(int cantidad)
{
    if(cantidad<=6)
    {
        return true;
    }
    else
    {
        cout<<"El maximo permitido por productos es de 6 unidades"<<endl;
        return false;
    }
}

void EncabezadoDeArticulos()
{
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"| Codigo | Categoria | Modelo | Material | Capacidad | Diametro | Stock |"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;

}

void EncabezadoDeClientes()
{
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"| Codigo |    CUIT   |   Nombre empresa   |           Correo            |"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;

}

void TituloDeMuestras()
{
    cout<<"*********************************************************"<<endl;
    cout<<"               Lista de pedidos de muestras              "<<endl;
    cout<<"========================================================="<<endl;
}
void EncabezadoDeMuestras()
{

    cout<<"---------------------------------------------------------"<<endl;
    cout<<"| Codigo |      Nombre empresa        |      Fecha      |"<<endl;
    cout<<"---------------------------------------------------------"<<endl;


}
void TituloPedidos()
{
    cout<<"*******************************************************************************"<<endl;
    cout<<"                          Solicitud de muestras                                "<<endl;
    cout<<"==============================================================================="<<endl;
}
void TituloDetalles()
{
    cout<<"*******************************************************************************"<<endl;
    cout<<"                         Detalle de muestras                                   "<<endl;
    cout<<"==============================================================================="<<endl;
}

void EncabezadoDetallesM()
{
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<"| Cod.Producto | Categoria | Modelo | Material | Capacidad | Diametro | Stock |"<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;

}

void EncabezadoDeMuestras2(int Numero, Cliente cliente)
{
    Fecha feHoy;
    cout << " Detalle  de muestra" <<"                  " << "    Fecha de pedido: " << feHoy.toString() << endl;
    cout << endl;
    cout << " Codigo Muestra: " << Numero << endl;
    cout <<endl;
    cout << " Datos del cliente: " << endl;
    ///cout << "-------------------------------------------------------------------------------"<< endl;
    cout << " CUIT: " << cliente.getCuit() <<"   "<<"Empresa: " << cliente.getNombreEmpresa() << "   " << "Correo: " << cliente.getCorreo()<<endl;
    cout << "-------------------------------------------------------------------------------"<< endl;
}
void EncabezadoDeMuestras3(int Numero, Muestra muestra, Cliente cliente)
{
    Fecha feHoy;
    cout << " Pedido de muestra" <<"                  " << "    Fecha de pedido: " << muestra.getFecha().toString() << endl;
    cout << endl;
    cout << " Codigo Muestra: " << Numero << endl;
    cout <<endl;
    cout << " Datos del cliente: " << endl;
    cout << "-------------------------------------------------------------------------------"<< endl;
    cout << " CUIT: " << cliente.getCuit() <<"   "<<"Empresa: " << cliente.getNombreEmpresa() << "   " << "Correo: " << cliente.getCorreo()<<endl;
    cout << "-------------------------------------------------------------------------------"<< endl;
}

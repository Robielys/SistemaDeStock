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
void MostrarMuestras()
{
    MuestraArchivo archivoMuestra;
    int CantidadMuestra= archivoMuestra.getCantidad();
    Muestra *muestra = new Muestra[CantidadMuestra];
    archivoMuestra.listar(muestra,CantidadMuestra);
    int aumentar=4;
    rlutil::cls();
    EncabezadoDeMuestras();
    for(int i=0; i<CantidadMuestra; i++)
    {
        muestra[i].mostrar(aumentar);
        aumentar++;
    }
    delete[] muestra;

}
bool ValidarCuit(int cuit)
{
    if (cuit <0)
    {
        cout<<"Cuit invalido";
        cout<<endl;
        return true;
    }
    Cliente cliente;
    ClienteArchivo archivoC;
    int cantidad= archivoC.getCantidad();
    for(int i=0; i<cantidad; i++)
    {
        cliente=archivoC.BuscarCliente(i);
        if(cliente.getCuit()== cuit)
        {
            cout<<"Este CUIT ya existe"<< endl;
            return true;
        }
    }
    return false;
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

void EncabezadoDeMuestras()
{
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"| Codigo |      Nombre empresa        |      Fecha      |"<<endl;
    cout<<"---------------------------------------------------------"<<endl;


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
    cout << " Pedido de muestra" <<"                  " << "    Fecha de pedido: " << feHoy.toString() << endl;
    cout << endl;
    cout << " Codigo Muestra: " << Numero << endl;
    cout <<endl;
    cout << " Datos del cliente: " << endl;
    cout << "-------------------------------------------------------------------------------"<< endl;
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

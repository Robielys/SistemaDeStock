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
    else{
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

bool ValidarArticulo(int codigoArticulo){
Articulo articulo;
ArticuloArchivo archivo;
int cantidad= archivo.getCantidad();
for(int x=0;x<cantidad;x++){
    articulo=archivo.BuscarArt(x);
    if(articulo.getID()==codigoArticulo){
        return true;
    }
}
cout<<"Codigo de articulo no existe"<< endl;
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

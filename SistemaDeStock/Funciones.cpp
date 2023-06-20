#include<iostream>
using namespace std;
#include "Funciones.h"
#include "Articulo.h"
#include "ArticuloArchivo.h"
#include "Cliente.h"
#include "ClienteArchivo.h"


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
    for(int i=0; i<cantidad; i++){
        cliente=archivoC.BuscarCliente(i);
        if(cliente.getCuit()== cuit){
            cout<<"Este CUIT ya existe"<< endl;
            return true;
        }
    }
    return false;
}

bool ValidarModelo( const char *modelo){
Articulo articulo;
ArticuloArchivo archivoA;
int cantidad= archivoA.getCantidad();
for(int x =0; x<cantidad;x++){
    articulo=archivoA.BuscarArt(x);
    if(articulo.getModelo()== modelo){
        cout<<"Este modelo ya existe";
        cout<<endl;
        return true;
    }
}
return false;
}

void EncabezadoDeArticulos(){
cout<<"-------------------------------------------------------------------------"<<endl;
cout<<"| Codigo | Categoria | Modelo | Material | Capacidad | Diametro | Stock |"<<endl;
cout<<"-------------------------------------------------------------------------"<<endl;

}

void EncabezadoDeClientes(){
cout<<"-------------------------------------------------------------------------"<<endl;
cout<<"| Codigo |    CUIT   |   Nombre empresa   |           Correo            |"<<endl;
cout<<"-------------------------------------------------------------------------"<<endl;

}

void EncabezadoDeMuestras(){
cout<<"---------------------------------------------------------"<<endl;
cout<<"| Codigo |      Nombre empresa        |      Fecha      |"<<endl;
cout<<"---------------------------------------------------------"<<endl;


}
void EncabezadoDetallesM(){
cout<<"----------------------------------------------------------------------------------------"<<endl;
cout<<"| Codigo | Cod.Producto | Categoria | Modelo | Material | Capacidad | Diametro | Stock |"<<endl;
cout<<"----------------------------------------------------------------------------------------"<<endl;

}

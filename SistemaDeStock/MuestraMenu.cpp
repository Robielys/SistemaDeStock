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

void MuestraMenu::Listar(){
    MuestraArchivo archivo;
    int cantidad = archivo.getCantidad();
    Muestra* muestra = new Muestra[cantidad];
    archivo.listar(muestra, cantidad);
    /*int aumentar= 4;*/
    for(int x=0; x<cantidad; x++){

        muestra[x].mostrar();
    }
    delete [] muestra;
    system("pause");
}
void MuestraMenu::guardar(){
    Fecha fecha;
    Muestra muestra;
    MuestraArchivo archivomuest;
    Cliente cliente;
    ClienteArchivo archivocli;
    Articulo articulo;
    ArticuloArchivo archivoarticulo;
    int numCliente=0;
    int numMuestra=0;
    cout<<"Ingrese numero de cliente : "<< endl;
    cin>>numCliente;
    cliente=archivocli.BuscarCliente(numCliente);
    muestra.setNombreCliente(cliente.getNombreEmpresa());
    muestra.setFecha(fecha);
    archivomuest.guardar(muestra);


    int codigoArticulo;
do{
        int cantidad=0;
    cout<<"Ingresar codigo de articulo: "<<endl;
    cin>>codigoArticulo;
    DetalleDeMuestra detalleM;
    DetalleDeMuestraArchivo archivodetalle;
    detalleM.setIDmuestra(muestra.getID());
    articulo=archivoarticulo.BuscarArt(codigoArticulo);
    detalleM.setCategoria(articulo.getCategoria());
    detalleM.setModelo(articulo.getModelo());
    detalleM.setCapacidad(articulo.getCapacidad());
    detalleM.setDiametro(articulo.getDiametro());
    detalleM.setIDproducto(articulo.getID());
    detalleM.setTipoDeMaterial(articulo.getTipoDeMaterial());
    cout<<"Ingresar la cantidad: "<<endl;
    cin>>cantidad;
    detalleM.setStock(articulo.descontarStock(cantidad));
    archivodetalle.Guardar(detalleM);
    detalleM.mostrar();

}while( codigoArticulo!=0);



}
void MuestraMenu::ListarDetalle(){
    DetalleDeMuestraArchivo archivoDetalle;
    MuestraArchivo archivoMuestra;
    int CantidadMuestraDetalle= archivoDetalle.CantidadRegistros();
    int CantidadMuestra= archivoMuestra.getCantidad();
    Muestra *muestra = new Muestra[CantidadMuestra];
    archivoMuestra.listar(muestra,CantidadMuestra);

    for(int i=0; i<CantidadMuestra; i++){
        muestra[i].mostrar();
    }
    int Numero;
    cout << "¿Cual numero de muestra desea ver?";
    cin >> Numero;
    for(int x=0;x<CantidadMuestraDetalle; x++){
        DetalleDeMuestra obj=archivoDetalle.Leer(x);
        if(obj.getIDmuestra()==Numero){
            obj.mostrar();

        }
    }
}
void MuestraMenu::Mostrar()
{
    int opcion;
    do
    {
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
    }while(opcion!=0);

}


#include <string>
#include <iostream>
using namespace std;
#include "Muestra.h"
#include "DetalleDeMuestra.h"
#include "MuestraArchivo.h"
#include "DetalleDeMuestraArchivo.h"
#include "MuestraMenu.h"

void MuestraMenu::Listar(){
}
void MuestraMenu::guardar(){
}
void MuestraMenu::ListarDetalle(){
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
            break;
        case 2:
            break;
        case 3:
            break;
        }
    }while(opcion!=0);

}

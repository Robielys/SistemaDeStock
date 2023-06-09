#include<iostream>
using namespace std;

#include "ProgramaPrincipal.h"

void ProgramaPrincipal::Ejecutar()
{
    int opcion;
    do
    {
        cout<< "-----------" << " Menu Principal " << "-----------" << endl;
        cout<< " 1.Solicitud de Muestras" << endl;
        cout<< " 2.Clientes" << endl;
        cout<< " 3.Articulos" << endl;
        cout<< "--------------------------------------" << endl;
        cout<< " 0. Salir" << endl;
        cout<< endl;
        cout<< " Ingresar el Numero de la Opcion: ";
        cin>> opcion;

        switch(opcion)
        {
        case 1:

            break;
        case 2:
            MenuCliente.mostrar();
            break;
        case 3:
            break;
        case 0:
            cout<<endl;
            cout<<"Gracias por usar nuestro Programa :)" <<endl;
            break;
        }
    }
    while(opcion !=0);
}

#include <string>
#include <iostream>
using namespace std;
#include "ClienteMenu.h"
#include "ClienteArchivo.h"
#include "Cliente.h"
#include "rlutil.h"
#include "Funciones.h"


void ClienteMenu::Listar()
{
    int aumentar=4;
    ClienteArchivo archivo;
    int cantidad = archivo.getCantidad();
    Cliente *cliente= new Cliente[cantidad];
    archivo.listar(cliente, cantidad);
    rlutil::cls();
    EncabezadoDeClientes();
    for(int i=0; i<cantidad; i++)
    {
        cliente[i].Mostrar(aumentar);
        aumentar++;
    }
    cout<<"-------------------------------------------------------------------------"<<endl;
    delete[] cliente;

    system("pause");
}


void ClienteMenu::guardar()
{
    rlutil::cls();
    Cliente cliente, cliente2;
    ClienteArchivo archivo;
    cliente.Cargar();
    if(archivo.guardar(cliente))
    {
        int cantidad=archivo.getCantidad();
        for(int x=0; x<cantidad;x++){
            cliente2=archivo.BuscarCliente(x);
            if(cliente2.getCuit()==cliente.getCuit()){
        rlutil::cls();
        EncabezadoDeClientes();
        cliente2.Mostrar(4);

            }
        }

        cout<<endl;
        cout << "Cliente guardado satisfactoriamente" << endl;
    }
    else
    {
        cout << "No se pudo guardar el cliente" << endl;
    }
    system("pause");
}


void ClienteMenu::baja()
{
    rlutil::cls();
    Cliente cliente;
    ClienteArchivo archivo;
    int ID, posicion;
    cout << "Ingresar ID que desea dar de baja: ";
    cin >> ID;

    posicion =archivo.buscar(ID);

    if(posicion != -1)
    {

        cliente=archivo.BuscarCliente(posicion);
        rlutil::cls();
        EncabezadoDeClientes();
        cliente.Mostrar(4);
        cliente.setEstado(false);
        if(archivo.guardarModificacion(cliente, posicion))
        {
            rlutil::cls();
            EncabezadoDeClientes();
            cliente.MostrarBaja(4);
            cout<<endl;
            cout<< "Este cliente se dio de baja correctamente" <<endl;
        }
        else
        {
            cout << "No se pudo dar de baja este cliente" << endl;

        }
    }
    else
    {
        cout << "No existe ID";
    }

    system("pause");
}


void ClienteMenu::editar()
{
    rlutil::cls();
    Cliente cliente;
    ClienteArchivo archivo;
    int ID, posicion, opcion;
    string  can;
    cout << " ¿Que accion desea realizar?"<< endl;
    cout << " 1.Modificar Correo?"<< endl;
    cout << " 2.Modificar Nombre Empresa?" << endl;
    cin >> opcion;
    if (opcion == 1)
    {
        cout << "Ingresar ID que desea Modificar: ";
        cin >> ID;

        posicion =archivo.buscar(ID);

        if(posicion != -1)
        {

            cliente=archivo.BuscarCliente(posicion);
            rlutil::cls();
            EncabezadoDeClientes();
            cliente.Mostrar(4);
            cout << "Ingresar el Correo: ";
            cin >> can;
            cliente.setCorreo(can);
            if(archivo.guardarModificacion(cliente, posicion))
            {
                rlutil::cls();
                EncabezadoDeClientes();
                cliente.Mostrar(4);
                cout<< "Se modifico correctamente" <<endl;
            }
            else
            {
                cout << "No se pudieron guardar los cambios" << endl;

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

            posicion =archivo.buscar(ID);

            if(posicion != -1)
            {

                cliente=archivo.BuscarCliente(posicion);
                rlutil::cls();
                EncabezadoDeClientes();
                cliente.Mostrar(4);
                cout << "Ingrese el Nombre de la empresa: ";
                cin >> can;
                cliente.setNombreEmpresa(can);
                if(archivo.guardarModificacion(cliente, posicion))
                {
                    rlutil::cls();
                    EncabezadoDeClientes();
                    cliente.Mostrar(4);
                    cout<< "Se modifico correctamente" <<endl;
                }
                else
                {
                    cout << "No se pudieron guardar los cambios" << endl;

                }
            }
            else
            {
                cout << "No existe ID";
            }
        }
    }

    system("pause");
}
void ClienteMenu::mostrar()
{
    int opcion;
    do
    {
        rlutil::cls();
        cout<< "-----------" << " Menu de clientes " << "-----------" << endl;
        cout<< " 1.Lista de clientes" << endl;
        cout<< " 2.Cargar nuevo cliente" << endl;
        cout<< " 3.Dar de baja a un cliente" << endl;
        cout<< " 4.Modificar un cliente" << endl;
        cout<< "----------------------------------------" << endl;
        cout<< " 0. Volver al menu principal" << endl;
        cout<< endl;
        cout<< " Ingresar el Numero de la Opcion: ";
        cin>>opcion;
        if(ValidarOpcionMenuPrincipal(5,opcion)){
        switch(opcion)
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

        }
    }
    }
    while (opcion!=0);
}

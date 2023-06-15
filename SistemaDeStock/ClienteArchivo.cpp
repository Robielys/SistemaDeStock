#include "ClienteArchivo.h"
#include<iostream>
using namespace std;

#include"Cliente.h"


int ClienteArchivo::CrearID()
{
    return getCantidad() + 1;

}

void ClienteArchivo::listar(Cliente* cli, int nroRegistro)
{

    FILE* pFile;
    pFile = fopen("Clientes.dat", "rb");
    if (pFile == NULL)
    {
        exit(100);
    }
    fread(cli, sizeof(Cliente), nroRegistro, pFile);
    fclose(pFile);
}
Cliente ClienteArchivo::BuscarCliente(int nroID)
{

    Cliente cli;
    FILE* pFile;
    pFile = fopen("Clientes.dat", "rb");
    if (pFile == NULL)
    {
        exit(100);
    }
    fseek(pFile, nroID * sizeof(Cliente),SEEK_SET);
    fread(&cli, sizeof(Cliente), 1, pFile);
    fclose(pFile);

    return cli;
}
bool ClienteArchivo::guardar(Cliente cli)
{

    cli.setID(CrearID());
    FILE* pFile;
    pFile = fopen("Clientes.dat","ab");
    if (pFile == NULL)
    {
        return false;
    }
    fwrite(&cli, sizeof(Cliente), 1, pFile);
    fclose(pFile);
    return true;
}
bool ClienteArchivo::guardarModificacion(Cliente cliente, int posicion)
{

    FILE* pFile = fopen("Clientes.dat","rb+");
    if(pFile == nullptr)
    {
        cout << "No se encontro Archivo";
        exit(10);
    }
    fseek(pFile,posicion * sizeof (Cliente),SEEK_SET);
    fwrite(&cliente,sizeof(Cliente),1,pFile);
    fclose(pFile);
    return true;
}
int ClienteArchivo::buscar(int ID)
{

    int i = 0;
    Cliente cli;
    FILE* pFile;
    pFile = fopen("Clientes.dat", "rb");
    if (pFile == NULL)
    {
        return false;
    }
    while(fread(&cli,sizeof(Cliente),1,pFile)==1)
    {
        if (cli.getID() == ID)
        {
            fclose(pFile);
            return i;
        }
        i++;
    }
    return -1;
}

int ClienteArchivo::getCantidad()
{
    int cantidad = 0;
    FILE* pFile = fopen("Clientes.dat","rb");
    if(pFile == nullptr)
    {
        cout<< "No existe archivo";
        exit(1);
    }

    fseek(pFile,0,SEEK_END);
    cantidad = ftell(pFile)/sizeof(Cliente);
    fclose(pFile);
    return cantidad;
}

#include "ArticuloArchivo.h"
#include<iostream>
#include "Articulo.h"
using namespace std;


int ArticuloArchivo::CrearID(){
return getCantidad() + 1;
}
void ArticuloArchivo::listar(Articulo* art, int nroRegistro)
{
    FILE* pFile;
    pFile = fopen("Articulos.dat", "rb");
    if (pFile == NULL)
    {
        exit(100);
    }
    fread(art, sizeof(Articulo), nroRegistro, pFile);
    fclose(pFile);
}
Articulo ArticuloArchivo::BuscarArt(int nroID){
    Articulo art;
    FILE* pFile;
    pFile = fopen("Articulos.dat", "rb");
    if (pFile == NULL)
    {
        exit(100);
    }
    fseek(pFile, nroID * sizeof(Articulo),SEEK_SET);
    fread(&art, sizeof(Articulo), 1, pFile);
    fclose(pFile);

    return art;
}
bool ArticuloArchivo::guardar(Articulo art)
{
    art.setID(CrearID());
    FILE* pFile;
    pFile = fopen("Articulos.dat", "ab");
    if (pFile == NULL)
    {
        return false;
    }
    fwrite(&art, sizeof(Articulo), 1, pFile);
    fclose(pFile);
    return true;
}


int ArticuloArchivo::buscar(int ID)
{
    int i = 0;
    Articulo aux;
   FILE* pFile;
    pFile = fopen("Articulos.dat", "rb");
    if (pFile == NULL)
    {
        return false;
    }
    while(fread(&aux,sizeof(Articulo),1,pFile)==1)
    {
        if (aux.getID() == ID)
        {
            fclose(pFile);
            return i;
        }
        i++;
    }
    return -1;
}
bool ArticuloArchivo::buscar1(string ID)
{
    int i = 0;
    Articulo aux;
    FILE* pFile;
    pFile = fopen("Articulos.dat", "rb");
    if (pFile == NULL)
    {
        exit(1);
    }
    while(fread(&aux,sizeof(Articulo),1,pFile)==1)
    {
        if (aux.getModelo() == ID)
        {
            fclose(pFile);
            return true;
        }
        i++;
    }
    return false;
}

int ArticuloArchivo::getCantidad()
{
    int cantidad = 0;
    FILE* pFile = fopen("Articulos.dat","rb");
    if(pFile == nullptr)
    {
        cout<< "No existe archivo";
        exit(1);
    }

    fseek(pFile,0,SEEK_END);
    cantidad = ftell(pFile)/sizeof(Articulo);
    fclose(pFile);
    return cantidad;
}
bool ArticuloArchivo::guardarModificacion(Articulo art, int posicion){
   FILE* pFile = fopen("Articulos.dat","rb+");
   if(pFile == nullptr){
    cout << "No se encontro archivo";
    exit(10);
   }
   fseek(pFile,posicion * sizeof (Articulo),SEEK_SET);
   fwrite(&art,sizeof(Articulo),1,pFile);
   fclose(pFile);
   return true;
}

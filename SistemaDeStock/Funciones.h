#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Cliente.h"
#include "Muestra.h"

bool ValidarCuit(long long cuit);
bool ValidarModelo(const char *modelo);
bool ValidarOpcionMenuPrincipal(int menu,int opcion);
bool ValidarArticulo(int codigoArticulo);
void EncabezadoDeArticulos();
void EncabezadoDeClientes();
void EncabezadoDeMuestras();
void EncabezadoDetallesM();
void EncabezadoDeMuestras2(int Numero, Cliente cliente);
void EncabezadoDeMuestras3(int Numero, Muestra muestra, Cliente cliente);
void MostrarMuestras();
#endif // FUNCIONES_H

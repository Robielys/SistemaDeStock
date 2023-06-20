#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Cliente.h"
#include "Muestra.h"

bool ValidarCuit(int cuit);
bool ValidarModelo(const char *modelo);
void EncabezadoDeArticulos();
void EncabezadoDeClientes();
void EncabezadoDeMuestras();
void EncabezadoDetallesM();
void EncabezadoDeMuestras2(int Numero, Cliente cliente);
void EncabezadoDeMuestras3(int Numero, Muestra muestra, Cliente cliente);
void MostrarMuestras();
#endif // FUNCIONES_H

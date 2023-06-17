#ifndef FECHA_H
#define FECHA_H
#include <string>
using namespace std;

class Fecha
{

private:
    int _Dia;
    int _Mes;
    int _Anio;

public:
    Fecha (int dia, int mes, int anio);
    Fecha ();

    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);
    string toString();

    int getDia();
    int getMes();
    int getAnio();


};

#endif // FECHA_H

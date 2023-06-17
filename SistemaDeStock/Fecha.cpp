#include<iostream>
using namespace std;


#include "Fecha.h"
#include <ctime>

Fecha::Fecha (int dia, int mes, int anio){
_Dia=dia;
_Mes=mes;
_Anio=anio;

}
Fecha::Fecha (){
time_t rawtime;
    struct tm timeinfo;

    time (&rawtime);
    timeinfo = *(localtime (&rawtime));

    _Dia = timeinfo.tm_mday;
    _Mes = timeinfo.tm_mon + 1;
    _Anio = timeinfo.tm_year + 1900;
}

void Fecha::setDia(int d){
_Dia=d;
}
void Fecha::setMes(int m){
_Mes=m;
}
void Fecha::setAnio(int a){
_Anio=a;
}

string Fecha::toString(){
string fecha;
fecha = to_string(_Dia)+ "/" + to_string(_Mes) + "/" + to_string(_Anio);
return fecha;
}

int Fecha::getDia(){
return _Dia;
}
int Fecha::getMes(){
return _Mes;
}
int Fecha::getAnio(){
return _Anio;
}

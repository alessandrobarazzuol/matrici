
/*
===============================================================================================
LIBRERIA dinamica (DLL ) MATRICI 
autore: classe 2G 2021-2022
Dev-C++ version 5.5.2 
Compilatore: MINGW64 
Dimensione massima della matrice 100x100
===============================================================================================
*/

#include<iostream>
#include <windows.h>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iomanip>


#ifndef _MATDLL_H_
#define _MATDLL_H_

using namespace std;

/*extern "C" specifica che la funzione è definita altrove e usa la convenzione 
di chiamata del linguaggio C. Il extern "C" modificatore può anche essere applicato 
a più dichiarazioni di funzione in un blocco*/
extern "C"
{	
__declspec(dllexport) void 	  		ordina   (double **m,int r, int c,int opz=2);
__declspec(dllexport) double  		det2x2   (double m[2][2]);
__declspec(dllexport) double  		det      (double m[3][3]);
__declspec(dllexport) void    		minore   (double m[3][3], double min[2][2], int rig, int col);
__declspec(dllexport) void    		minore3x4(double m[3][4], double min[3][3],  int col);
__declspec(dllexport) int     		rango3x4 (double m[3][4]);
__declspec(dllexport) void    		minore2x2(double m[2][2], double &min,int riga,int col);
__declspec(dllexport) int     		rango3x3 (double m[3][3]);
__declspec(dllexport) double  		mxyz     (double ma[3][4],int p);
__declspec(dllexport) int     		sistema  (double &x, double &y,double &z,double m[3][4],double ma[3][3]); 
__declspec(dllexport) long double 	dete     (double a[100][100],int dim);

};

#endif











//problema fisico, aca hare el codigo que resuelve la ecuacion

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

main(){
//defino variables
#define pi 3.1415
#define L 0.64
#define C 250
//el tiempo total será de un segundo y lo voy a recorrer cada 0.00002 sg, por lo tanto el numero de iteraciones será 50000
#define t 1
#define dt 0.00002
#define dx 0.005

//Leer archivos, numero de datos 129

int numDatos;
numDatos=129;
float *Datos = malloc(numDatos*sizeof(float));
FILE* file;
file = fopen("cond_ini_cuerda.dat", "r");
float *posiciones = malloc(129*sizeof(float));
float *amplitudes = malloc(129*sizeof(float));

int i;
for(i=0; i<129; i++){
    fscanf(file, "%f %f\n", &posiciones[i], &amplitudes[i]);
    Datos[i]=amplitudes[i];
	}
fclose(file);









}





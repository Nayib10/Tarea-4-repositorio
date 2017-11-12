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
//el tiempo total será de un segundo y lo voy a recorrer cada 0.0001 sg, por lo tanto el numero de iteraciones será 10000
#define t 1
#define dt 0.0001
#define dx 0.005

//Leer archivos, numero de datos 129

int numDatos;
numDatos=129;

float *Datos = malloc(numDatos*sizeof(float));

FILE* file;
file = fopen("cond_ini_cuerda.dat", "r");
float *posiciones = malloc(numDatos*sizeof(float));
float *amplitudes = malloc(numDatos*sizeof(float));

int i;
for(i=0; i<numDatos; i++){
    fscanf(file, "%f %f\n", &posiciones[i], &amplitudes[i]);
    Datos[i]=amplitudes[i];
	}
fclose(file);

// Primera parte, cuerda con extremos fijos

// Condiciones de frontera

float extIzq;
float extDer;
extIzq=100.0;
extDer=50.0;

//Recorrido
float cte;
int j;
//Constante
cte= ((pow(C,2)*pow(dt,2))/pow(dx,2));
//presente
float *now = malloc(numDatos*sizeof(float));
//futuro
float *auxiliar = malloc(numDatos*sizeof(float));
//pasado
float *tempBef = malloc(numDatos*sizeof(float));
//condiciones iniciales
float *CondInic = malloc(numDatos*sizeof(float));

//el numero de iteraciones sera 10000 por las razones explicadas anteriormente
for(i=0; i<128;i++){
//Las condiciones iniciales van a tomar el valor de las amplitudes dadas como condiciones iniciales
CondInic[i] = Datos[i];
auxiliar[i] = CondInic[i] + (cte/2.0) * (CondInic[i+1]-2.0*CondInic[i] + CondInic[i-1]);
}

for(i=0; i < 10000; i++){
	for(j=0;j<numDatos; j++){
		auxiliar[j]=(2.0*(1.0-cte))*now[j]+cte*(now[j+1]+now[j-1])-tempBef[j];
	}
tempBef[j]=now[j];
now[j]=auxiliar[j];
}



FILE* dat;
dat = fopen("ExtremosFijos.txt", "w");

for (j=0; j<129;j++){
fprintf(dat, "%f\n", auxiliar[j]);
}

}



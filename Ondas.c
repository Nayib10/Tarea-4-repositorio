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
int k;
//Constante
cte= (pow(C,2)*pow(dt,2))/pow(dx,2);

float *CondInic = malloc(numDatos*sizeof(float));
//presente
CondInic[k] = Datos[i];
//futuro
float *auxiliar = malloc(numDatos*sizeof(float));
//pasado
float *tempBef = malloc(numDatos*sizeof(float));

//el numero de iteraciones sera 50000 por las razones explicadas anteriormente
for (j=0; j<50000; j++){
	for (k=1; k<numDatos; k++){
		
		if (k=1){
			if (j=0){
		auxiliar[k] = (extIzq-2.0*CondInic[k]+CondInic[k+1])*cte+ (2.0*CondInic[k]-0.0);
			}
			else{
		auxiliar[k] = (extIzq-2.0*CondInic[k]+CondInic[k+1])*cte+ (2.0*CondInic[k]-tempBef[k]);
			}
		}
		
		
		if (k=128){
			if (j=0){
		auxiliar[k] = (CondInic[k-1]-2.0*CondInic[k]+extDer)*cte+ (2.0*CondInic[k]-0.0);
			}
			else{
		auxiliar[k] = (CondInic[k-1]-2.0*CondInic[k]+extDer)*cte+ (2.0*CondInic[k]-tempBef[k]);
			}
		}
		
		
		else {
			if (j=0){
		auxiliar[k] = (CondInic[k-1]-2.0*CondInic[k]+CondInic[k+1])*cte+ (2.0*CondInic[k]-0.0);
			}
			else{
		auxiliar[k] = (CondInic[k-1]-2.0*CondInic[k]+CondInic[k+1])*cte+ (2.0*CondInic[k]-tempBef[k]);
			}
		}
	}
tempBef[k]=CondInic[k];
CondInic[k]=auxiliar[k];
}




}



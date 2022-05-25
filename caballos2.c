#include <stdio.h>
#include <stdlib.h>

//*************************F U N C I O N E S************************************//

int crearMeta(int m){
    int meta=m-5;
    return meta;
}

int *modpos(int posicion[], int meta){
    int cant = sizeof(posicion);
    int *respuesta = malloc(15*sizeof(int));
    respuesta = posicion;
    for (int i = 0; i < cant; i++) {
        double aleatorio = rand()*3+1;
        int r=(int) aleatorio;
            if ((respuesta[i]+r) < meta) {
                respuesta[i] = respuesta[i] + r;
            }else respuesta[i] = meta + 1;
            
    }//fin for
    return respuesta;
}

void dibujarmatriz(int posicion[], int meta, int d){
    int c = sizeof(posicion);
    int hipodromo[c][d];
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < d; j++) {
            hipodromo[i][0] = 0;//con esto limpiamos la matriz original
            if (meta==j) {
                hipodromo[i][j]=1;//agregamos la meta
                printf("1");// last update
            }
            if (posicion[i]==j) {
                    printf("☻ ");//situamos el caballo
            } else  printf(" ");//mostramos lo que hay en la posicion         
        }
    printf("\n");
    }       
}   

//*************************F I N  D E  F U N C I O N E S************************************//

int main(){
    int c, d;//declaracion de variables c: Caballos, d: Distancia. 
    printf("Ingrese la cantidad de caballos y la distancia: ");
    scanf("%i %i", &c, &d);
    printf("\n");

    //int hipodromo[c][d];
    int posicion[c];
    int flag=0;
    int  meta = crearMeta(d);
    printf("☻=Caballo  0=pocicion vacia  1=Meta\n");

    for (int i = 0; i < sizeof(posicion); i++) {
        posicion[i]=0;
    }

    while(flag==0){
        dibujarmatriz(posicion,meta,d);
        for (int i = 0; i < c; i++) {
                if (flag==0) {
                    if (posicion[i]>meta) {
                        int num = i + 1;
                        printf(" primer caballo en llegar a la meta %i \n", num);
                        flag=1;
                    }else{ 
                        int posicion[c] = modpos(posicion, meta);
                    }
                }//fin if de flag
            }//fin if de turnos    
    }
}





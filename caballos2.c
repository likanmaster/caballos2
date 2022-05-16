#include <stdio.h>

int main(){
    int c, d;//declaracion de variables c: Caballos, d: Distancia. 
    printf("Ingrese la cantidad de caballos y la distancia: ");
    scanf("%i %i", &c, &d);
    printf("\n");

    int hipodromo[c][d];
    int posicion[c];
    int flag=0;
    int  meta=crearmeta(d);
    printf("☻=Caballo  0=pocicion vacia  1=Meta\n");

    for (int i = 0; i < sizeof(posicion); i++) {
        posicion[i]=0;
    }

    while(flag==0){
        dibujarmatriz(posicion,hipodromo,meta);
        for (int i = 0; i < c; i++) {
                if (flag==0) {
                    if (posicion[i]>meta) {
                      printf(" primer caballo en llegar a la meta "+(i+1)+"\n");
                      flag=1;
                    }else  posicion=modpos(posicion, meta);
                }//fin if de flag
            }//fin if de turnos    
    }
}

//*************************F U N C I O N E S************************************//

int crearmeta(int m){
    int meta=m-5;
    return meta;
}

static int[] modpos(int[] posicion, int meta){
    for (int i = 0; i < posicion.length; i++) {
        double aleatorio = Math.random()*3+1;
        int r=(int) aleatorio;
            if (posicion[i]+r<meta) {
                int pos=posicion[i]+r;
                posicion[i]=pos;
            }else posicion[i]=meta+1;
            
    }//fin for
    return posicion;
}

void dibujarmatriz(int[] posicion, int[][] hipodromo, int meta){
    for (int i = 0; i < posicion.length; i++) {
        for (int j = 0; j < hipodromo[0].length; j++) {
            hipodromo[i][0]=0;//con esto limpiamos la matriz original
            if (meta==j) {
                hipodromo[i][j]=1;//agregamos la meta
                System.out.print("1");// last update
            }
            if (posicion[i]==j) {
                    System.out.print("☻ ");//situamos el caballo
            } else  System.out.print(" ");//mostramos lo que hay en la posicion         
        }
    System.out.println(" ");
    }       
}   

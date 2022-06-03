#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
 

#ifdef _WIN32
  #include<windows.h>
#endif  

//variable pantalla tipo mutex para sincronizar el acceso a la pantalla
#ifdef MUTEX
pthread_mutex_t pantalla;
#endif
//para compilar usar: gcc -o carrera carrera.c -lpthread -lncurses -DMUTEX
//*************************F U N C I O N E S************************************//

int crearMeta(int m){
    int meta=m-5;
    return meta;
}
void limpiar_pantalla()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

int *modpos(int *posicion, int meta){
    int cant;
    cant = (int)sizeof(posicion);
    int *resul;
    resul = (int*)malloc(cant * sizeof(int));
    resul = posicion;
    int i;
    for (i = 0; i < cant; i++) {
        double aleatorio = rand() % (1+1);
        //printf("rand %f \n",aleatorio);// last update
        //int r = (int)aleatorio;
        if ((resul[i]) < meta) {
        	if(aleatorio<1){
			
            int pos = resul[i] + 1;
            resul[i] = pos;
            }
        }else{
            resul[i] = meta + 1;
        }
    }//fin for
    return resul;
}

void dibujarmatriz(int *posicion, int meta, int d){
    int c = (int)sizeof(posicion);
    int hipodromo[c][d];
    int i, j;
    for (i = 0; i < c; i++) {
        for (j = 0; j < d; j++) {
            hipodromo[i][0] = 0;//con esto limpiamos la matriz original
            if (meta == j) {
                hipodromo[i][j]=1;//agregamos la meta
                printf("1");// last update
            }
            if (posicion[i]==j) {
                    printf("0");//situamos el caballo
            } else  printf(" ");//mostramos lo que hay en la posicion         
        }
    printf("\n");
    }       
}   

//*************************F I N  D E  F U N C I O N E S************************************//


 #ifdef MUTEX
	pthread_mutex_init (&pantalla, NULL);//inicializa variable pantalla tipo mutex
  #endif
  
int main(){
    clock_t tiempo_inicio, tiempo_final;
    double segundos;

    tiempo_inicio = clock();
    int c, d, i;//declaracion de variables c: Caballos, d: Distancia.
	int fin=0; 
	int win=1000;
    
    printf("Ingrese la cantidad de caballos (entre 1 y 7 ) y la distancia (entre 50 y 100): ");
    scanf("%i %i", &c, &d);	
    if(c<1||c>7||d<50||d>100){
    	printf("Por favor verifique que los datos ingresados esten dentro de los rangos establecidos\n caballos (entre 1 y 7 ) y  distancia (entre 50 y 100): ");
    
    scanf("%i %i", &c, &d);	
	}	
	
    
    int auxf=c;
    printf("\n");
    

    //int hipodromo[c][d];
    //int posicion[c];
    int *pos = malloc(c * sizeof(int));
    int flag=0;
    int  meta = crearMeta(d);
    printf("0=Caballo   1=Meta\n");

    for (i = 0; i < c; i++) {
        pos[i] = 0;
    }

    while(fin<auxf){
    	 #ifdef MUTEX
  	pthread_mutex_lock(&pantalla);	//bloquea la pantalla (seccion critica)
    #endif
    	 limpiar_pantalla(); 
    	 printf("%d caballos corriendo \n",c);
       usleep(20000);
        dibujarmatriz(pos,meta,d);
       #ifdef MUTEX
		pthread_mutex_unlock(&pantalla);//desbloquea la pantalla (seccion critica)
    #endif
        for (i = 0; i < c; i++) {
            //if (flag == 0) {
                if (pos[i] > meta) {
                	
                    int num = i+1 ;
                    printf(" el caballo No. %i llego a la meta \n", num);
                    if(win==1000){
                		win=num;
					}
                    flag=1;
                    fin=fin+1;
                }else{ 
                    pos = modpos(pos, meta);
                }
                
           // }//fin if de flag
        }//fin if de turnos   
        
		 
    }
 printf(" largo de la pista %i  metros \n", d);
  printf(" ___________________________\n");
 printf(" el caballo ganador es el caballo numero %i  \n", win-1);
   printf(" ___________________________\n");
 for (i=0;i<c;i++){
 	printf(" el caballo  %d corrio %d  metros \n", i+1, pos[i]+4);
 }
  printf(" ___________________________\n");
  
   printf(" Gracias por participar!\n");
    tiempo_final = clock();

    segundos = (double)(tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecucion: %f segundos \n",segundos); 
}

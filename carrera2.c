//para compilar usar: gcc -o carrera carrera.c

#include<unistd.h>							//bibliotecas de sistema Unix
#include<stdlib.h> 							//bibliotecas funciones estandar
#include<ncurses.h> 						//bibliotecas manejo de pantalla
#include<time.h> 

typedef struct{									//se define una estructura
	int carril;										//para el caballo
	int pos;
	char caballo;									//
	int vueltas;

} parametro;


int funcionCab(parametro *para){
  int x=para->pos,y=para->carril;		    //para posicionamiento de pantalla
  mvprintw(y,x," %c",para->caballo);//posiciona e imprime el competidor h
  refresh();									//refresca los cambion en la pantalla
  usleep(100000/10);								//duerme por 1/4 de segundo
  if(drand48()<0.5) x++;		    		//avanza una posicion con probabilidad 0.5
	return x;
  }


int main(void){

  int c;
  int d;
  int v;
  
  printf("Ingrese la cantidad de vueltas(entre1 y 4) caballos (entre 1 y 7 ) y la distancia (entre 50 y 100): ");
  scanf("%i %i %i", &v,&c, &d);
    if(v<1||v>4||c<1||c>7||d<50||d>100){
       printf("Por favor verifique que los datos ingresados esten dentro de los rangos establecidos\n vueltas (entre1 y 4) caballos (entre 1 y 7 ) y  distancia (entre 50 y 100): ");
   
    scanf("%i %i %i", &v,&c, &d);
}



  int x=1,y=9;		    		//para posicionamiento de pantalla

	parametro cab1,cab2,cab3,cab4,cab5,cab6,cab7;			//estructura con los parametros de entrada
	


  initscr();										//inicializa la pantalla para ncurses
	curs_set(0);    							//elimina el cursor
	erase();											//limpia pantalla
	refresh();										//refresca los cambion en la pantalla
	srand(time(NULL));						//inicializa semilla de la funcion random
  
  cab1.carril=1;
  cab1.caballo='1';
  cab1.pos=1;
  cab1.vueltas=0;
  
  cab2.carril=2;
  cab2.caballo='2';
  cab2.pos=1;
  cab2.vueltas=0;
  
  cab3.carril=3;
  cab3.caballo='3';
  cab3.pos=1;
  cab3.vueltas=0;

  cab4.carril=4;
  cab4.caballo='4';
  cab4.pos=1;
  cab4.vueltas=0;

  cab5.carril=5;
  cab5.caballo='5';
  cab5.pos=1;
  cab5.vueltas=0;

  cab6.carril=6;
  cab6.caballo='6';
  cab6.pos=1;
  cab6.vueltas=0;
  
  cab7.carril=7;
  cab7.caballo='7';
  cab7.pos=1;
  cab7.vueltas=0;
  int tv=0;
  int tm=0;
  while (x<v*d ){		    										
    mvprintw(y,x," p");					//posiciona e imprime el competidor p
		refresh();								//refresca los cambion en la pantalla
    usleep(1000/10);							//duerme por 1/4 de segundo
    if(drand48()<0.5) x++;		    	//avanza una posicion con probabilidad 0.5
    	if (c==7){
		      cab1.pos=funcionCab(&cab1);
          cab2.pos=funcionCab(&cab2);
          cab3.pos=funcionCab(&cab3);
	        cab4.pos=funcionCab(&cab4);
		      cab5.pos=funcionCab(&cab5);
		      cab6.pos=funcionCab(&cab6);
		      cab7.pos=funcionCab(&cab7);
      };
       if (c==6){
		      cab1.pos=funcionCab(&cab1);
          cab2.pos=funcionCab(&cab2);
          cab3.pos=funcionCab(&cab3);
	        cab4.pos=funcionCab(&cab4);
		      cab5.pos=funcionCab(&cab5);
		      cab6.pos=funcionCab(&cab6);
		   };
		   if (c==5){
		      cab1.pos=funcionCab(&cab1);
          cab2.pos=funcionCab(&cab2);
          cab3.pos=funcionCab(&cab3);
	        cab4.pos=funcionCab(&cab4);
		      cab5.pos=funcionCab(&cab5);
      };
      if (c==4){
		      cab1.pos=funcionCab(&cab1);
          cab2.pos=funcionCab(&cab2);
          cab3.pos=funcionCab(&cab3);
	        cab4.pos=funcionCab(&cab4);
      };
      if (c==3){
		      cab1.pos=funcionCab(&cab1);
          cab2.pos=funcionCab(&cab2);
          cab3.pos=funcionCab(&cab3);
      };
       if (c==2){
		      cab1.pos=funcionCab(&cab1);
          cab2.pos=funcionCab(&cab2);
      };
       if (c==1){
		      cab1.pos=funcionCab(&cab1);
      };

}
//tabla de resultados
 
 printf(" \n");
  mvprintw(10,2,"____________*********______________");
 


  int mayor=cab1.pos;
  char win=cab1.caballo;
  if (x>=v*d) mvprintw(20,x,"ganó p");
	else if (cab1.pos>=v*d) win =cab1.caballo;
	else if (cab2.pos>=v*d) win =cab2.caballo;
	else if (cab3.pos>=v*d) win =cab3.caballo;
	else if (cab4.pos>=v*d) win =cab4.caballo;
	else if (cab5.pos>=v*d) win =cab5.caballo;
	else if (cab6.pos>=v*d) win =cab6.caballo;
	else if (cab7.pos>=v*d) win =cab7.caballo;

	if (cab2.pos>mayor){
	 mayor=cab2.pos;
	 win=cab2.caballo;
	}
	else if (cab3.pos>mayor) {
	 mayor=cab3.pos;
	 win=cab3.caballo;
	}
	else if (cab4.pos>mayor) {
	 mayor=cab4.pos;
	 win=cab4.caballo;
	}
	else if (cab5.pos>mayor) {
	 mayor=cab5.pos;
	 win=cab5.caballo;
	}
	else if (cab6.pos>mayor) {
	 mayor=cab6.pos;
	 win=cab6.caballo;
	}
	else if (cab7.pos>mayor) {
	 mayor=cab7.pos;
	 win=cab7.caballo;
	}
	else mvprintw(20,x," ");
  
//contador de vueltas
	cab1.vueltas=cab1.pos/d;
	cab2.vueltas=cab2.pos/d;
	cab3.vueltas=cab3.pos/d;
	cab4.vueltas=cab4.pos/d;
	cab5.vueltas=cab5.pos/d;
	cab6.vueltas=cab6.pos/d;
  cab7.vueltas=cab7.pos/d;
tv=cab1.vueltas+cab2.vueltas+cab3.vueltas+cab4.vueltas+cab5.vueltas+cab6.vueltas+cab7.vueltas;
tm=cab1.pos+cab2.pos+cab3.pos+cab4.pos+cab5.pos+cab6.pos+cab7.pos;

  mvprintw(11,2,"distancia recorrida por caballos \n");
  if (c==7){
  mvprintw(12,2,"el caballo numero %c corrio %d metros con %d vueltas",cab1.caballo,cab1.pos, cab1.vueltas);
  mvprintw(13,2,"el caballo numero %c corrio %d metros con %d vueltas",cab2.caballo,cab2.pos, cab2.vueltas);
  mvprintw(14,2,"el caballo numero %c corrio %d metros con %d vueltas",cab3.caballo,cab3.pos, cab3.vueltas);
  mvprintw(15,2,"el caballo numero %c corrio %d metros con %d vueltas",cab4.caballo,cab4.pos, cab4.vueltas);
  mvprintw(16,2,"el caballo numero %c corrio %d metros con %d vueltas",cab5.caballo,cab5.pos, cab5.vueltas);
  mvprintw(17,2,"el caballo numero %c corrio %d metros con %d vueltas",cab6.caballo,cab6.pos, cab6.vueltas);
  mvprintw(18,2,"el caballo numero %c corrio %d metros con %d vueltas",cab7.caballo,cab7.pos, cab7.vueltas);
  };
   if (c==6){
  mvprintw(12,2,"el caballo numero %c corrio %d metros con %d vueltas",cab1.caballo,cab1.pos, cab1.vueltas);
  mvprintw(13,2,"el caballo numero %c corrio %d metros con %d vueltas",cab2.caballo,cab2.pos, cab2.vueltas);
  mvprintw(14,2,"el caballo numero %c corrio %d metros con %d vueltas",cab3.caballo,cab3.pos, cab3.vueltas);
  mvprintw(15,2,"el caballo numero %c corrio %d metros con %d vueltas",cab4.caballo,cab4.pos, cab4.vueltas);
  mvprintw(16,2,"el caballo numero %c corrio %d metros con %d vueltas",cab5.caballo,cab5.pos, cab5.vueltas);
  mvprintw(17,2,"el caballo numero %c corrio %d metros con %d vueltas",cab6.caballo,cab6.pos, cab6.vueltas);
  };
   if (c==5){
  mvprintw(12,2,"el caballo numero %c corrio %d metros con %d vueltas",cab1.caballo,cab1.pos, cab1.vueltas);
  mvprintw(13,2,"el caballo numero %c corrio %d metros con %d vueltas",cab2.caballo,cab2.pos, cab2.vueltas);
  mvprintw(14,2,"el caballo numero %c corrio %d metros con %d vueltas",cab3.caballo,cab3.pos, cab3.vueltas);
  mvprintw(15,2,"el caballo numero %c corrio %d metros con %d vueltas",cab4.caballo,cab4.pos, cab4.vueltas);
  mvprintw(16,2,"el caballo numero %c corrio %d metros con %d vueltas",cab5.caballo,cab5.pos, cab5.vueltas);
  };
  if (c==4){
  mvprintw(12,2,"el caballo numero %c corrio %d metros con %d vueltas",cab1.caballo,cab1.pos, cab1.vueltas);
  mvprintw(13,2,"el caballo numero %c corrio %d metros con %d vueltas",cab2.caballo,cab2.pos, cab2.vueltas);
  mvprintw(14,2,"el caballo numero %c corrio %d metros con %d vueltas",cab3.caballo,cab3.pos, cab3.vueltas);
  mvprintw(15,2,"el caballo numero %c corrio %d metros con %d vueltas",cab4.caballo,cab4.pos, cab4.vueltas);
  };
  if (c==3){
  mvprintw(12,2,"el caballo numero %c corrio %d metros con %d vueltas",cab1.caballo,cab1.pos, cab1.vueltas);
  mvprintw(13,2,"el caballo numero %c corrio %d metros con %d vueltas",cab2.caballo,cab2.pos, cab2.vueltas);
  mvprintw(14,2,"el caballo numero %c corrio %d metros con %d vueltas",cab3.caballo,cab3.pos, cab3.vueltas);
  };
  if (c==2){
  mvprintw(12,2,"el caballo numero %c corrio %d metros con %d vueltas",cab1.caballo,cab1.pos, cab1.vueltas);
  mvprintw(13,2,"el caballo numero %c corrio %d metros con %d vueltas",cab2.caballo,cab2.pos, cab2.vueltas);
  };
  if (c==1){
  mvprintw(12,2,"el caballo numero %c corrio %d metros con %d vueltas",cab1.caballo,cab1.pos, cab1.vueltas);
  };
  mvprintw(19,2,"totales: %d vueltas y %d metros \n ",tv,tm);

  mvprintw(21,2,"ganò el caballo %c \n",win);
  mvprintw(22,2,"el tamano de la pista fue de %d metros \n",d);
  mvprintw(24,2,"gracias por participar !");

	refresh();
  
	getch(); 										//espera que se ingrese cualquier tecla para salir
	endwin();										//cierra la pantalla de ncurses

}




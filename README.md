

Simulacion de carrera de caballos creada en el lenguaje C, conuna cantidad de 2 a 7  caballos

variables de entrada: c=cantidad de caballos m=largo del hipodromo(se recomienda un valor entero entre 40 a 60 para una correcta visualizacion)

el programa consiste en poner los caballos en el punto de partida y que estos avancen en turnos  randomicos una posicion hacia adelante, el primero en pasar la meta es el ganador

  1           
           2   
              3   
       4


Para la ejecución del algoritmo se deben seguir los siguientes pasos:
Primero abrir la terminal de Linux

se debe clonar el repositorio remoto en el repositorio local utilizando el siguiente comando:

    git clone https://github.com/likanmaster/caballos2.git

Para poder clonar el repositorio luego de ejecutar el comando anterior, se solicitara el nombre de usuario y contraseña (en caso de que el repositorio este privado) que deben ser ingresados por la persona que esta ejecutando el algoritmo

El siguiente paso es acceder a la carpeta del repositorio local que se creo inicialmente, para esto es necesario cambiarse de directorio con el comando cd, como el siguiente ejemplo, en caso de que la carpeta se llame caballos se de usar el comando de la siguiente forma:

    cd caballos2

Luego primero se debe compilar el programa con la siguiente instrucción

    gcc -o caballlos2 caballos2.c -lpthread -lncurses -DMUTEX

Una vez compilado el programa se debe ejecutar ingresando los parametros de entrada cantidad de caballos y lago del hipodromo como por ejemplo:

    /.carrera

Con la realización de todos los pasos mencionados anteriormente es posbible ejecutar el programa.

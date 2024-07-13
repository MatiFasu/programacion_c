Se juega una carrera entre distintas especies de hormigas.

En esta carrera corre una hormiga reina, una hormiga roja y una hormiga. Es una carrera por pasos, donde la reina avanza entre 3 y 8 pasos (donde la cantidad de pasos se elije aleatoriamente entre estos valores), la hormiga roja entre 2 y 7 pasos y la hormiga negra entre 1 y 9 pasos.

La carrera termina con la primer hormiga que haya llegado a 141 pasos, o sea a la meta. Si los tres superan esta cantidad en la misma cantidad de veces que dieron pasos, es empate.

Se contará con dos procesos.

Se debe utilizar threads, cola de mensajes, y para el sincronismo usar mutex y/o semáforos.

Pueden ser un proceso por hormiga, o quizás le conviene más que uno de los procesos sea pista/tablero/cancha y el otro proceso sean los animales(threads).

Puede considerar de utilizar memoria compartida si lo precisa para el desarrollo. Puede utilizar los siguientes destino y eventos, o los que usted elija.

Se debe mostrar lo que sucede en los dos procesos en todo momento, y cual jugador gano y el resultado.

Se debe comenzar la carrera presionando una tecla cuando los dos procesos estén corriendo, pero sería recomendable mediante memoria compartida.

Pensar bien que/quien es cada proceso! Comenzar por lo mínimo, lo más importante es el sincronismo y que compile!.

Se debe actualizar cada 300ms
Si utiliza memoria dinámica debe liberar la memoria!
Utilizar memoria compartida o un bucle, para siempre poder realizar las inicializaciones correspondientes, y no depender de correr un proceso determinado primero.
Utilizar Makefile con la estructura de archivos vista en la cursada.
Utilizar los delay (sleep) que correspondan.

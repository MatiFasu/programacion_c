En el clásico de futbol de primera, se cuenta con dos procesos (uno por cada equipo) que juegan un partido. 

A la par también se cuenta con un tercer proceso, panel que informa lo que va sucediendo en el partido.

El partido termina cuando uno de los equipos llega a la cantidad máxima de goles que debe ser informada por parámetro al ejecutar el/los programa/s.

Es un partido por turnos, en cada turno se realiza el remate de cada equipo. Para el remate se debe solicitar que presione (ingresa por pantalla) un numero de 1 al 3, y a la par hacer un numero aleatorio (también de 1 a 3), si acierta (se corresponde con el número informado), es gol, sino, es fuera. Eso se debe guardar en archivo (ya sea uno solo o uno por equipo).

Remate del primer equipo, se debe informar en el proceso del equipo. Luego puede mostrarse en el panel, o esperar el segundo remate.

Remate del segundo equipo, se debe informar en el proceso del equipo. Luego debe informarse en el panel la totalidad de los dos remates, o el del segundo equipo dependiendo que modo se haya escogido.

Panel: Todo lo que va sucediendo debe ir informándose en el proceso panel. Puede informarse luego de cada remate de un equipo, ó remata el primer equipo, remata el segundo equipo, y se muestra por panel, y así sucesivamente hasta el final.

En el final del partido se debe informar el ganador y los goles. El primero en llegar a 3 goles gana.
 
Para comunicar puede/debe utilizarse archivos y/o semáforos para el sincronismo.

Cada 500ms cada sistema debe chequear para mostrar o pasar el turno.

En total son 3 procesos corriendo en forma simultanea.

Se debe mostrar la actividad de cada proceso. 

# TP12

Guía 12: Threads
1. [ENTREGAR] Buer circular
Un buer circular es una estructura de datos de tamaño jo, que tiene conectado el principio con el nal.
Resulta útil para implementar colas FIFO, de tamaño máximo limitado, ya que no requieren mover los
datos a medida que se van sacando de la cola.
En el siguiente ejemplo podemos observar la dinámica.
El buer comienza vacío,
luego se ingresa el primer dato (1). Observar que la posición donde se decida empezar a escribir no
importa al ser circular.
Luego se ingresan dos datos más (2) y (3).
Luego se sacan los datos en el orden en el que fueron ingresados: Primero (1), luego (2).
Figura 0.1: Ejemplo buer circular
Se debe implementar una librería para generar buers circulares de caracteres. El mismo debe permitir:
Crear múltiples buers;
Ingresar un nuevo dato al nal,
sacar el primer dato de la cola,
indicar si el buer se encuentra lleno.
2. [ENTREGAR] Generador de eventos de teclado
Se deberá realizar una librería que capture eventos de teclado y los ponga en una cola para que puedan
ser utilizados por cualquier programa. La misma debe correr de manera paralela, para que pueda estar
capturando eventos constantemente sin interrumpir la ejecución del programa principal.
Funciones recomendadas:
start/stop: Comienzan y nalizan la captura de eventos
get_next_event: Obtener el próximo evento, siguiendo una estructura FIFO
3. [ENTREGAR] Programa de prueba
Realizar un programa que demuestre el correcto funcionamiento de las librerías realizadas.

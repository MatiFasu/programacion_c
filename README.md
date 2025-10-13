# Programación paralela

🧩 Problemática

A medida que los sistemas informáticos evolucionan, el volumen de datos y la complejidad de las aplicaciones aumentan considerablemente.
Los programas que se ejecutan de forma secuencial (una tarea tras otra) no pueden aprovechar todo el potencial del hardware moderno, especialmente los procesadores multinúcleo.

Esto genera problemas como:

- Bajo rendimiento y mayores tiempos de ejecución.
- Desaprovechamiento de recursos del sistema.
- Dificultad para escalar aplicaciones que procesan grandes volúmenes de información o tareas concurrentes.

⚙️ Qué se Resuelve

La Programación Paralela busca dividir un problema complejo en subtareas que puedan ejecutarse simultáneamente, logrando así:

- Acelerar el procesamiento mediante la ejecución concurrente de procesos e hilos.
- Optimizar el uso de los recursos (CPU, memoria, dispositivos de E/S).
- Mejorar la eficiencia y escalabilidad de las aplicaciones.
- Facilitar la sincronización y comunicación entre procesos a través de mecanismos como semaforos, memoria compartida y colas de mensajes (POSIX).

## Contenidos

1. [Procesos](#procesos)
2. [Archivos](#archivos)
3. [POSIX](#posix)
4. [Semáforo](#semáforo)
5. [Memoria compartida](#memoria-compartida)
6. [Cola de mensajes](#cola-de-mensajes)
7. [Programación en paralelo](#programación-en-paralelo)
8. [Multithreading](#multithreading)

## Procesos

En esta sección se cubren los conceptos fundamentales relacionados con los procesos en sistemas operativos, incluyendo la creación, administración y comunicación entre procesos.

## Archivos

Se aborda el manejo de archivos en sistemas operativos, incluyendo operaciones de lectura, escritura, y manipulación de archivos.

## POSIX

Los estándares POSIX son un conjunto de normativas para la compatibilidad entre sistemas operativos tipo UNIX. Se estudian las funciones y herramientas proporcionadas por POSIX para el desarrollo de aplicaciones multiplataforma.

## Semáforo

Se profundiza en el concepto de semáforos y su aplicación en la sincronización de procesos y la gestión de recursos compartidos.

## Memoria compartida

Se analiza el uso de la memoria compartida como mecanismo de comunicación entre procesos y como herramienta para la optimización de recursos en sistemas concurrentes.

## Cola de mensajes

Se explora el uso de colas de mensajes para la comunicación entre procesos, permitiendo la transferencia de datos de manera asincrónica y segura.

## Programación en paralelo

Se introduce la programación en paralelo como técnica para la ejecución simultánea de tareas, mejorando el rendimiento y la eficiencia de los sistemas.

## Multithreading

Se estudian los conceptos de multithreading, incluyendo la creación y sincronización de hilos de ejecución para lograr la concurrencia en aplicaciones.

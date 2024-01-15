# Calculadora con Árbol de Sintaxis Abstracta (AST)

## Visión general
Este programa en C++ implementa una calculadora simple que evalúa expresiones matemáticas utilizando un Árbol de Sintaxis Abstracta (AST). El AST es una representación jerárquica de la estructura de la expresión, donde cada nodo corresponde a un operador u operando.

## Funcionamiento

## Estructura del Nodo AST:
El programa define una estructura Node para representar nodos en el AST. Cada nodo puede almacenar un operador (op1), un valor numérico (value), y punteros a nodos hijos izquierdo (izq) y derecho (der).

## Construcción del AST:
La función createAST construye el AST a partir de una expresión matemática dada. Utiliza un análisis descendente recursivo para manejar números, paréntesis y operadores.

## Análisis de la Expresión:
El programa analiza la expresión de entrada caracter por caracter, manejando números y expresiones anidadas dentro de paréntesis.

## Evaluación del AST:
La función evaluateAST evalúa recursivamente el AST para calcular el resultado final de la expresión matemática.

## Operadores Soportados:
La calculadora admite operadores aritméticos básicos: suma (+), resta (-), multiplicación (*), y división (/).

## Manejo de Errores:
El programa realiza comprobaciones básicas de errores, como asegurarse de que haya números o paréntesis izquierdos esperados.

## Uso

### Entrada:
Ejecute el programa e ingrese una expresión matemática cuando se le solicite.

### Salida:
El programa mostrará el resultado de la expresión evaluada.

### Ejemplo
Ingrese una expresion matematica: (3 + 5) * 2 - 7

Resultado: 11

## Gestión de Memoria
El programa libera la memoria asignada para el AST utilizando la función freeAST después de evaluar la expresión.

## Notas
El código utiliza características de C++, como estructuras, punteros y funciones recursivas, para implementar el AST y evaluar expresiones.

## Descargo de responsabilidad
Esta calculadora está diseñada con fines educativos y puede no manejar todos los casos límite o expresiones complejas. Úsela con precaución y considere la implementación de manejo adicional de errores para uso en producción.

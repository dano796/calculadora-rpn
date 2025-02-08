# Calculadora RPN en C

Implementación de una calculadora RPN (Notación Polaca Inversa) en C. La calculadora permite realizar operaciones matemáticas básicas y avanzadas utilizando una pila para almacenar los operandos.

## Características

- Soporte de operaciones básicas: suma (`+`), resta (`-`), multiplicación (`*`), división (`/`).
- Funciones avanzadas: raíz cuadrada (`r`), seno (`s`), coseno (`c`), tangente (`t`), potencia (`p`).
- Manejo de errores: detecta divisiones por cero, raíces cuadradas de números negativos y tangentes indefinidas (múltiplos de 90 grados).
- Interfaz de consola interactiva.
- Pila de 8 niveles para almacenar operandos.

## Requisitos

- Compilador de C (`gcc`).
- Biblioteca matemática (`lm`).

### Menú de opciones

1. **Ingresar número**: Permite ingresar un número a la pila.
2. **Seleccionar operación**: Permite elegir una operación matemática.
3. **Limpiar último**: Elimina el último número ingresado en la pila.
4. **Limpiar todo**: Vacía toda la pila.
5. **Salir**: Cierra la calculadora.

### Operaciones disponibles

- +: Suma los dos últimos números ingresados en la pila.
- -: Resta el penúltimo número ingresado en la pila con el último número ingresado en la pila.
- *: Multiplica los dos últimos números ingresados en la pila.
- /: Divide el penúltimo número ingresado en la pila con el último número ingresado en la pila.
- **r**: Calcula la raíz cuadrada del último número ingresado en la pila.
- **s**: Calcula el seno del último número ingresado en la pila (en grados).
- **c**: Calcula el coseno del último número ingresado en la pila (en grados).
- **t**: Calcula la tangente del último número ingresado en la pila (en grados).
- **p**: Eleva el penúltimo número ingresado en la pila a la potencia del último número ingresado en la pila.

---

### Daniel Ortiz Aristizábal
### Sistemas Operativos - Universidad Pontificia Bolivariana

#include <stdio.h>
#include <math.h>

/**
 * Implementación Calculadora RPN en C
 * @author Daniel Ortiz Aristizábal
 */

float stack[8];

void printStack(void) {
    int i = 0;
    for (i = 0; i < 8; i++) {
        printf("%d", 8 - i);
        printf(". ");
        printf("%f", stack[i]);
        printf("\n");
    }
}

void moveStackUp(void) {
    int i = 0;
    for (i = 1; i < 8; i++) {
        stack[i - 1] = stack[i];
    }
}

void moveStackDown(void) {
    int i = 0;
    for (i = 7; i > 0; i--) {
        stack[i] = stack[i - 1];
    }
    stack[0] = 0.0;
}

double toRadians(void) {
    float pi = 3.14159265359;
    return stack[7] * (pi / 180);
}

void operation(char opChar) {
    switch (opChar){
    case '+':
        stack[6] += stack[7];
        moveStackDown();
        printf("\033[2J");
        break;
    case '-':
        stack[6] -= stack[7];
        moveStackDown();
        printf("\033[2J");
        break;
    case '*':
        stack[6] *= stack[7];
        moveStackDown();
        printf("\033[2J");
        break;
    case '/':
        if (stack[7] == 0) {
            printf("\033[2J");
            printf("Math Error\n\n");
        } else {
            stack[6] = stack[6]/stack[7];
            moveStackDown();
            printf("\033[2J");
        }
        break;
    case 'r':
        if (stack[7] < 0) {
            printf("\033[2J");
            printf("Math Error\n\n");
        } else {
            stack[7] = sqrt(stack[7]);
            printf("\033[2J");
        }
        break;
    case 's':
        stack[7] = sin(toRadians());
        printf("\033[2J");
        break;
    case 'c':
        stack[7] = cos(toRadians());
        printf("\033[2J");
        break;
    case 't':
        // Se verifica si el valor en stack[7] es múltiplo de 90
        if (fabs(fmod(stack[7], 90)) < 1e-6) { 
            // fmod(stack[7], 90) calcula el residuo de dividir stack[7] entre 90
            // fabs() toma el valor absoluto del residuo (para manejar correctamente ángulos negativos)
            // Si el residuo es menor que 1e-6 (0.000001), se considera que stack[7] es un múltiplo de 90
            printf("\033[2J");
            printf("Math Error\n\n");
        } else {
            stack[7] = tan(toRadians());
            printf("\033[2J");
        }
        break;
    case 'p':
        stack[6] = pow(stack[6], stack[7]);
        moveStackDown();
        printf("\033[2J");
        break;
    default:
        printf("\033[2J");
            printf("Ingrese un caracter de operación valido\n");
        break;
    }
}

void printOptionsMenu(void) {
    printf("Qué desea hacer?\n");
    printf("1. Ingresar número 2. Seleccionar operación 3. Limpiar último\n");
    printf("4. Limpiar todo  5. Salir\n");
}

void clearAll(void) {
    int i = 0;
    for (i = 0; i < 8; i++){
        stack[i] = 0.0;
    }
}

void clearLast(void) {
    stack[7] = 0.0;
    moveStackDown();
}

int main (void) {
    int i, opc;
    float num = 0;
    char opChar;

    for (i = 0; i < 8; i++) {
        stack[i] = 0;
    }

    printf("<---------- CALCULADORA RPN ---------->\n");

    do {
        printStack();
        printf("\n");
        printOptionsMenu();
        scanf("%d", &opc);

        switch (opc) {
        case 1:
            printf("\033[2J");
            printStack();
            printf("\nIngrese el número: ");
            scanf("%f", &num);
            moveStackUp();
            stack[7] = num;
            printf("\033[2J");
            break;
        case 2:
            printf("\033[2J");
            printStack();
            printf("+, -, *, /, r(raíz cuadrada), s(seno), c(coseno), t(tangante), p(potencia)\n");
            scanf(" %c", &opChar);
            operation(opChar);
            break;
        case 3:
            printf("\033[2J");
            clearLast();
            break;
        case 4:
            printf("\033[2J");
            clearAll();
            break;
        case 5:
            printf("\033[2J");
            break;
        default:
            printf("\033[2J");
            printf("Ingrese una opción valida\n");
            break;
        }
    } while (opc != 5);

    return 0;
}

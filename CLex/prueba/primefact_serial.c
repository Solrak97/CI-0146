/*
* Copyright 2021 Jey Caleb Ruiz Pinel
*/
#include "primefact_serial.h"

/*Revisa si el numero ingresado es primo*/
int isPrime(int64_t number) {
    int isPrime = 1;
    for (int iterator = 2; iterator <= sqrt(number); iterator++) {
        if ((number%iterator) == 0) {
            isPrime = 0;
            break;
        }
    }
    return isPrime;
}

/*Revisa si el numero ingresado es un numero primo o compuesto*/
void primefact_serial(int64_t number){
    if(isPrime(number)==1){
        primefact_prime(number);
    }else{
        primefact_composite(number);
    }
}

/*Imprime el mismo numero el cual se trata de la factorizacion
del numero primo*/
void primefact_prime(int64_t number){
    printf("%ld:%ld\n", number, number);
}

/*Adaptado de https://www.youtube.com/watch?v=DHLao_2sjnY*/
void primefact_composite(int64_t number){
    /*Se crea una copia del numero, se inicializa el divisor en 2 y se 
    crea una variable para contar las veces que se utiliza el divisor 
    dentro de un ciclo*/
    int64_t number_copy = number;
    int64_t divider = 2;
    int64_t exponent_counter = 0;
    /*Se imprime el numero que vamos a factorizar para acomdar 
    la salida*/
    printf("%ld:", number_copy);
    /*Se inicia un ciclo mientras que el numero sea diferente a 1*/
    while(number_copy!=1){
        /*Se comprueba si el numero actual se puede dividir 
        entre el divisor actual sin residuo*/
        if(number_copy%divider == 0){
            /*Se hace un ciclo para ir diviendo el numero
            entre el divisor y asi obtener la factorizacion*/
            while (number_copy%divider == 0)
            {
                exponent_counter++;
                number_copy = number_copy / divider;
            }
            /*Si el exponente se utilizo mas de una vez se imprime
            el divisor elevado por el exponente*/
            if(exponent_counter > 1){
            printf(" %ld ^ %ld", divider, exponent_counter);
            } else{
            /*Imprime solo el divisor */
                printf(" %ld", divider);
            }
        }
        /*Se reinicia el contador a 0 y se aumenta el divisor*/
        exponent_counter = 0;
        divider++;
    }
    printf("\n");
}
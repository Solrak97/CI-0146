/*
* Copyright 2021 Jey Caleb Ruiz Pinel
*/
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * @brief Metodo para saber si un numero es primo o no
 * @param number El numero que se va a calcular si es primo o no (no funciona con caracteres)
 * @return 1 si el numero es primo o 0 si el numero no es primo 
*/
int isPrime(int64_t number);
/**
 * @brief Metodo para saber si un numero es par o impar
 * @param number El numero del que se va a calcular si es par o impar (no funciona con caracteres)
 * @return 1 si el numero es par o 0 si el numero no es impar 
*/
int isEven(int64_t number);
/**
 * @brief Metodo para aplicar goldbach a un numero par
 * @param number El numero al que se le va a aplicar goldbach
 * @return La cantidad de sumas de numeros impares en las que se puede expresar el numero recibido
*/
int goldbachEven(int64_t number);
/**
 * @brief Metodo para aplicar goldbach a un numero impar
 * @param number El numero al que se le va a aplicar goldbach
 * @return La cantidad de sumas de numeros impares en las que se puede expresar el numero recibido
*/
int goldbachOdd(int64_t number);
/**
 * @brief Metodo para saber si la conjetura de goldbach se va a aplicar a un numero par o impar
 * @param number El numero al que se le va a aplicar goldbach
 * @return La cantidad de sumas de numeros impares en las que se puede expresar el numero recibido
*/
int goldbachSerial(int64_t number);

int main(void) {
    int64_t n;
    FILE* input = stdin;
    FILE* output = stdout;

    size_t arrNums_size = 1;
    int64_t* arrNums = calloc(arrNums_size, sizeof(int64_t));

    while (fscanf(input, "%ld", &n) == 1) {
        arrNums[arrNums_size-1] = n;
        arrNums_size++;
        arrNums = realloc(arrNums, arrNums_size * sizeof(int64_t));
    }
    fprintf(output, "\n");

    for (size_t arrNums_pos = 0; arrNums_pos < arrNums_size; arrNums_pos++) {
        if (arrNums[arrNums_pos] < -5 || arrNums[arrNums_pos] > 5) {
            fprintf(output, "%ld: %d sums\n", arrNums[arrNums_pos],
            goldbachSerial(arrNums[arrNums_pos]));
        } else {
            fprintf(output, "%ld: NA\n", arrNums[arrNums_pos]);
        }
    }
    free(arrNums);
    return 0;
}

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

int isEven(int64_t number) {
    int isEven = 1;
    if ((number % 2) != 0) {
        isEven = 0;
    }
    return isEven;
}

int goldbachEven(int64_t number) {
    int sum = 0;
    int numberCopy = number;
    int absoluteNumber = abs(numberCopy);
    for(int leftPrime = 2, rightPrime = absoluteNumber - leftPrime; 
    rightPrime >= leftPrime; leftPrime++, rightPrime--) {
        if(isPrime(leftPrime) == 1 && isPrime(rightPrime) == 1) {
            if(number < 0) {
                printf(" %d + %d," , leftPrime, rightPrime);
            }
            sum++;
        }
    }
    return sum;
}

int goldbachOdd(int64_t number) {
    int sum = 0;
    int numberCopy = number;
    int absoluteNumber = abs(numberCopy);
    for (int firstPivot = 2; firstPivot < (absoluteNumber/2); firstPivot++) {
        for (int secondPivot = firstPivot; secondPivot < absoluteNumber; secondPivot++) {
            for (int thirdPivot = secondPivot; thirdPivot < absoluteNumber; thirdPivot++) {
                if(isPrime(firstPivot) == 1 && isPrime(secondPivot) == 1 && isPrime(thirdPivot) == 1
                    && (firstPivot + secondPivot + thirdPivot) == absoluteNumber) {
                        if(number < 0) {
                            printf(" %d + %d + %d," , firstPivot, secondPivot, thirdPivot);
                        }
                        sum++;
                }
            }
        }
    }
    return sum;
}

int goldbachSerial(int64_t number){
    int sum = 0;
    if(isEven(number) == 1) {
        sum = goldbachEven(number);
    } else {
        sum = goldbachOdd(number);
    }
    return sum;
}
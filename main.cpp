// Autor: Deyan Sanabria Fallas

#include <iostream>
#include <string.h>

#define ARRAY_START 0

using namespace std;

// EJERCICIO COMPLETE THE TRIPLETS

/*
Algoritmo inefficiente: En este algoritmo se hacen solamente con el for, 4 comparaciones, 3 incrementos
de la variable "i", con el resto del cuerpo, en el peor de los caso se hacen 6 comparaciones con los if
y 3 incrementos al score. En total hay 10 comparaciones y 6 incrementos o operaciones aritmeticas
*/
void inefficientTriplets(int *alice, int *bob, int *score) {
    for(int i = ARRAY_START; i < 3; i++) {
        if(alice[i] > bob[i]) {
            score[0]++;
        } else if(alice[i] < bob[i]) {
            score[1]++;
        }
    }
}

/*
Algoritmo eficiente: En este algoritmo se elimina el ciclo For, por lo que se llega a ahorrar en comparaciones
para un total de 3 comparaciones y 11 operaciones aritmetiicas en el peor de los casos, logrando una gran
disminucion de comparaciones y aumentando las operaciones aritmeticas.
*/
void efficientTriplets(int *alice, int *bob, int *score) {
    int puntaje;
    if(alice[0]!=bob[0]) {
        puntaje = (alice[0]-bob[0])/abs((alice[0]-bob[0]));
        score[0] += (puntaje+1);
        score[1] += (puntaje-1);
    }
    if(alice[1]!=bob[1]) {
        puntaje = (alice[1]-bob[1])/abs((alice[1]-bob[1])); 
        score[0] += (puntaje+1);
        score[1] += (puntaje-1);

    }
    if(alice[2]!=bob[2]) {
        puntaje = (alice[2]-bob[2])/abs((alice[2]-bob[2])); 
        score[0] += (puntaje+1);
        score[1] += (puntaje-1);
    }
    score[0] /= 2;
    score[1] /= -2;
}

// EJERCICIO TIME CONVERSION

/*
Algoritmo ineficiente: este algoritmo ineficiente tiene 3 comparaciones dentro de un if y
una de esas comparaciones es compuesta, ademas se obtiene un substring extra que contiene 
el AM o PM de la hora, lo cual es innecesario debido a que solo se necesita una letra y se 
puede obtener usando indices
*/
string inefficientTime(string twelveFormat){
    string militaryFormat;
    int hour = stoi(twelveFormat.substr(0,2));
    string ampm = twelveFormat.substr(8);
    if(hour == 12 && ampm =="AM") {
        hour = 0;
    } else if (ampm == "PM") {
        hour += 12;
    }
    if(hour<10) {
        militaryFormat = "0" + to_string(hour) + twelveFormat.substr(2,6);
    } else {
        militaryFormat = to_string(hour) + twelveFormat.substr(2,6);
    }
    return militaryFormat;
    
}


/*
Algoritmo eficiente: en este caso solo hay 2 comparaciones (en un if y un if ternario) 
y el resto se reemplazo por operaciones aritmeticas, ademas se omitio obtener un substring
completo del AM y PM y solo se uso la letra A o P para la comparacion
*/
string efficientTime(string twelveFormat) {
    string militaryFormat;
    int hour = stoi(twelveFormat.substr(0,2));
    int offset = (hour%12/hour);

    if(twelveFormat[8] == 'A')
        offset--;

    hour += (12*offset);
    militaryFormat = hour<10 ? "0" + to_string(hour) + twelveFormat.substr(2,6) :
                               to_string(hour) + twelveFormat.substr(2,6);
    
    return militaryFormat;
}

// EJERCIO SUBARRAY DIVISION

/*
Algoritmo ineficiente: en este caso el algoritmo se realiza en base a dos for anidados, el inicial se
dedica a recorrer el arreglo y el de adentro suma al numero en el indice actual los siguientes n
numeros del arreglo, siendo n = mes - 1 y asegurandose que el primer for no pase por los ultimos
elementos del arreglo, porque el for de adentro intentaria leer los proximos numeros y si no existen
se cae el programa. Para un array de 7 elementos y que el mes sea 3, hay 18 comparaciones en los ciclos
For y otras 5 comparaciones por un if, para un total de 23 comparaciones y muchos ciclos innecesarios
debido a que las operaciones aritmeticas se repiten ya que el arreglo va avanzando uno a uno
y cada numero anterior ya se sumo con los tres siguientes numeros y esta suma se reinicia cada
que se pasa de numero en el arreglo.
*/
int inefficientDivision(int arraySize, int *array, int day, int month) {
    int numberOfDivisions = 0;
    int sum;
    arraySize = arraySize - (month - 1);
    for(int i = ARRAY_START; i < arraySize; i++) {
        sum = 0;
        for(int j = 0; j < month; j++) {
            sum += array[i+j];
        }
        if(sum == day) {
            numberOfDivisions++;
        }
    }
    return numberOfDivisions;
}

/*
Algoritmo eficiente: A comparacion del algoritmo anterior, este algoritmo no tiene un for anidado. Para un
array de 7 elementos y que el mes sea 3, este algoritmo tiene 22 comparaciones, una menos a comparacion del otro
pero lo interesante esta en las operaciones aritmeticas, las cuales se disminuyen puest a que solo se realiza una
suma y una resta cada vez que se avanza al siguiente elemento del arreglo, mientras que antes cada que se avanzaba
en el arreglo, se volvian a sumar numeros desde 0, para este caso que son 3 meses, se hacian 3 sumas denuevo
*/

int efficientDivision(int arraySize, int *array, int day, int month) {
    int numberOfDivisions = 0;
    int sum = 0;
    month--;
    for(int i = ARRAY_START; i < arraySize; i++) {
        sum += array[i];
        if(i < month) {
            continue;
        }
        if(sum == day) {
            numberOfDivisions++;
        }
        sum -= array[i-month];
    }
    return numberOfDivisions;
}

int main(){
    cout << "--------- " << "EJERCICIO 1: COMPARE THE TRIPLETS" << " ---------" << endl;
    cout << "Primer prueba: Alicie tiene un puntaje de 17, 28 y 30 | Bob tiene un puntaje de 99, 16 y 8" << endl;
    int alice[] = {17,28,30};
    int bob[] = {99,16,8};
    int score[] = {0,0};
    efficientTriplets(alice,bob,score);
    cout << "Para un resultado de: Alicie con un score de: " << score[0];
    cout << " | Bob con un score de: " << score[1] << endl;

    cout << "\nSegunda prueba: Alicie tiene un puntaje de 50, 60 y 70 | Bob tiene un puntaje de 30, 60 y 100" << endl;
    int alice2[] = {50,60,70};
    int bob2[] = {30,60,100};
    int score2[] = {0,0};
    efficientTriplets(alice2,bob2,score2);
    cout << "Para un resultado de: Alicie con un score de: " << score2[0];
    cout << " | Bob con un score de: " << score2[1] << endl;

    cout << "\n--------- " << "EJERCICIO 2: TIME CONVERSION" << " ---------" << endl;
    cout << "Primera prueba: convertir 12:23:45AM a formato militar" << endl;
    cout << "La conversion quedo como: " << efficientTime("12:23:45AM") << endl;

    cout << "\nSegunda prueba: convertir 04:05:01PM a formato militar" << endl;
    cout << "La conversion quedo como: " << efficientTime("04:05:01PM") << endl;

    cout << "\nTercera prueba: convertir 08:15:25AM a formato militar" << endl;
    cout << "La conversion quedo como: " << efficientTime("08:15:25AM") << endl;

    cout << "\n--------- " << "EJERCICIO 3: SUBARRAY DIVISION" << " ---------" << endl;
    cout << "Primera prueba: Lily tiene un chocolate con los numeros 1, 2, 1, 3 y 2 | Ron cumple el dia 3 del mes 2" << endl;

    int chocolate[] = {1, 2, 1, 3, 2};
    cout << "Lily puede dividir el chocolate en: " << efficientDivision(5,chocolate,3,2) << endl;

    cout << "\nSegunda prueba: Lily tiene un chocolate con los numeros 3, 7, 8, 2, 10 y 0 | Ron cumple el dia 10 del mes 2" << endl;

    int chocolate2[] = {3, 7, 8, 2, 10, 0};
    cout << "Lily puede dividir el chocolate en: " << efficientDivision(6,chocolate2,10,2) << endl;

    return 0;
}
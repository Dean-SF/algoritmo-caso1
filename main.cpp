// Autor: Deyan Sanabria Fallas

#include <iostream>
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

int main(){
    cout << "--------- " << "EJERCICIO 1: COMPARE THE TRIPLETS" << " ---------" << endl;
    cout << "Primer prueba: Alicie tiene un puntaje de 17, 28 y 30 | Bob tiene un puntaje de 99, 16 y 8" << endl;
    int alice[] = {17,28,30};
    int bob[] = {99,16,8};
    int score[] = {0,0};
    efficientTriplets(alice,bob,score);
    cout << "Para un resultado de: Alicie con un score de: " << score[0];
    cout << " | Bob con un score de: " << score[1] << endl;

    cout << "Segunda prueba: Alicie tiene un puntaje de 50, 60 y 70 | Bob tiene un puntaje de 30, 60 y 100" << endl;
    int alice2[] = {50,60,70};
    int bob2[] = {30,60,100};
    int score2[] = {0,0};
    efficientTriplets(alice2,bob2,score2);
    cout << "Para un resultado de: Alicie con un score de: " << score2[0];
    cout << " | Bob con un score de: " << score2[1] << endl;

    return 0;
}
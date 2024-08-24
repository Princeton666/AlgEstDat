// Calculadora.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.


#include <iostream>

using namespace std;

float sumar(float a, float b) { return a + b; }
float restar(float a, float b) { return a - b; }
float multiplicacion(float a, float b) { return a * b; }
float division(float a, float b) { return a / b; }

int main() {
    float a, b, c;
    int opt;

    cout << "Ingresar los a y b respectivamente:" << endl;
    cin >> a >> b;
    cout << "Ingresar la operacion 0 sumar , 1 restar , 2 multiplicar , 3 division" << endl;
    cin >> opt;


    float (*operations[])(float, float) = { sumar, restar, multiplicacion, division };

    if (opt >= 0 && opt < 4) {
        c = operations[opt](a, b);
        cout << "Resultado: " << c << endl;
    }
    else {
        cout << "Operación no válida." << endl;
    }

    return 0;
}
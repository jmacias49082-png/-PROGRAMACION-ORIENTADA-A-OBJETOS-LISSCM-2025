#include "SegundaTarea.h"
#include <iostream>
using namespace std;

// posiciones pares = false, impares = true
void procesar(bool arr[], int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = (i % 2 == 1);
    }
}

// aplica %2 a cada número usando punteros
void procesar(int* arr, int n) {
    int* p = arr;
    for (int i = 0; i < n; ++i) {
        *p = (*p) % 2;
        cout << "direccion=" << static_cast<const void*>(p)
            << "  valor=" << *p << '\n';
        ++p;
    }
}

void imprimirBool(const bool arr[], int n) {
    cout << "{ ";
    for (int i = 0; i < n; ++i) {
        cout << (arr[i] ? "true" : "false");
        if (i < n - 1) cout << ", ";
    }
    cout << " }\n";
}

void imprimirInt(const int arr[], int n) {
    cout << "{ ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << " }\n";
}

void MainSegundaTarea() {
    bool banderas[5] = { true, true, true, true, true };
    cout << "Booleanos antes: ";
    imprimirBool(banderas, 5);

    procesar(banderas, 5);

    cout << "Booleanos despues: ";
    imprimirBool(banderas, 5);

    cout << '\n';

    int numeros[10];
    for (int i = 0; i < 10; ++i) numeros[i] = i;

    cout << "Enteros antes: ";
    imprimirInt(numeros, 10);

    cout << "Aplicando %2 y mostrando direccion/valor:\n";
    procesar(numeros, 10);

    cout << "Enteros despues: ";
    imprimirInt(numeros, 10);
}

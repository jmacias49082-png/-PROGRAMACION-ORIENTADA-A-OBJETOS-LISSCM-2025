#include "SegundaTarea.h"
#include <iostream>
using namespace std;

// Posiciones pares = false, impares = true
void Procesar(bool arr[], int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = (i % 2 == 1);
    }
}

// Aplica %2 a cada numero usando punteros y muestra direccion/valor
void Procesar(int* arr, int n) {
    int* p = arr;
    for (int i = 0; i < n; ++i) {
        *p = (*p) % 2;
        cout << "direccion=" << static_cast<const void*>(p)
            << "  valor=" << *p << '\n';
        ++p;
    }
}

void ImprimirBool(const bool arr[], int n) {
    cout << "{ ";
    for (int i = 0; i < n; ++i) {
        cout << (arr[i] ? "true" : "false");
        if (i < n - 1) cout << ", ";
    }
    cout << " }\n";
}

void ImprimirInt(const int arr[], int n) {
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
    ImprimirBool(banderas, 5);

    Procesar(banderas, 5);

    cout << "Booleanos despues: ";
    ImprimirBool(banderas, 5);

    cout << '\n';

    int numeros[10];
    for (int i = 0; i < 10; ++i) numeros[i] = i;

    cout << "Enteros antes: ";
    ImprimirInt(numeros, 10);

    cout << "Aplicando %2 y mostrando direccion/valor:\n";
    Procesar(numeros, 10);

    cout << "Enteros despues: ";
    ImprimirInt(numeros, 10);

    /* Referencias (Tarea 2):
       - Arrays en C++ (arreglos basicos): https://www.youtube.com/watch?v=og-ENx-GwPQ
       - Punteros y arrays en C++: https://www.youtube.com/watch?v=mlTjAmqtNA8
       - Sobrecarga de funciones en C++: https://www.youtube.com/watch?v=w8CihmJHGWc
    */
}

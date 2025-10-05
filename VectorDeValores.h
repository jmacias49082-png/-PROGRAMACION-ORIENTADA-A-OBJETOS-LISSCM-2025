#pragma once

// Declaraci�n de la estructura VectorDeValores.
// Una estructura simple para manejar un arreglo din�mico de flotantes.
struct VectorDeValores
{
    // Puntero que apuntar� al primer elemento de nuestro arreglo en memoria din�mica (Heap).
    float* valores;
    // Variable para saber cu�ntos elementos tiene nuestro arreglo.
    int tamanio;
    // Constructor por defecto: crea un vector con valores predeterminados.
    VectorDeValores();
    // Constructor parametrizado: crea un vector a partir de un arreglo existente.
    VectorDeValores(float arr[], int tam);
    // Destructor: su trabajo es liberar la memoria que pedimos para evitar fugas (memory leaks).
    ~VectorDeValores();
};

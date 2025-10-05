#pragma once

// Declaración de la estructura VectorDeValores.
// Una estructura simple para manejar un arreglo dinámico de flotantes.
struct VectorDeValores
{
    // Puntero que apuntará al primer elemento de nuestro arreglo en memoria dinámica (Heap).
    float* valores;
    // Variable para saber cuántos elementos tiene nuestro arreglo.
    int tamanio;
    // Constructor por defecto: crea un vector con valores predeterminados.
    VectorDeValores();
    // Constructor parametrizado: crea un vector a partir de un arreglo existente.
    VectorDeValores(float arr[], int tam);
    // Destructor: su trabajo es liberar la memoria que pedimos para evitar fugas (memory leaks).
    ~VectorDeValores();
};

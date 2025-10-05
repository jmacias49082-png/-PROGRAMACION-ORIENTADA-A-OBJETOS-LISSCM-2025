#include "VectorDeValores.h"
#include <iostream> 

using namespace std;

//  Definiciones de los métodos de VectorDeValores 

// Implementación del constructor por defecto.
VectorDeValores::VectorDeValores()
{
    tamanio = 2; // Tamaño por defecto como se pidió en la tarea.
    valores = new float[tamanio]; // Pedimos memoria para 2 flotantes.

    // Inicializamos los valores para que no contengan "basura".
    valores[0] = 0.0f;
    valores[1] = 0.0f;

    cout << "Constructor por defecto de VectorDeValores llamado. Se creo un vector de " << tamanio << " elementos."
        << endl;
}

// Implementación del constructor que recibe un arreglo.
VectorDeValores::VectorDeValores(float arr[], int tam)
{
    // Chequeo de seguridad: No se permite crear un vector con tamaño 0 o negativo.
    if (tam <= 0)
    {
        cout << "ERROR: Constructor de VectorDeValores llamado con tam = " << tam << ". Estableciendo tamaño por defecto (2)." << endl;
        tamanio = 2;
        valores = new float[tamanio];
        valores[0] = 0.0f;
        valores[1] = 0.0f;
    }
    else
    {
        tamanio = tam;
        // Solicitamos memoria nueva del tamaño requerido.
        valores = new float[tamanio];
        // Copiamos los elementos del arreglo que nos pasaron a nuestra nueva memoria.
        for (int i = 0; i < tamanio; ++i)
        {
            valores[i] = arr[i];
        }
    }

    cout << "Constructor parametrizado de VectorDeValores llamado. Se creo un vector de " << tamanio << " elementos."
        << endl;
}

// Implementación del destructor.
VectorDeValores::~VectorDeValores()
{
    // Chequeo de seguridad: solo liberamos la memoria si el puntero no es nulo.
    if (valores != nullptr)
    {
        cout << "Destructor de VectorDeValores llamado. Se liberaron " << tamanio << " elementos."
            << endl;

        // Usamos delete[] porque la memoria se pidió con new float[tamanio].
        delete[] valores;
        // Buena práctica: después de liberar la memoria, apuntamos a nullptr
        // para evitar que el puntero quede "colgando" (dangling pointer).
        valores = nullptr;
    }
    else
    {
        cout << "Destructor de VectorDeValores llamado. No se libero memoria dinámica (valores era nullptr)." << endl;
    }
}
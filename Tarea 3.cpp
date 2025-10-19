#include "Tarea3.h"
#include "Templates.h"
#include "DynamicArray.h"
#include "LinkedList.h"
#include <iostream> 

using namespace std;


// Función de prueba para el Ejercicio 0 (Templates)
void ProbarTemplates()
{
    cout << "\n PRUEBA EJERCICIO 0: TEMPLATES (PrintArray) " << endl;

    // Prueba con Enteros
    int arrInt[] = { 1, 2, 3, 4, 5 };
    cout << "Arreglo de Enteros: ";
    PrintArray(arrInt, 5);

    // Prueba con Floats
    float arrFloat[] = { 1.1f, 2.2f, 3.3f };
    cout << "Arreglo de Floats: ";
    PrintArray(arrFloat, 3);
}

// Función de prueba para el Ejercicio 1 (DynamicArray)
void ProbarDynamicArray()
{
    cout << "\n PRUEBA EJERCICIO 1: DYNAMIC ARRAY " << endl;

    DynamicArray<int> myDynamicArray;

    // Prueba de push_back (y #if de copias)
    cout << "Probando push_back (Resize):" << endl;
    myDynamicArray.push_back(10); // Resize a 1 (1 copia)
    myDynamicArray.push_back(20); // Resize a 2 (1 copia)
    myDynamicArray.push_back(30); // Resize a 4 (2 copias)
    cout << "Despues de 3 push_back(): ";
    myDynamicArray.Print(); // Imprime: 10, 20, 30,

    // Prueba de Sobrecarga de Operador [] (Lectura)
    cout << "myDynamicArray[0] debe imprimir 10: " << myDynamicArray[0] << endl;

    // Prueba de Sobrecarga de Operador [] (Escritura)
    myDynamicArray[1] = 1984;
    cout << "Despues de myDynamicArray[1] = 1984: ";
    myDynamicArray.Print(); // Imprime: 10, 1984, 30,

    // Prueba de pop_back
    myDynamicArray.pop_back();
    cout << "Despues de pop_back(): ";
    myDynamicArray.Print(); // Imprime: 10, 1984,

    myDynamicArray.shrink_to_fit();
    cout << "Llamada a shrink_to_fit() (sin salida)." << endl;
}

// Función de prueba para el Ejercicio 2 (LinkedList)
void ProbarLinkedList()
{
    cout << "\n PRUEBA EJERCICIO 2: LINKED LIST " << endl;
    { // Se crea un scope para probar el destructor
        LinkedList<int> myList;

        myList.push_front(10);
        myList.push_front(20);
        myList.push_front(30);
        cout << "Despues de 3 push_front(30, 20, 10): ";
        myList.Print(); // Imprime: 30 -> 20 -> 10 -> nullptr

        myList.pop_front();
        cout << "Despues de pop_front(): ";
        myList.Print(); // Imprime: 20 -> 10 -> nullptr

        // La función Clear() se llamará automáticamente aquí
        cout << "Saliendo del scope de myList... El destructor debe llamarse ahora." << endl;
    } // El destructor de myList llama a Clear() aquí.
    cout << "myList destruida." << endl;
}


// Función principal llamada por main.cpp
void MainTarea3()
{
    ProbarTemplates();
    ProbarDynamicArray();
    ProbarLinkedList();
}
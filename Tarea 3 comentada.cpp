#include "Tarea3.h"
#include "Templates.h"
#include "DynamicArray.h"
#include "LinkedList.h"
#include <iostream> 

using namespace std;

// Prueba para el Ejercicio 0 (Templates)
void ProbarTemplates()
{
    // Título limpio
    cout << "\nPRUEBA EJERCICIO 0: TEMPLATES (PrintArray)" << endl;

    int arrInt[] = { 1, 2, 3, 4, 5 };
    cout << "Arreglo de Enteros: ";
    PrintArray(arrInt, 5); // Prueba con ints

    float arrFloat[] = { 1.1f, 2.2f, 3.3f };
    cout << "Arreglo de Floats: ";
    PrintArray(arrFloat, 3); // Prueba con floats
}

// Prueba para el Ejercicio 1 (DynamicArray)
void ProbarDynamicArray()
{
    cout << "\nPRUEBA EJERCICIO 1: DYNAMIC ARRAY" << endl;

    DynamicArray<int> myDynamicArray; // Uso el template con <int>

    cout << "Probando push_back (Resize):" << endl;
    myDynamicArray.push_back(10); // Llama a Resize(1)
    myDynamicArray.push_back(20); // Llama a Resize(2)
    myDynamicArray.push_back(30); // Llama a Resize(4)
    cout << "Despues de 3 push_back(): ";
    myDynamicArray.Print();

    // Prueba de la sobrecarga de []
    cout << "myDynamicArray[0] debe imprimir 10: " << myDynamicArray[0] << endl;

    myDynamicArray[1] = 1984; // Prueba de escritura con []
    cout << "Despues de myDynamicArray[1] = 1984: ";
    myDynamicArray.Print();

    // Prueba de pop_back
    myDynamicArray.pop_back();
    cout << "Despues de pop_back(): ";
    myDynamicArray.Print();

    myDynamicArray.shrink_to_fit(); // Prueba de shrink (ya implementada)
    cout << "Llamada a shrink_to_fit() (revisa el DEBUG de copias)." << endl;
}

// Prueba para el Ejercicio 2 (LinkedList)
void ProbarLinkedList()
{
    cout << "\nPRUEBA EJERCICIO 2: LINKED LIST" << endl;

    // Creo un scope (bloque con { }) para probar el destructor
    {
        LinkedList<int> myList;

        // Prueba de push_front
        myList.push_front(10);
        myList.push_front(20);
        myList.push_front(30);
        cout << "Despues de 3 push_front(30, 20, 10): ";
        myList.Print();

        // Prueba de pop_front
        myList.pop_front();
        cout << "Despues de pop_front(): ";
        myList.Print();

        cout << "Saliendo del scope de myList... El destructor debe llamarse ahora." << endl;
    } // Aquí se destruye 'myList' y debe llamar a ~LinkedList(), que llama a Clear().
    cout << "myList destruida." << endl;
}


// Esta es la función principal que llama 'main.cpp'
void MainTarea3()
{
    ProbarTemplates();
    ProbarDynamicArray();
    ProbarLinkedList();
}
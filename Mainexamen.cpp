// Main.cpp

#include "EjerciciosTarea.h" // �CORREGIDO! Necesario para declarar las funciones MainEjercicio...
#include <iostream>        // �CORREGIDO! Necesario para usar std::cout y std::cin.get()

// Rol del archivo main.cpp:
// Este archivo es el punto de entrada de la aplicaci�n. Su �nica responsabilidad,
// como se pidi� en las instrucciones, es llamar a las funciones principales
// que contienen las pruebas de cada ejercicio.
int main()
{
    // Llamada a la funci�n que prueba la estructura VectorDeValores.
    MainEjercicioEstructuras();

    // Llamada a la funci�n que prueba la clase Rect.
    MainEjercicioClases();

    // Llamada a la funci�n que demuestra el uso de memoria din�mica.
    MainEjercicioMemoriaDinamica();

    // Peque�a pausa para que la ventana de la consola no se cierre inmediatamente
    // al terminar la ejecuci�n y podamos ver los resultados.
    std::cout << "Presiona Enter para finalizar el programa..." << std::endl;
    std::cin.get();

    return 0; // Indica que el programa termin� exitosamente.
}
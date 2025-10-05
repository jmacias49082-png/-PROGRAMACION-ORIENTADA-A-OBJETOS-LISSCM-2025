#include "EjerciciosTarea.h"
#include "VectorDeValores.h"
#include "Rect.h"
#include <iostream>

using namespace std;

void MainEjercicioEstructuras()
{
    cout << "--- INICIO EJERCICIO ESTRUCTURAS ---" << endl;
    cout << "\nProbando constructor por defecto:" << endl;
    VectorDeValores v1;
    cout << "Valores de v1: " << v1.valores[0] << ", " << v1.valores[1] << endl;
    cout << "\nProbando constructor parametrizado:" << endl;
    float miArray[] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f };
    int tam = sizeof(miArray) / sizeof(float);
    VectorDeValores v2(miArray, tam);
    cout << "Valores de v2: ";
    for (int i = 0; i < v2.tamanio; ++i)
    {
        cout << v2.valores[i] << " ";
    }
    cout << endl;

    cout << "\nLas instancias v1 y v2 seran destruidas automaticamente al salir de esta funcion."
        << endl;
    cout << "--- FIN EJERCICIO ESTRUCTURAS ---\n" << endl;
}

void MainEjercicioClases()
{
    cout << "--- INICIO EJERCICIO CLASES ---" << endl;
    cout << "\nProbando constructores de Rect (unificados):" << endl;

    // 1. Llama al constructor por defecto: Rect(0, 0, 0, 0)
    Rect rectDefault;
    // 2. Llama al constructor completo: Rect(10, 20, 50, 100)
    Rect rectCompleto(10, 20, 50, 100);
    // 3. Llama al constructor parcial (Alto, Ancho): Rect(0, 0, 30, 40)
    Rect rectParcial(0, 0, 30, 40);

    cout << "\nRect Default: X=" << rectDefault.GetX() << ", Y=" << rectDefault.GetY() << ", Alto=" << rectDefault.GetAlto() << ", Ancho=" << rectDefault.GetAncho() << endl;
    cout << "Rect Completo: X=" << rectCompleto.GetX() << ", Y=" << rectCompleto.GetY() << ", Alto=" << rectCompleto.GetAlto() << ", Ancho=" << rectCompleto.GetAncho() << endl;
    cout << "Rect Parcial: X=" << rectParcial.GetX() << ", Y=" << rectParcial.GetY() << ", Alto=" << rectParcial.GetAlto() << ", Ancho=" << rectParcial.GetAncho() << endl;
    cout << "\nProbando funcion ImprimeCoordenadasYVerifica:" << endl;
    float xFin, yFin;
    if (rectCompleto.ImprimeCoordenadasYVerifica(rectCompleto, xFin, yFin))
    {
        cout << "La funcion regreso TRUE. Coordenadas finales guardadas: (" << xFin << ", " << yFin << ")" << endl;
    }

    Rect rectNegativo(-1, 5, 5, 5);
    if (!rectCompleto.ImprimeCoordenadasYVerifica(rectNegativo, xFin, yFin))
    {
        cout << "La funcion regreso FALSE como se esperaba."
            << endl;
    }

    cout << "\nProbando funcion CheckOverlap:" << endl;
    Rect rA1(0, 0, 5, 5);
    Rect rB1(6, 6, 5, 5);
    if (rA1.CheckOverlap(rB1)) {
        cout << "Caso 1 (No traslape): Se traslapan (INCORRECTO)" << endl;
    }
    else {
        cout << "Caso 1 (No traslape): No se traslapan (CORRECTO)" << endl;
    }

    Rect rA2(0, 0, 5, 5);
    Rect rB2(2, 2, 2, 2);
    if (rA2.CheckOverlap(rB2)) {
        cout << "Caso 2 (Traslape): Se traslapan (CORRECTO)" << endl;
    }
    else {
        cout << "Caso 2 (Traslape): No se traslapan (INCORRECTO)" << endl;
    }

    Rect rA3(0, 0, 5, 5);
    Rect rB3(1, 1, 7.5, 2);
    if (rA3.CheckOverlap(rB3)) {
        cout << "Caso 3 (Traslape): Se traslapan (CORRECTO)" << endl;
    }
    else {
        cout << "Caso 3 (Traslape): No se traslapan (INCORRECTO)" << endl;
    }

    cout << "\nLos Rects seran destruidos automaticamente al salir de la funcion." << endl;
    cout << "--- FIN EJERCICIO CLASES ---\n" << endl;
}

void MainEjercicioMemoriaDinamica()
{
    cout << "--- INICIO EJERCICIO MEMORIA DINAMICA ---" << endl;
    float* punteroFloat = nullptr;
    cout << "3) Puntero inicializado a nullptr. Es la mejor practica para evitar punteros salvajes."
        << endl;

    punteroFloat = new float(7.77f);
    cout << "3.1) Se reserva memoria en el Heap para un float. Valor: " << *punteroFloat << endl;
    float variableStack = 6.66f;
    cout << "3.2) Se crea una variable local en el Stack. Valor: " << variableStack << endl;
    punteroFloat = &variableStack;
    cout << "3.3) Puntero ahora apunta a la direccion de la variable local. Valor: " << *punteroFloat << endl;
    cout << "3.4) Cuidado, acabas de causar un memory leak!" << endl;

    // CORRECCIÓN DEL ERROR DE SINTAXIS (COMILLAS)
    cout << "3.5) Es un 'memory leak' porque la memoria que pedimos con 'new' en el paso 3.1 ya no es accesible. "
        << "Perdimos la unica referencia que teniamos a esa direccion de memoria. "
        << "Para evitarlo, debimos llamar 'delete punteroFloat;' ANTES de reasignarlo." << endl;

    punteroFloat = new float(1984.0f);
    cout << "3.6) Se pide nueva memoria. El puntero ahora apunta a esta nueva direccion. Valor: " << *punteroFloat << endl;
    float* segundoPuntero = punteroFloat;
    cout << "3.7) 'segundoPuntero' copia la direccion de memoria de 'punteroFloat'. Ambos apuntan al mismo lugar."
        << endl;

    delete punteroFloat;
    punteroFloat = nullptr;
    cout << "3.8) Se libera la memoria a la que apuntaba 'punteroFloat' y se anula el puntero para seguridad."
        << endl;

    if (punteroFloat == nullptr)
    {
        cout << "3.9) 'punteroFloat' ahora es nullptr. Ya no apunta a la memoria liberada."
            << endl;
    }

    if (punteroFloat == NULL)
    {
        cout << "3.10) La comprobacion con NULL tambien funciona, aunque nullptr es la forma moderna en C++."
            << endl;
    }

    if (segundoPuntero != nullptr && segundoPuntero != NULL)
    {
        cout << "3.11) 'segundoPuntero' NO es nulo. Se ha convertido en un 'dangling pointer' o puntero colgante. "
            << "Todavia guarda la direccion de la memoria que ya fue liberada. Usarlo es peligroso y puede crashear el programa."
            << endl;
    }

    cout << "--- FIN EJERCICIO MEMORIA DINAMICA ---\n" << endl;
}
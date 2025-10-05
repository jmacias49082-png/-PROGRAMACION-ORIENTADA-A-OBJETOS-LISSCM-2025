#include "Rect.h"
#include <iostream>

using namespace std;

// --- Definiciones de los métodos de la clase Rect ---

// Definición del constructor unificado. NO lleva valores por defecto aquí.
Rect::Rect(float x, float y, float alto, float ancho)
{
    float valoresIniciales[4] = { x, y, alto, ancho };
    datos = new VectorDeValores(valoresIniciales, 4);

    // Lógica para imprimir el mensaje correcto según la llamada (propósito didáctico).
    if (x == 0.0f && y == 0.0f && alto == 0.0f && ancho == 0.0f) {
        cout << "Constructor por defecto/unificado de Rect llamado." << endl;
    }
    else if (x == 0.0f && y == 0.0f) {
        cout << "Constructor parcial/unificado (alto, ancho) de Rect llamado." << endl;
    }
    else {
        cout << "Constructor parametrizado/unificado (x, y, alto, ancho) de Rect llamado." << endl;
    }
}


Rect::~Rect()
{
    // Chequeo de seguridad: solo liberamos la memoria si el puntero no es nulo.
    if (datos != nullptr)
    {
        // Al usar 'delete' sobre el puntero 'datos', se invoca automáticamente el destructor de VectorDeValores.
        delete datos;
        cout << "Destructor de Rect llamado." << endl;
    }
    else {
        cout << "Destructor de Rect llamado. No se libero memoria dinámica (datos era nullptr)." << endl;
    }
}

// Implementación de los getters. ¡Deben ser const!
float Rect::GetX() const { return datos->valores[0]; }
float Rect::GetY() const { return datos->valores[1]; }
float Rect::GetAlto() const { return datos->valores[2]; }
float Rect::GetAncho() const { return datos->valores[3]; }

// Implementación de ImprimeCoordenadasYVerifica.
bool Rect::ImprimeCoordenadasYVerifica(const Rect& rectAAnalizar, float& out_xFinal, float& out_yFinal)
{
    float x = rectAAnalizar.GetX();
    float y = rectAAnalizar.GetY();
    float alto = rectAAnalizar.GetAlto();
    float ancho = rectAAnalizar.GetAncho();

    if (x < 0 || y < 0 || alto < 0 || ancho < 0)
    {
        cout << "Error: Uno de los campos del Rect es menor que 0." << endl;
        return false;
    }

    out_xFinal = x + ancho;
    out_yFinal = y + alto;
    cout << "Coordenadas del Rect:" << endl;
    cout << "  Punto de inicio: (" << x << ", " << y << ")" << endl;
    cout << "  Punto final: (" << out_xFinal << ", " << out_yFinal << ")" << endl;

    return true;
}

// Implementación de CheckOverlap con lógica de una sola condición.
bool Rect::CheckOverlap(const Rect& otroRect) const
{
    // Se verifica si NO HAY traslape. Si se cumple alguna condición de separación, regresamos false.

    if (this->GetX() >= otroRect.GetX() + otroRect.GetAncho() || // 1. COMPLETAMENTE a la DERECHA
        this->GetX() + this->GetAncho() <= otroRect.GetX() ||     // 2. COMPLETAMENTE a la IZQUIERDA
        this->GetY() >= otroRect.GetY() + otroRect.GetAlto() ||  // 3. COMPLETAMENTE ABAJO
        this->GetY() + this->GetAlto() <= otroRect.GetY())      // 4. COMPLETAMENTE ARRIBA
    {
        return false;
    }

    // Si no se cumplió ninguna condición de NO traslape, significa que SÍ hay traslape.
    return true;
}
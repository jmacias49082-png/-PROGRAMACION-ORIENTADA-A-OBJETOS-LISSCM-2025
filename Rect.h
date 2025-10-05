#pragma once
#include "VectorDeValores.h" // Incluimos la definición de nuestra estructura.
// Clase que representa un rectángulo en un espacio 2D.
class Rect
{
private:
    // Puntero a nuestra estructura para almacenar los 4 valores (X, Y, Alto, Ancho).
    VectorDeValores* datos;
public:
    // Constructor unificado: El constructor ahora usa valores por defecto.
    Rect(float x = 0.0f, float y = 0.0f, float alto = 0.0f, float ancho = 0.0f);

    // Destructor para liberar la memoria del objeto VectorDeValores.
    ~Rect();
    // Métodos "Get" (getters) para acceder a los valores de forma segura y legible desde fuera de la clase.
    // Los nombres usan PascalCase y son CONSTANTES.
    float GetX() const;
    float GetY() const;
    float GetAlto() const;
    float GetAncho() const;

    // Métodos de la clase.
    bool ImprimeCoordenadasYVerifica(const Rect& rectAAnalizar, float& out_xFinal, float& out_yFinal);
    bool CheckOverlap(const Rect& otroRect) const;
};
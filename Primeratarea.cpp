#include "Primeratarea.h"
#include <iostream>
#include <ctime>
using namespace std;

// Ajusta domingo(0)..sábado(6) a lunes(0)..domingo(6)
int diaLunesBase(int tm_wday) { return (tm_wday + 6) % 7; }

// Obtiene día/hora/minuto actuales (MSVC con localtime_s)
void obtenerAhora(int& dia, int& hora, int& minuto) {
    time_t t = time(nullptr);
    tm lt{};
    localtime_s(&lt, &t);
    dia = diaLunesBase(lt.tm_wday);
    hora = lt.tm_hour;
    minuto = lt.tm_min;
}

const char* nombreDia(int dia) {
    static const char* nombres[7] = { "lunes","martes","miercoles","jueves","viernes","sabado","domingo" };
    if (dia < 0 || dia > 6) return "dia invalido";
    return nombres[dia];
}

void esLunes(int dia) {
    if (dia == 0) cout << "Hoy es lunes\n";
}

void juevesAntesMediodia(int dia, int hora) {
    if (dia == 3 && hora < 12) cout << "Es jueves antes del mediodia\n";
}

void martesODespuesDeMediodia(int dia, int hora) {
    if (dia == 1) cout << "Hoy es martes\n";
    else if (hora >= 12) cout << "No es martes, pero ya paso el mediodia\n";
}

void recorrerSemana(int dia_actual) {
    for (int i = 0; i < 7; ++i) {
        const char* nd = nombreDia(i);
        if (i == dia_actual) cout << "Hoy SI es " << nd << '\n';
        else cout << "Hoy no es " << nd << '\n';
    }
}

void MainPrimeraTarea() {
    int dia, hora, minuto;
    obtenerAhora(dia, hora, minuto);

    cout << "[chequeo] Son las " << hora << ":"
        << (minuto < 10 ? "0" : "") << minuto
        << " y es " << nombreDia(dia) << ".\n\n";

    esLunes(dia);
    juevesAntesMediodia(dia, hora);
    martesODespuesDeMediodia(dia, hora);
    recorrerSemana(dia);
}

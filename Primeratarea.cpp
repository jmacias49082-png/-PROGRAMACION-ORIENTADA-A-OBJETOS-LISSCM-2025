#include "Primeratarea.h"
#include <iostream>
#include <ctime>
using namespace std;

// Ajusta domingo(0)..sabado(6) a lunes(0)..domingo(6)
int DiaLunesBase(int diaSemana) {
    return (diaSemana + 6) % 7;
}

// Obtiene dia/hora/minuto actuales (MSVC: localtime_s)
void ObtenerAhora(int& dia, int& hora, int& minuto) {
    time_t t = time(nullptr);
    tm lt{};
    localtime_s(&lt, &t);
    dia = DiaLunesBase(lt.tm_wday);
    hora = lt.tm_hour;
    minuto = lt.tm_min;
}

const char* NombreDia(int dia) {
    static const char* nombres[7] = {
        "lunes","martes","miercoles","jueves","viernes","sabado","domingo"
    };
    if (dia < 0 || dia > 6) return "dia invalido";
    return nombres[dia];
}

void EsLunes(int dia) {
    if (dia == 0) cout << "Hoy es lunes\n";
}

void JuevesAntesMediodia(int dia, int hora) {
    if (dia == 3 && hora < 12) cout << "Es jueves antes del mediodia\n";
}

void MartesODespuesDeMediodia(int dia, int hora) {
    if (dia == 1) cout << "Hoy es martes\n";
    else if (hora >= 12) cout << "No es martes, pero ya paso el mediodia\n";
}

void RecorrerSemana(int diaActual) {
    for (int i = 0; i < 7; ++i) {
        const char* nd = NombreDia(i);
        if (i == diaActual) cout << "Hoy SI es " << nd << '\n';
        else cout << "Hoy no es " << nd << '\n';
    }
}

void MainPrimeraTarea() {
    int dia, hora, minuto;
    ObtenerAhora(dia, hora, minuto);

    cout << "[chequeo] Son las " << hora << ":"
        << (minuto < 10 ? "0" : "") << minuto
        << " y es " << NombreDia(dia) << ".\n\n";

    EsLunes(dia);
    JuevesAntesMediodia(dia, hora);
    MartesODespuesDeMediodia(dia, hora);
    RecorrerSemana(dia);

    
}

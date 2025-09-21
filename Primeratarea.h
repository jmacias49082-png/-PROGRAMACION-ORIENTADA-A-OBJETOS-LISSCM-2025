#pragma once



int diaLunesBase(int tm_wday);
void obtenerAhora(int& dia, int& hora, int& minuto);
const char* nombreDia(int dia);
void esLunes(int dia);
void juevesAntesMediodia(int dia, int hora);
void martesODespuesDeMediodia(int dia, int hora);
void recorrerSemana(int dia_actual);
void MainPrimeraTarea();
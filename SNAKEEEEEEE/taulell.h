#pragma once
#include "const.h"
#include "utils.h"

//Inicialitzacio de funcions
void PomaRAND(char tablero[VERTICAL][HORIZONTAL], Position& poma);
void IniciarTablero(char tablero[VERTICAL][HORIZONTAL], Position& capSerp, Position& PosPOMA);
void PrinteoTablero(char tablero[VERTICAL][HORIZONTAL], int& Contador);
void Movimiento(Position& capSerp, bool& pressW, bool& pressA, bool& pressS, bool& pressD, char tablero[VERTICAL][HORIZONTAL], vector<Position>& VECTcosSerp);
bool Marges(Position& capSerp);
void CosSerp(char tablero[VERTICAL][HORIZONTAL], vector<Position>& VECTcosSerp);



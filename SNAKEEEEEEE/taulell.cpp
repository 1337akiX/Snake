#include "const.h"
#include "keyboard.h"
#include "utils.h"

//Randomitzem la posiio de la poma dintre els limits del taulell
void PomaRAND(char tablero[VERTICAL][HORIZONTAL], Position& poma) {
    poma.x = rand() % VERTICAL;
    poma.y = rand() % HORIZONTAL;
    tablero[poma.x][poma.y] = POMA;
}
//inicialitzem internament el taulell, la posicio del cap de la serp i la poma
void IniciarTablero(char tablero[VERTICAL][HORIZONTAL], Position& capSerp, Position& poma) {
    for (int i = 0; i < VERTICAL; i++) {
        for (int j = 0; j < HORIZONTAL; j++) {
            tablero[i][j] = ' ';
        }
    }
    capSerp.x = VERTICAL / 2;
    capSerp.y = HORIZONTAL / 2;
    tablero[capSerp.x][capSerp.y] = CAP_SERP;
    PomaRAND(tablero, poma);
}

void PrinteoTablero(char tablero[VERTICAL][HORIZONTAL], int& Contador) {
    cout << "PUNTOS: " << Contador << endl;
	//imprimim la part superior del taulell.
    for (int i = 0; i < HORIZONTAL + MARGES_EXTERIOR; i++) {
        cout << LIM_DE_ADALT_ABAIX;
    }
    cout << endl;

	//imprimim les dos parets laterals del taulell.
    for (int i = 0; i < VERTICAL; i++) {
        for (int j = 0; j < HORIZONTAL; j++) {
            if (j == 0) cout << LIM_COSTATS;
            cout << tablero[i][j];
            if (j == HORIZONTAL - 1) cout << LIM_COSTATS;
        }
        cout << endl;
    }
	//imprimim la part inferior del taulell.
    for (int i = 0; i < HORIZONTAL + MARGES_EXTERIOR; i++) {
        cout << LIM_DE_ADALT_ABAIX;
    }
    cout << endl;
}

void Movimiento(Position& capSerp, bool& pressW, bool& pressA, bool& pressS, bool& pressD, char tablero[VERTICAL][HORIZONTAL], vector<Position>& VECTcosSerp) {
	//Condicions per a que la serp no es mogui en diagonal, i perque no es pugui moure en la direccio oposada a la que es mou.
    if (IsWPressed() && !pressS) {
        pressW = true;
        pressA = false;
        pressS = false;
        pressD = false;
    }
    if (IsAPressed() && !pressD) {
        pressW = false;
        pressA = true;
        pressS = false;
        pressD = false;
    }
    if (IsSPressed() && !pressW) {
        pressW = false;
        pressA = false;
        pressS = true;
        pressD = false;
    }
    if (IsDPressed() && !pressA) {
        pressW = false;
        pressA = false;
        pressS = false;
        pressD = true;
    }

    if (!VECTcosSerp.empty()) {
        //Es mou desde el final cap a l'inici (es resta) per evitar sobrescriure els valors que encara no s'han mogut.
        for (int i = (VECTcosSerp.size() - 1); i > 0; i--) {
            VECTcosSerp[i] = VECTcosSerp[i - 1]; // imposem que la posicio del index del vector sigui una menys, aixi fara que es vaguin seguint el moviment amb la posicio que tenen davant
        //exemple si hem pillat la 1ra manzana -> vect[1]= vect[0] -> el primer cos, seguira el mov del cap de la serp.
        }
		VECTcosSerp[0] = capSerp; //la posicio d'index 0 del vector sempre sera el cap de la serp
    }
	//moviment de la serp, en funcio de les tecles que es premen.
    if (pressW) {
        capSerp.x--;
    }
    if (pressA) {
        capSerp.y--;
    }
    if (pressS) {
        capSerp.x++;
    }
    if (pressD) {
        capSerp.y++;
    }

    // Netegem el tauler eliminant tots els rastres deixats per la serp, de manera que només es manté la poma.
    for (int i = 0; i < VERTICAL; i++) {
        for (int j = 0; j < HORIZONTAL; j++) {
            if (tablero[i][j] != POMA) {
                tablero[i][j] = ' ';
            }
        }
    }
}
// Comprovem si el cap de la serp ha tocat les parets del taulell, si es així, retornem true.
bool Marges(Position& capSerp) {

    if (capSerp.x < 0) {
        return true;
    }
    else if (capSerp.y < 0) {
        return true;
    }
    else if (capSerp.x >= VERTICAL) {
        return true;
    }
    else if (capSerp.y >= HORIZONTAL) {
        return true;
    }
    return false;
}
// Iterem per cada posicio del VECTcosSerp i li assignem el valor de COS_SERP(x minuscula) segons les coordenades "x" y "y".
void CosSerp(char tablero[VERTICAL][HORIZONTAL], vector<Position>& VECTcosSerp) {
    for (Position& parte : VECTcosSerp) {
        tablero[parte.x][parte.y] = COS_SERP;
    }
}
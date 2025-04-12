- He cambiat el FRAMETIME a 100, perque a 150 era injugable.


- En aquesta funcio, he tingut que buscar aquesta forma del for amb IA:

// Iterem per cada posicio del VECTcosSerp i li assignem el valor de COS_SERP(x minuscula) segons les coordenades "x" i "y".
void CosSerp(char tablero[VERTICAL][HORIZONTAL], vector<Position>& VECTcosSerp) {
    for (Position& parte : VECTcosSerp) {
        tablero[parte.x][parte.y] = COS_SERP;
    }
}
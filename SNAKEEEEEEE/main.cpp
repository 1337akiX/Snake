#include "const.h"
#include "keyboard.h"
#include "utils.h"
#include "taulell.h"


int main() {
    srand(time(NULL));
    bool pressW = false;
    bool pressA = false;
    bool pressS = false;
    bool pressD = false;
    bool GameOver = false;
   
    int Contador = 0;
    char tablero[VERTICAL][HORIZONTAL];
    Position capSerp;
    Position poma;
    vector<Position> VECTcosSerp;
    
    IniciarTablero(tablero, capSerp, poma);
	//Mentres el joc no hagi acabat (que la funcio de Marges sigui false ), es va actualitzant el taulell i es va imprimint.
    while (!GameOver) {
        system("cls");
        PrinteoTablero(tablero, Contador);
        Movimiento(capSerp, pressW, pressA, pressS, pressD, tablero, VECTcosSerp);
        //si en algun moment marges es converteix en true, s'acabara el bucle del gameplay.
        GameOver = Marges(capSerp);
        if (GameOver) {
            break;
        }

        tablero[capSerp.x][capSerp.y] = CAP_SERP; //Marca cada frame, la posicio del cap de la serp
        CosSerp(tablero, VECTcosSerp);

		//COMPROVACIO DE SI LA POSICIO DEL CAP DE LA SERP ES IGUAL A LA POSICIO DE LA POMA.
        if (poma.x == capSerp.x && poma.y == capSerp.y) {
			Contador += POMA_COMIDA; //Sumem 1 punt per cada poma que es mengui
			VECTcosSerp.push_back({ capSerp.x, capSerp.y }); // SI LA POSICIO SON IGUALS, AFEGIM UN NOU VALOR AL VECTOR DARRERA DEL ULTIM VALOR DEL VECTOR, aquest valor tindra la mateixa posicio que el cap de la serp.
            PomaRAND(tablero, poma); //Tornem a cridar la funcio de la poma perque torni a aparèixer en una posicio aleatoria.
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_RATE));
    }
    system("cls");
    cout << "Has Morido, Tu Puntuacion: " << Contador<< endl;
    return 0;
}
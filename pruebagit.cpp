#include "iostream"
#include "string"
#include "ctime"
#include "cstdlib"
#include "unistd.h"
using namespace std;

//NUMERO YA MENCIONADO POR EL BOT YA NO VOLVERLO A DECIR
// Prototipo de función
bool yaColocado(int, int mat[3][3]);
bool tableroCompleto(int mat[3][3]);
void marcarNumero(int, int mat[3][3]);

int main(void)
{
    int opc;
    

do {
    cout << "Seleccione la opcion que desee: " << endl;
cout << "1. NUEVA PARTIDA" << endl;     
cout << "2. REGISTRO DE PARTIDAS" << endl; 
cout << "3. REGISTRO DE GANADORES" << endl; 
cout << "4. INTEGRANTES DE MAX" << endl; 
cout << "5. SALIR DEL JUEGO" << endl;
cout << "tempo";
cin >> opc;

        switch (opc) {

        case 1: 

        break;

        case 2: 

        
            
        break; 

        case 3: 
        
                
        break;

        case 4:
                
        break;

        case 5: 
                        
        break;

        default:

        break;
        }
                
    } while (opc != 5);
 return 0;

}

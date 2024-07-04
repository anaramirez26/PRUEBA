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
bool yaDicho(int, int [], int);
void generarTablero(int mat[3][3]);
void mostrarTablero(int mat[3][3]);
void tableroActualizado(int mat[3][3]);
bool verificarEmpate(int mat[2][3][3]);
void mostrarGanador(int mat[2][3][3], string arrjug[2], bool &juegoTerminado);

int main(void)
{
    srand(time(0));
    int numAl, opc, opcion;
    string arrjug[2];
    bool juegoTerminado = false;
    bool alguienGano = false;
    int mat[2][3][3] = {0}; // Matrices para los dos jugadores
    int numerosDichos [20] = {0};
    int contadorNumerosDichos = 0;

do {
cout << "Seleccione la opcion que desee: " << endl;
cout << "1. NUEVA PARTIDA" << endl;     
cout << "2. REGISTRO DE PARTIDAS" << endl; 
cout << "3. REGISTRO DE GANADORES" << endl; 
cout << "4. INTEGRANTES DE MAX" << endl; 
cout << "5. SALIR DEL JUEGO" << endl;
cin >> opc;

        switch (opc) {

          case 1: 
                for (int i = 0; i < 2; i++) {
                cout << "Ingrese el nombre del jugador " << (i + 1) << " : ";
                cin >> arrjug[i];
            }

            cout << endl << "Los nombres de los jugadores son: " << endl;
            for (int i = 0; i < 2; i++) {
                cout << "Jugador " << (i + 1) << " : " << arrjug[i] << endl;
            }

            cout << endl << endl << "HAZ INICIADO UNA NUEVA PARTIDA!" << endl << endl;
            cout << endl << "TABLEROS DE JUGADORES" << endl << endl;

                // Generar y mostrar los tableros para cada jugador
            for (int k = 0; k < 2; k++) {{
                cout << "Tablero del jugador " << arrjug[k] << " : " << endl << endl;

                // Generar números aleatorios únicos para cada tablero
                generarTablero(mat[k]);

                // Mostrar el tablero del jugador
                mostrarTablero(mat[k]);

            }

            }

            // Pausa antes de que el bot comience a generar números
            cout << "Presione Enter para que el bot genere el primer numero..." << endl;
            cin.ignore(); // Ignorar el carácter de nueva línea residual del último cin
            cin.get();

            // Bucle para generar números aleatorios y marcar en los tableros
            
            do { 
                
                do {
                    numAl = 1 + rand() % 20;
                } while (yaDicho(numAl, numerosDichos, contadorNumerosDichos));

                cout << endl << endl << "Numero generado por el bot: " << numAl << endl << endl;

                numerosDichos[contadorNumerosDichos++] = numAl;

                for (int k = 0; k < 2; k++) {
                    marcarNumero(numAl, mat[k]);
                }

                // Mostrar los tableros actualizados
                for (int k = 0; k < 2; k++) {
                    cout << "Tablero del jugador " << arrjug[k] << " : " << endl << endl;
                    tableroActualizado(mat[k]);
                }

                        // Pausa entre generaciones de números
                sleep(1);

                    if (verificarEmpate(mat)) {
                        cout << endl << "EL JUEGO TERMINÓ EN EMPATE!" << endl;
                        juegoTerminado = true;
                        cout << endl << "LA PARTIDA HA TERMINADO..." << endl << endl;
                        } else {
                        mostrarGanador(mat, arrjug, juegoTerminado);
                        }

                // do while para que las opciones no se muestren cuando este completo de ceros 
            do{ 

                if(!alguienGano);
                cout << "1. Mostrar la ayuda" << endl;
                cout << "2. Continuar con la partida" << endl;
                cin >> opcion; 

                if(opcion ==1){
                    cout << "AYUDA" << endl;
                    cout << "reglas" << endl; 
                    // Opción para continuar
                    cout << "Presione Enter para continuar con la partida..." << endl;
                    cin.ignore();
                    cin.get();
                    
                }else if(opcion != 2){
                    cout <<"Opcion invalida. Por favor, seleccione 1 o 2" << endl; 
                }
            } while (opcion != 1 && opcion != 2);
        
        }while (!juegoTerminado);

            cout << endl << endl << "LA PARTIDA HA TERMINADO..." << endl << endl;

                    break;

                    case 2: 

                    cout << endl << " REGISTRO DE PARTIDAS " << endl << endl;
            
                    break; 

                    case 3: 
                    cout << endl << "REGISTRO DE GANADORES" << endl << endl;
                
                    break;

                    case 4:
                
                    cout << endl << "INTEGRANTES DE MAX" << endl << endl;
                    cout << endl << "Ana Belen Ramirez Flores 00183224" << endl;
                    cout << endl << "Xochill Guissell Miguel Miranda 00114924" << endl;
                    cout << endl << "Maria Fernanda Ramirez Portillo 00127724" << endl;
                    cout << endl << endl;
                break;

                    case 5: 
                        
                        cout << endl << endl; 
                        
                        cout << endl << "Has salido del juego" << endl;

                        cout << endl << endl;   

                break;

                default:
                cout << "Opcion no valida. Por favor, seleccione 1 o 5." << endl;
                }

    } while (opc != 5);
 return 0;

}

// Función para verificar si un número ya ha sido colocado en el tablero
bool yaColocado(int num, int mat[3][3]) 
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] == num) {
                return true;
            }
        }
    }
    return false;
}

 // Función para verificar si el tablero está completamente lleno de ceros
bool tableroCompleto(int mat[3][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

// Función para marcar un número en el tablero
void marcarNumero(int num, int mat[3][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] == num) {
                mat[i][j] = 0;
            }
        }
    }
    
}

bool yaDicho(int num, int numerosDichos[], int contador)
{   
    for (int i=0; i < contador; i++) {
        if (numerosDichos[i] == num) {
            return true;
        }
    }

    return false;

}

void generarTablero(int mat[3][3])
{
    int numAl;
    for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                do {
                    numAl = 1 + rand() % 20;
                } while (yaColocado(numAl, mat));
                mat[i][j] = numAl;
            }
        }
}

void mostrarTablero(int mat[3][3])
{
    for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << mat[i][j] << "  ";
            }
            cout << endl << endl;
    }
}

void tableroActualizado(int mat[3][3])
{
    for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << mat[i][j] << "  ";
                }
                cout << endl << endl;
    }

}

// Función para verificar si ambos tableros están completamente llenos de ceros
bool verificarEmpate(int mat[2][3][3])
{
    return tableroCompleto(mat[0]) && tableroCompleto(mat[1]);
}

// Función para mostrar el ganador si un jugador tiene su tablero completo de ceros
void mostrarGanador(int mat[2][3][3], string arrjug[2], bool &juegoTerminado)
{
    if (tableroCompleto(mat[0])) {
        cout << endl << "EL JUGADOR " << arrjug[0] << " HA GANADO LA PARTIDA!" << endl;
        juegoTerminado = true;
        cout << endl << "LA PARTIDA HA TERMINADO..." << endl << endl;
    } else if (tableroCompleto(mat[1])) {
        cout << endl << "EL JUGADOR " << arrjug[1] << " HA GANADO LA PARTIDA!" << endl;
        juegoTerminado = true;
        cout << endl << "LA PARTIDA HA TERMINADO..." << endl << endl;
    }
}
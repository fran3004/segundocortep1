#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

void gotoxy(USHORT x, USHORT y){ COORD cp={x,y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp); }

void TITULOS();
int MENU();
void CAPTURA(int MATRIZ[10][10], int &FIL, int &COL);
void CREAR(int MATRIZ[10][10], int VECTOR[100], int FIL, int COL);

long VALNUMERO(int X, int Y, int T );

main()
  {
  char OP = 'S';
  int  TIPO, F = 0, C = 0, MTZ[10][10], VECTOR[100];
  while ( OP == 'S')
    {
    TITULOS();
    TIPO = MENU();
    switch (TIPO) {
       case 1 : CAPTURA(MTZ, F, C);
                break;
       case 2 : CREAR(MTZ, VECTOR, F, C);
                break;
       case 3 : OP = 'N';
       }
    }
  }

void TITULOS()
  {
  system("cls");
  system("color F1");
  gotoxy(13,5) ; cout <<"CAPTURAR MATRIZ Y VECTOR DE REPETIDOS";
  gotoxy(27,6);  cout <<"MATRIZ 10 X 10" ;
  }

int MENU()
  {
  int OP ;
  gotoxy(20,10); cout << "1 - CAPTURAR VALORES DE LA MATRIZ" ;
  gotoxy(20,11); cout << "2 - CREAR VECTOR DE ELEMENTOS REPETIDOS";
  gotoxy(20,13); cout << "3 - SALIR DEL PROGRAMA";
  do  {
       gotoxy(18,16); cout << "SELECCIONE UNA DE LAS ALTERNATIVAS : ";
       OP = VALNUMERO(56,16,10);
       gotoxy(24,22); cout << "VALOR FUERA DE RANGO";
  }  while((OP < 1) || (OP > 3)) ;
  gotoxy(24,22); cout << "                            ";
  return OP ;
  }

void CAPTURA(int MATRIZ[10][10], int &FIL, int &COL)
  {
  int I, J;
  TITULOS();
  gotoxy(22,9) ; cout << "CAPTURAR VALORES DE LA MATRIZ";

  if (FIL != 0)
     {
     gotoxy(18,14); cout << "OJO... LA MATRIZ YA EXISTE...!!!";
     gotoxy(18,16); cout << "CONSULTE LOS DATOS O REINICIE EL PROGRAMA";
     getch();
     }
  else
     {
     do {
        gotoxy(15,12); cout << "Digite el No de Filas, Max = 10 :      ";
        gotoxy(50,12); FIL = VALNUMERO(50,12,10);
     } while ((FIL <= 0 ) || (FIL > 10));

     do {
        gotoxy(15,13); cout << "Digite el No de Columnas, Max = 10 :      ";
        gotoxy(53,13); COL = VALNUMERO(53,13,10);
     } while ((COL <= 0 ) || (COL > 10));

     gotoxy(15,12); cout << "                                               ";
     gotoxy(15,13); cout << "                                               ";

     for ( I = 0 ; I < FIL ; I++ )
       for ( J = 0 ; J < COL ; J++ )
         {
         gotoxy(10,15); cout << "Introducir valor Entero para posicion ["<< I << "][" << J << "] ->      ";
         gotoxy(70,15); MATRIZ[I][J] = VALNUMERO(70,15,10) ;
         }

     gotoxy(10,20); cout << "DATOS REGISTRADOS... PULSE CUALQUIER TECLA";
     getch();
     }
  }

void CREAR(int MATRIZ[10][10], int VECTOR[100], int FIL, int COL)
  {
  int I, J, K, L, N, SW, CONT;

  if ( FIL == 0)
    {
    gotoxy (20,24); cout << " No existen datos en la Matriz";
    getch();
    }
  else
    {
    TITULOS();
    gotoxy(15,9) ; cout << "MATRIZ Y VECTOR DE ELEMENTOS REPETIDOS" ;
    N = 0;

    gotoxy(10,12); cout << "MATRIZ =";
    for ( I = 0 ; I < FIL ; I++ )
      {
      gotoxy(20,12 + I);
      for ( J = 0 ; J < COL ; J++ )
        cout << MATRIZ[I][J] << "   ";
      }

    for ( I = 0 ; I < FIL ; I++ )
      for ( J = 0 ; J < COL ; J++ )
        {
        CONT = 0;
        for ( K = 0 ; K < FIL ; K++ )
          for ( L = 0 ; L < COL ; L++ )
            if ( MATRIZ[I][J] == MATRIZ[K][L] )
               CONT++;

        if ( CONT > 1 )
           {
           SW = 0;
           for ( K = 0 ; K < N ; K++ )
             if ( VECTOR[K] == MATRIZ[I][J] )
                SW = 1;

           if ( SW == 0 )
              {
              VECTOR[N] = MATRIZ[I][J];
              N++;
              }
           }
        }

    gotoxy(10,14 + FIL); cout << "VECTOR REPETIDOS =";
    gotoxy(30,14 + FIL);
    for ( K = 0 ; K < N ; K++ )
      cout << VECTOR[K] << "   ";

    if ( N == 0 )
       {
       gotoxy(30,14 + FIL); cout << "NO EXISTEN ELEMENTOS REPETIDOS";
       }

    gotoxy(10,18 + FIL); cout << "Pulse cualquier tecla para salir ";
    getch();
    }
  }

long VALNUMERO(int X, int Y, int T )
  {
  long NUMERO ;
  char CADENA[30] ;
  int  SW, K, LONGITUD;
  cin.sync();
  do {
     SW = 0 ;
     gotoxy(X,Y) ; cout << "               " ;
     gotoxy(X,Y); NUMERO = atof(gets(CADENA));
     LONGITUD = strlen(CADENA) ;
     if ( LONGITUD == 0 )
        {
        gotoxy(20,22); cout << "ERROR.. no ha escrito nada, max = " << T;
        getch();
        SW = 1;
        }
      else
        if ( LONGITUD > T)
           {
           gotoxy(20,22); cout << "ERROR.. demasiados digitos, Max = " << T;
           getch();
           SW = 1;
           }
         else
           for ( K = 0 ; ( K < LONGITUD && SW == 0 ) ; K++ )
               if ( !isdigit(CADENA[K]) )
                  {
                  gotoxy(20,22); cout << "ERROR.. No Digite Letras";
                  getch();
                  SW = 1;
                  }
   gotoxy(20,22) ;cout << "                                                                ";
   }  while ( SW == 1 ) ;
   return  NUMERO ;
  }

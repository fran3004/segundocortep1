#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

void gotoxy(USHORT x, USHORT y){ COORD cp={x,y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp); }

void TITULOS();
int MENU();
void CREAR(int MATRIZ[10][10], int &FIL, int &COL);
void IMPRIMIR(int MATRIZ[10][10], int VECTOR[10], int FIL, int COL);

long VALNUMERO(int X, int Y, int T );

main()
  {
  char OP = 'S';
  int  TIPO, F = 0, C = 0, MTZ[10][10], VECTOR[10];
  while ( OP == 'S')
    {
    TITULOS();
    TIPO = MENU();
    switch (TIPO) {
       case 1 : CREAR(MTZ, F, C);
                break;
       case 2 : IMPRIMIR(MTZ, VECTOR, F, C);
                break;
       case 3 : OP = 'N';
       }
    }
  }

void TITULOS()
  {
  system("cls");
  system("color F1");
  gotoxy(13,5) ; cout <<"CREAR MATRIZ Y VECTOR POR COLUMNAS";
  gotoxy(17,6);  cout <<"SUMA DE CADA COLUMNA DE LA MATRIZ" ;
  }

int MENU()
  {
  int OP ;
  gotoxy(20,10); cout << "1 - ASIGNAR VALORES A LA MATRIZ" ;
  gotoxy(20,11); cout << "2 - IMPRIMIR MATRIZ Y VECTOR";
  gotoxy(20,13); cout << "3 - SALIR DEL PROGRAMA";
  do  {
       gotoxy(18,16); cout << "SELECCIONE UNA DE LAS ALTERNATIVAS : ";
       OP = VALNUMERO(56,16,10);
       gotoxy(24,22); cout << "VALOR FUERA DE RANGO";
  }  while((OP < 1) || (OP > 3)) ;
  gotoxy(24,22); cout << "                            ";
  return OP ;
  }

void CREAR(int MATRIZ[10][10], int &FIL, int &COL)
  {
  int I, J;
  TITULOS();
  gotoxy(23,9) ; cout << "ASIGNAR VALORES A LA MATRIZ";

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

void IMPRIMIR(int MATRIZ[10][10], int VECTOR[10], int FIL, int COL)
  {
  int I, J, F, SUMA;

  if ( FIL == 0)
    {
    gotoxy (20,24); cout << " No existen datos en la Matriz";
    getch();
    }
  else
    {
    TITULOS();
    gotoxy(18,9) ; cout << "IMPRIMIR MATRIZ Y VECTOR POR COLUMNAS" ;

    gotoxy(10,12); cout << "MATRIZ =";
    for ( I = 0 ; I < FIL ; I++ )
      {
      gotoxy(20,12 + I);
      for ( J = 0 ; J < COL ; J++ )
        cout << MATRIZ[I][J] << "   ";
      }

    for ( J = 0 ; J < COL ; J++ )
      {
      SUMA = 0;
      for ( I = 0 ; I < FIL ; I++ )
        SUMA = SUMA + MATRIZ[I][J];
      VECTOR[J] = SUMA;
      }

    F = 14 + FIL;
    gotoxy(10,F); cout << "VECTOR SUMA COLUMNAS =";
    gotoxy(35,F);
    for ( J = 0 ; J < COL ; J++ )
      cout << VECTOR[J] << "   ";

    gotoxy(10,F+4); cout << "Pulse cualquier tecla para salir ";
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

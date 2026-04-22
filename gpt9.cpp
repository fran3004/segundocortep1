#include <windows.h>                      
#include <iostream>                      
#include <conio.h>                       

using namespace std;                     

void gotoxy(USHORT x, USHORT y){ COORD cp={x,y};                              
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp); }

void TITULOS();
int MENU();
int CREAR(int ARREGLO[10], int N);
void CONSULTA(int ARREGLO[10], int N);

long VALNUMERO(int X, int Y, int T );

main()
    {
    char OP = 'S';
    int  TIPO, N = 0, VECTOR[10];
    while ( OP == 'S')
        {
        TITULOS();
        TIPO = MENU();
        switch (TIPO) {
            case 1 : N = CREAR(VECTOR, N);
                     break;
            case 2 : CONSULTA(VECTOR, N );
                	 break;
            case 3 : OP = 'N';
           };
       }
    }
  
  
void TITULOS()
   {
   system("cls");
   system("color F1");
   gotoxy(25,6) ; cout <<"CREAR Y CONSULTAR UN ARREGLO";
   gotoxy(28,7);  cout <<"UNIDIMENSIONAL - VECTOR" ;
   }
  
  int MENU()
   {
   int OP ;
   gotoxy(26,10); cout << "1 - ASIGNAR VALORES AL VECTOR" ;
   gotoxy(26,11); cout << "2 - CONSULTAR VALORES DEL VECTOR";
   gotoxy(26,13); cout << "3 - SALIR DEL PROGRAMA";
   do  {
        gotoxy(22,16); cout << "SELECIONE UNA DE LAS ALTERNATIVAS : ";
        OP = VALNUMERO(58,16,10);
        gotoxy(30,22); cout << "VALOR FUERA DE RANGO";
   }  while((OP < 1) || (OP > 5)) ;
   gotoxy(30,22); cout << "                            ";
   return OP ;
   }    

 int CREAR(int ARREGLO[10], int N)
    {
    int I;
    TITULOS();
    gotoxy(27,9) ; cout << "ASIGNAR VALORES AL VECTOR";  
    if (N !=0 )
       {
       gotoxy(27,15) ; cout << "Ojo ....EL VECTOR YA EXIXTE...!!!"; getch();
       }
     else
       {
       do {
	      gotoxy(15,13); cout << "Digite el No de Elemetos, Max = 10 :      ";
	      gotoxy(52,13); N = VALNUMERO(52,13,10);
       } while ((N < 0 ) || (N > 10));
       gotoxy(15,13); cout << "                                               ";
    
	   for ( I = 0 ; I < N ; I++ )
	       {
	       gotoxy(15,15); cout << "Introducir un valor Entero para la posicion "<< I << " -> ";
	       gotoxy(65,15); ARREGLO[I] = VALNUMERO(65,15,10) ;
	       }
	   }
	   return N;
    } 

 void CONSULTA(int ARREGLO[10], int N)
    {
    int I , SUMA , MAYOR, MENOR;
	if ( N == 0)
	   {
	   gotoxy (20,24); cout << " No existen elementos en la Listas";
	   getch();
	   }
	 else
	   {
	   TITULOS();
       gotoxy(26,9) ; cout << "CONSULTAR VALORES AL VECTOR" ;
       SUMA = 0, MAYOR = MENOR = ARREGLO[0];
       gotoxy(25,14); cout << "VECTOR = " ;
       for ( I = 0 ; I < N ; I++ )
           {
		   cout<< ARREGLO[I] << "   " ;
		   SUMA = SUMA + ARREGLO[I];
		   if ( ARREGLO[I] > MAYOR)
		      MAYOR = ARREGLO[I];
		   if ( ARREGLO[I] < MENOR)
			  MENOR = ARREGLO[I];
		   }   
	   gotoxy(25,16); cout << "SUMA TOTAL DE LOS ELEMENTOS  = " << SUMA;
	   gotoxy(25,18); cout << "VALOR MAYOR DE LOS ELEMENTOS = " << MAYOR;
	   gotoxy(25,20); cout << "VALOR MENOR DE LOS ELEMENTOS = " << MENOR;
       gotoxy(25,23); cout << "Pulse cualquier tecla para salir ";
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

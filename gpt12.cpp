#include <windows.h>                    
#include <iostream>                     
#include <conio.h>                      

using namespace std;                     

void gotoxy(USHORT x,USHORT y){ COORD cp={x,y};                                               
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp); }

void TITULOS();
int MENU();
int CREAR(int VECTOR[10], int N);
void IMPRIMIR(int VCETOR[10], int N);

long VALNUMERO(int X, int Y, int T );

main()
  {
  int TIPO ;
  char  OP = 'S';
  int VECTOR[10], N = 0;
  while  ( OP == 'S' )
    {
    TITULOS();
    TIPO = MENU();
    switch ( TIPO ) {
     
       case 1 : N = CREAR( VECTOR, N);
                break ;
       case 2 : IMPRIMIR(VECTOR, N);
	            break ;
       case 3 : OP = 'N' ;
	            break ;
       }
    }
  }

void TITULOS()
   {
   system("cls");
   system("color F1");
   gotoxy(22,6) ; cout <<"CREAR, ORDENAR E IMPRIMIR UN VECTOR";
   gotoxy(34,7);  cout <<"METODO BURBUJA" ;
   }
   
int MENU()
  {
  int TIPO;
  gotoxy(26,10); cout << "1 - ASIGNAR VALORES AL VECTOR" ;
  gotoxy(26,11); cout << "2 - ORDENAR VECTOR E IMPRIMIR";
  gotoxy(26,13); cout << "3 - SALIR DEL PROGRAMA";
  do {
     gotoxy(22,16); cout << "Seleccine una alternativa :  ";
     TIPO = VALNUMERO(58,16,10);
  } while ((TIPO < 1 ) || (TIPO > 3));
  return TIPO;
  }
 
int CREAR(int VECTOR[10], int N)  
  {
  int I ;
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
	     gotoxy(65,15); VECTOR[I] = VALNUMERO(65,15,10) ;
         }
     }
   return N;
  } 
    
void IMPRIMIR(int VECTOR[10], int N) 
   {
   int I, K, AUX, VECTORAUX[N];
   if ( N == 0)
      {
      gotoxy (20,24); cout << " No existen elementos en la Listas";
      getch();
      }
    else
      {
	  TITULOS();
      gotoxy(26,10) ; cout << "ORDENAR VECTOR E IMPRIMIR" ;
             	   
      // **** RUTINA DE IMPRIMIR VECTOR INICIAL ****	
            	   
      gotoxy(25,14); cout << "VECTOR  INICIAL = " ;
      for ( I = 0 ; I < N ; I++ )
          {
	      cout<< VECTOR[I] << "   " ;
	      VECTORAUX[I] = VECTOR[I];
	      }
	                
	   // **** RUTINA DE ORDENAMIENTO - METODO BURBUJA ****  
						               
      for ( I = 1 ; I < N ; I++)
        for ( K = N-1 ; K >= I; K--)
            if ( VECTORAUX[K-1] > VECTORAUX[K] )
               {
               AUX = VECTORAUX[K-1] ;
               VECTORAUX [K-1] = VECTORAUX[K] ;
               VECTORAUX[K] = AUX ;
               }
                            		                       
	   // **** RUTINA DE IMPRIMIR VECTOR ORDENADO ****	
						   
	  gotoxy(25,17); cout << "VECTOR ORDENADO = " ;
      for ( I = 0 ; I < N ; I++ )
	      cout<< VECTORAUX[I] << "   " ;			    
	                   
	  gotoxy(25,22); cout << "Pulse cualquier tecla para salir ";
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
	       for ( K = 0 ; ( K < LONGITUD && SW == 0 ); K++ )
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


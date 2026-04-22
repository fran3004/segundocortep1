#include <windows.h>                      
#include <iostream>                      
#include <conio.h>                       

using namespace std;                     

void gotoxy(USHORT x,USHORT y){ COORD cp={x,y};                                               
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp); }

void TITULOS();
int MENU();
int CAPTURA(int VECTOR[15], int N);
void BUSCAR(int VECTOR[15],  int N);

long VALNUMERO(int X, int Y, int T );


// ***********************PROGRAMA PRINCIPAL ****************

main()
  {
  char CONTROL = 'S';
  int  OPCION , NRO = 0 ;
  int  VECTOR[15];
  while ( CONTROL == 'S')
     {
     TITULOS();
     OPCION = MENU();
     switch (OPCION)  {
        case 1 : NRO = CAPTURA(VECTOR, NRO );
                 break;
        case 2 : BUSCAR (  VECTOR, NRO);
                 break;
        case 3 : CONTROL = 'N';
         };
      }
   }
  
// *********************** FUNCION TITULOS ****************
void TITULOS()
   {
   system("cls");
   system("color F1");
   gotoxy(14,6) ; cout <<"CREAR Y/O ADICIONA, CONSULTA Y BUSCAR EN UN ARREGLO";
   gotoxy(28,7);  cout <<"UNIDIMENSIONAL - VECTOR" ;
   }
  
// *********************** FUNCION MENU *******************
  
  int MENU()
   {
   int TIPO ;
   gotoxy(26,10); cout << "1 - ASIGNAR VALORES AL VECTOR";
   gotoxy(26,12); cout << "2 - IMPRIMIR Y BUSCAR EN EL VECTOR "  ;
   gotoxy(26,14); cout << "3 - SALIR DEL PROGRAMA";
   do {
      gotoxy(24,19); cout << "Seleccine una alternativa :  ";
      gotoxy(55,19); TIPO = VALNUMERO(55,19,10);
   } while ((TIPO < 1 ) || (TIPO > 3));
   return TIPO ;
   }  
   
// *********************** FUNCION CREAR  *******************
  
int CAPTURA(int VECTOR[15], int N )  
  {
  char OP = 'S';
  if (N >= 15)
	 {
	 gotoxy(27,23) ; cout << "NO HAY ESPACIOS DISPONIBLES";
	 getch();
	 }
    else
     {
     TITULOS();
     gotoxy(27,9) ; cout << "ASIGNAR VALORES AL VECTOR";  
     while (( OP == 'S') && ( N < 15))
       {
       gotoxy(15,15); cout << "Introducir un valor Entero para la posicion "<< N << " -> ";
	   gotoxy(62,15); VECTOR[N] = VALNUMERO(65,15,10);
	   N++;
       do {
          gotoxy(20,20); cout << "Desea Capturar un Nuevo Elemento  S/N :        ";
          gotoxy(60,20); OP = getche();
          OP = toupper(OP);
       } while (( OP != 'S') && ( OP != 'N'));
       }
      }
    return N ;
  } 
 	
  
// ******************** FUNCION BUSCAR ****************
  
void BUSCAR( int VECTOR[15], int N )	
   {
   int VALOR, K, SW ;
   if ( N == 0 )
      {
      gotoxy(20,24); cout << "NO Existe Vector" ;
      getch();
      }
     else
	  {
	  TITULOS();
      gotoxy(15,15); cout << "Introducir un valor Entero -> ";
      gotoxy(45,15); VALOR = VALNUMERO(45,15,10);
      gotoxy(15,15); cout << "                                   ";
      gotoxy(25,14); cout << "VECTOR = " ;
      SW = 0 ;	
	  for ( K = 0 ; K < N ; K++ ) 
	      {
	      cout<< VECTOR[K] << "   " ;
	      if (VALOR == VECTOR[K])
	          SW = 1 ; 
	      }
	   
	  if (SW == 1)
	     {
	     gotoxy(25,20); cout << "OK, Elemento " << VALOR << " SI EXISTE en la Lista !!!!!!" ;
	     }
	   else
	     {
	     gotoxy(25,20); cout << "El Elemento " << VALOR << " NO EXISTE en la Lista !!!!!!! ";	
	     }	  
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


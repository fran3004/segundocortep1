#include <iostream>
#include <conio.h>
#include <windows.h>  

using namespace std; 

void gotoxy(USHORT x, USHORT y){ COORD cp={x,y};                                                 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp); }

long double VALNUMERO(int X, int Y, int T );
char *VALCADENA(int X, int Y, int T );

main()
  {
  char NOMBRE[30], SEXO[9];
  long CEDULA; 
  char OP ='S';
  while (OP == 'S')
    {
    system("cls");
    system("color F1");
    gotoxy(33,5) ;cout << "CUEROLANDIA LTDA";
    gotoxy(30,6) ;cout << "REGISTRO DE LOS DATOS";
    gotoxy(20,9) ;cout << "CEDULA   : ";
    gotoxy(20,10);cout << "NOMBRE   : ";
    gotoxy(20,11);cout << "SEXO     : ";
    do {
       gotoxy(31,9) ;  CEDULA  = VALNUMERO(31,9,10);
       gotoxy(20,22); cout<< "Error .... valor fuera de rango ";
    } while ( CEDULA < 0 ) ;
    gotoxy(20,22); cout << "                                  ";
    gotoxy(31,10); strcpy( NOMBRE, strupr(VALCADENA(31,10,30)));
    gotoxy(31,10); cout << (NOMBRE);
    do {
       gotoxy(20,22); cout << " Digite : MASCULINO o FEMENINO " ;
       gotoxy(31,11); strcpy( SEXO, strupr(VALCADENA(31,11,9)) );
       gotoxy(31,11); cout << SEXO;
    }  while ( strcmp( SEXO, "MASCULINO" ) != 0  && strcmp(SEXO, "FEMENINO") != 0 );
    gotoxy(20,22); cout << "                                  ";
    gotoxy(34,15); cout << "DATOS LEIDOS";
    gotoxy(20,17); cout << "CEDULA LEIDA   = " << CEDULA ;
    gotoxy(20,18); cout << "NOMBRE LEIDO   = " << NOMBRE;
    gotoxy(20,19); cout << "SEXO LEIDO     = " << SEXO  ;
    do {
       gotoxy(28,23); printf("DESEA CONTINUAR - S/N - ");
       OP = getch();
       OP = toupper(OP);
    } while (( OP != 'S' ) && ( OP != 'N'));
    }
  }  


long double VALNUMERO(int X, int Y, int T )
  {
  long NUMERO ;
  char CADENA[30] ;
  int  SW, K, LONGITUD;
  cin.sync();
  do { 
     SW = 0 ;
     gotoxy(X,Y) ; cout << "                                                              " ;
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


char *VALCADENA(int X, int Y, int T )
   {
   char CADENA[40];
   int  SW, K, LONGITUD ;
   cin.sync();
   do {
      SW = 0 ;
      gotoxy(X,Y) ; cout << "                                                           " ;
      gotoxy(X,Y);  gets(CADENA);
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
	        gotoxy(20,22); cout << "ERROR.. demasiados LETRAS, Max = " << T;
	        getch();
	        SW = 1;
	        } 
	      else
	        for ( K = 0 ; ( K < LONGITUD && SW == 0 ) ; K++ )
	            if (( !isalpha( CADENA[K])) && (CADENA[K]  != ' ') && (CADENA[K]  != '.')
		           && (CADENA[K]  != '-') && (CADENA[K]  != '?') && (CADENA[K]  != '?'))
		           {
		           gotoxy(20,22); cout << "ERROR.. Digite solo Letras      ";
		           getch();
		           SW = 1;
		           }
	
     gotoxy(10,22) ;cout << "                                                             ";
     } while ( SW == 1 ) ;
     return CADENA ;
   }

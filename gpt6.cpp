#include <windows.h>                    
#include <iostream>                     
#include <conio.h>                      

using namespace std;                     

void gotoxy(SHORT x, USHORT y){ COORD cp={x,y};                                               
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp); }

main()
  {
  int I , TIPO, N = 0 ;
  char  OP = 'S';
  int VECTOR[10] ;
  while  ( OP == 'S' )
    {
    system("cls");
    system("color F1");
    gotoxy(25,6) ; cout <<"CREAR Y CONSULTAR UN ARREGLO";
    gotoxy(28,7);  cout <<"UNIDIMENSIONAL - VECTOR" ;
    gotoxy(26,10); cout << "1 - ASIGNAR VALORES AL VECTOR" ;
    gotoxy(26,11); cout << "2 - CONSULTAR VALORES DEL VECTOR";
    gotoxy(26,13); cout << "3 - SALIR DEL PROGRAMA";
    do {
       gotoxy(24,16); cout << "Seleccine una alternativa : ";
       gotoxy(55,16); cin >> TIPO ;
    } while ((TIPO < 1 ) || (TIPO > 3));
    
    switch ( TIPO ) {
     
       case 1 : system("cls");
                system("color F1");
                gotoxy(25,6) ; cout <<"CREAR Y CONSULTAR UN ARREGLO";
                gotoxy(28,7);  cout <<"UNIDIMENSIONAL - VECTOR" ;
                gotoxy(27,9) ; cout << "ASIGNAR VALORES AL VECTOR";  
                if (N !=0 )
                   {
                   gotoxy(27,15) ; cout << "Ojo ....EL VECTOR YA EXIXTE...!!!"; getch();
                   }
                 else
                   {
				   do {
	     	          gotoxy(15,13); cout << "Digite el No de Elemetos, Max = 10 :      ";
	                  gotoxy(52,13); cin >> N ;
	               } while ((N < 0 ) || (N > 10));
	               gotoxy(15,13); cout << "                                               ";
                   for ( I = 0 ; I < N ; I++ )
	                 {
	                 gotoxy(15,15); cout << "Introducir un valor Entero para la posicion "<< I << " ->       ";
			         gotoxy(65,15); cin >> VECTOR[I] ;
	                 }
	               }  
	            break ;
      
	   case 2 : if ( N == 0)
	               {
	               gotoxy (20,24); cout << " No existen elementos en la Listas";
				   getch();
			       }
				 else
				   {
				   system("cls");
				   system("color F1");
                   gotoxy(25,6) ; cout <<"CREAR Y CONSULTAR UN ARREGLO";
				   gotoxy(28,7);  cout <<"UNIDIMENSIONAL - VECTOR" ;
				   gotoxy(26,9) ; cout << "CONSULTAR VALORES AL VECTOR" ;
                   gotoxy(25,14); cout << "VECTOR = " ;          
				   for ( I = 0 ; I < N ; I++ )
				       cout<< VECTOR[I] << "   " ;
				   gotoxy(25,19); cout << "Pulse cualquier tecla para salir ";    
			       getch();
				   }
				   break ;
				   
	   case 3 : OP = 'N' ;
	            break ;
       }
	}
  }


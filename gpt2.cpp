#include <iostream>
#include <conio.h>
#include <windows.h>  

using namespace std; 

int gotoxy(USHORT x,USHORT y){                                  
COORD cp={x,y};                                                 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);   
}

int  RECIBIR();
int  MOSTRAR(int NRO);

main() {
	int  N, F ;
    char OP = 'S';
    while (OP == 'S')
          {
          system("cls");
          system("color F1");
          gotoxy(30,5); cout << "TABLA DE MULTIPLICAR";
          N = RECIBIR();
          F = MOSTRAR(N);
          do {
             gotoxy(29,F+3); cout<< "DESEA CONTINUAR  S/N : " ;
             OP = getch();
             OP = toupper(OP);
          }  while ((OP != 'S') && (OP != 'N')); 
           
	  }
	}

 int RECIBIR()
  {
  int NRO;
  gotoxy(25,20); cout <<"EL VALOR DEBE SER ENTRE 1 y 12";
  do {
     gotoxy(25,8); cout << "Digite el Numero de Calculo :       ";
     gotoxy(55,8); cin >> NRO ;
     gotoxy(25,20); cout <<"ERROR.......VALOR ENTRE 1 y 12";
  }  while(( NRO <= 0 )|| ( NRO >12 ));
  gotoxy(25,8);  cout << "                                           ";
  gotoxy(25,20); cout << "                                           ";	
  return NRO;	
  }
  
 int  MOSTRAR( int NRO)
    {
    int J, T, F ;
    gotoxy(30,5);  cout << "TABLA DE MULTIPLICAR DEL " <<  NRO;
    F = 8 ;
    for (J = 1 ; J <= 12 ; J++)
      {
      T = NRO * J ;
      gotoxy(34,F); printf("%2d %3s %2d %3s %3d", J, " * ", NRO, " = ", T) ;
      //gotoxy(34,F); cout<< J << " * " << N  << " = " << T ;
      F++ ;
      }
      return F;
    } 

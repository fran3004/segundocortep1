#include <iostream>
#include <conio.h>
#include <windows.h>  

using namespace std; 

void gotoxy(USHORT x,USHORT y){ COORD cp={x,y};                                                 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp); }

void MOSTRAR();
char OPCION();
void TITULOS();

main() 
  {
  char OP = 'S';
  while (OP == 'S')
    {
    TITULOS();
    MOSTRAR();
    OP = OPCION();
    }
  }

void TITULOS()
   {
   system("cls");
   system("color F1");
   gotoxy(17,5); cout << "DETERMINAR SI UN NUMERO ES POSITIVO O NEGATIVO";
   }
	
  	   
void MOSTRAR()
   {
   int N;
   gotoxy(25,8); cout << "Digite el Numero :       ";
   gotoxy(44,8); cin >> N ;
   if ( N > 0)
      {
      gotoxy(25,13); cout <<  N << " ES UN VALOR POSITIVO";
      }
    else
      {
      gotoxy(25,13); cout <<  N << " ES UN VALOR NEGATIVO";
      }
   }
    
char OPCION()
  {
  char OP;
  do {
     gotoxy(29,18); cout<< "DESEA CONTINUAR  S/N : " ;
     OP = getch();
     OP = toupper(OP);
   }  while ((OP != 'S') && (OP != 'N'));
   return OP;
   }

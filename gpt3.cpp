#include <windows.h>  
#include <iostream>  
#include <conio.h>   

using namespace std; 

int gotoxy(int x,int y){                                  
COORD cp={x,y};                                                 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);   
}

void TITULOS();
void CONTEXTOS();
void CAPTURA( long &CEDULA, char NOMBRE[20], char &SEXO, int &EDAD);
void IMPRIMIR(long CEDULA, char NOMBRE[20], char SEXO, int EDAD) ;
char OPCION();

main() 
  {
  long CEDULA;
  int EDAD ;
  char NOMBRE[20], SEXO;
  char OP = 'S' ;
  
  while (OP == 'S') 
    {
    TITULOS();
    CONTEXTOS();
    CAPTURA(CEDULA, NOMBRE, SEXO, EDAD);
    IMPRIMIR(CEDULA, NOMBRE, SEXO, EDAD);
    OP = OPCION();
    }
  }


void TITULOS()
  {
  system("cls"); 	
  system("color F0");
  gotoxy(25,4); cout<<"UNIVERSIDAD POPULAR DEL CESAR";
  gotoxy(24,5); cout<<"PROGRAMA INGENIERIA DE SISTEMAS"; 
  }
  
void CONTEXTOS()
  {
  gotoxy(20,8);  cout<< "CEDULA     : ";
  gotoxy(20,9);  cout<< "NOMBRE     : ";
  gotoxy(20,10); cout<< "SEXO  M/F  : " ;
  gotoxy(20,11); cout<< "EDAD       : " ;	
  }
  
void CAPTURA( long &CEDULA, char NOMBRE[20], char &SEXO, int &EDAD)
  {
    do {
       gotoxy(33,8) ; cout << "              ";	
       gotoxy(33,8) ; cin >> CEDULA;
       gotoxy(20,22) ; cout<< "Error .... valor fuera de rango ";
    } while (CEDULA <= 0);
    gotoxy(20,22); cout <<"                                   ";
    cin.ignore();
    gotoxy(33,9);  gets(NOMBRE);
    do {
       gotoxy(33,10); cout<< " " ;
       gotoxy(20,20); cout << " Digite : M-> Masculino o F -> Femenino " ;
       gotoxy(33,10); SEXO = getchar();
       SEXO = toupper(SEXO) ;
    } while ((SEXO != 'M') && ( SEXO != 'F'));
    gotoxy(20,20); cout <<"                                              ";
    do {
       gotoxy(33,11); cout<< "   " ;
       gotoxy(33,11); cin >> EDAD;
       gotoxy(20,22); cout << "Error .... valor NO valido ";
    } while ((EDAD < 1) || (EDAD > 120));
    gotoxy(20,22); cout <<"                              ";
  }
  
  
void IMPRIMIR(long CEDULA, char NOMBRE[20], char SEXO, int EDAD) 
  {
  gotoxy(34,14); printf( "DATOS LEIDOS");
  gotoxy(20,17); cout<< "CEDULA  = " << CEDULA;
  gotoxy(20,18); cout<< "NOMBRE  = " << NOMBRE;
  gotoxy(20,19); cout<< "SEXO    = " << SEXO ;
  gotoxy(20,20); cout<< "EDAD    = " << EDAD ; 
  }  
  
  
char OPCION()
  {
  char OP; 
  do {
     gotoxy(27,24); cout<< "DESEA CONTINUAR  S/N : " ;
     OP = getche();
     OP = toupper(OP);
  }  while ((OP != 'S') && (OP != 'N'));
  return OP;
  }

#include <windows.h> 
#include <iostream> 
#include <conio.h>  

using namespace std; 

void gotoxy(USHORT x,USHORT y) {COORD cp={x,y};                                                 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp); }

/******************* DECLARACION DE FUNCIONES **********************/

void TITULOS();
int MENU();
void CAPTURA(long &CEDULA, char NOMBRE[20], int &EDAD, char &SEXO);
void CALCULOS( char SEXO, int EDAD, int &ContM, int &ContF, int &AcuM, int &AcuF, int &EdadMayor, int &EdadMenor );
void IMPRIMIR(int ContM, int ContF, int AcuM, int AcuF, int EdadMayor, int EdadMenor );

/********************** PROGRAMA PRINCIPAL ************************/

main()
  {
  long CEDULA ;
  char NOMBRE[20], SEXO;
  int  EDAD, OPCION, ContM = 0, ContF= 0, AcuM = 0, AcuF = 0, EdadMayor = 0, EdadMenor = 120;
  char OP = 'S', OPMENU = 'S' ;
  
  while (OPMENU == 'S')
    {
    TITULOS();
    OPCION = MENU();
    OP = 'S';
    switch (OPCION) {
	  case 1 : while (OP == 'S')
                 { 
                 TITULOS();
                 CAPTURA(CEDULA, NOMBRE, EDAD, SEXO);
	             CALCULOS( SEXO, EDAD, ContM, ContF, AcuM, AcuF, EdadMayor, EdadMenor );
                 do {
                    gotoxy(27,20); cout<< "DESEA CONTINUAR  S/N : " ;
                    OP = getche();
                    OP = toupper(OP);
                 }  while ((OP != 'S') && (OP != 'N'));
                }
                break;
      case 2 : IMPRIMIR(ContM, ContF, AcuM, AcuF, EdadMayor, EdadMenor);
               break;
      case 3 : OPMENU ='N';
      }
    }
  } 
  

/********************** FUNCION TITULOS ************************/

void TITULOS()
  {
  system("cls"); 	
  system("color F1");
  gotoxy(29,4); cout<<"E S T A D I S T I C A";
  gotoxy(26,6); cout<<"CIUDAD DE VALLEDUPAR - CESAR";
  }
  
/*********************** FUNCION MENU *************************/

int MENU()
  {
  int OPCION;
  gotoxy(26,10); cout << "1 - CAPTURA DE DATOS Y CALCULOS" ;
  gotoxy(26,11); cout << "2 - CONSULTAR RESULTADOS";
  gotoxy(26,13); cout << "3 - SALIR DEL PROGRAMA";
  do {
    gotoxy(22,16); cout << "SELECIONE UNA DE LAS ALTERNATIVAS : ";
    cin >> OPCION ;
    gotoxy(30,22); cout << "VALOR FUERA DE RANGO";
  }  while((OPCION < 1) || (OPCION > 3)) ;
  gotoxy(30,22); cout << "                            ";
  return OPCION;
  } 
  
/********************** FUNCION CAPTURA ************************/

  
void CAPTURA(long &CEDULA, char NOMBRE[20], int &EDAD, char &SEXO)
  {
  gotoxy(20,10); cout<< "CEDULA     : ";
  gotoxy(20,11); cout<< "NOMBRE     : ";
  gotoxy(20,12); cout<< "SEXO  M/F  : " ;
  gotoxy(20,13); cout<< "EDAD       : " ;
      
  do {
     gotoxy(33,10) ; cout << "              ";	
     gotoxy(33,10) ; cin >> CEDULA;
     gotoxy(20,22); cout<< "Error .... valor fuera de rango ";
  } while (CEDULA <= 0) ;
  gotoxy(20,22); cout <<"                                   ";
  cin.sync();
  gotoxy(33,11); gets(NOMBRE);
  do {
     gotoxy(33,12); cout<< " " ;
     gotoxy(20,20); cout << " Digite : M-> Masculino o F -> Femenino " ;
     gotoxy(33,12); SEXO = getchar();
     SEXO = toupper(SEXO) ;
  } while ((SEXO != 'M') && ( SEXO != 'F'));
  gotoxy(20,20); cout <<"                                              ";
  do {
     gotoxy(33,13) ; cout << "   ";	
     gotoxy(33,13) ; cin >> EDAD;
     gotoxy(20,22); cout<< "Error .... valor fuera de rango ";
  } while (EDAD <= 0) ;
  gotoxy(20,22); cout <<"                                       "; 
	
  }
  
  
/********************** FUNCION CALCULOS ************************/

  
void CALCULOS( char SEXO, int EDAD, int &ContM, int &ContF, int &AcuM, int &AcuF, int &EdadMayor, int &EdadMenor )
  {
  switch (SEXO) {
	
     case 'M': ContM = ContM + 1;
               AcuM = AcuM + EDAD;
               break;
     case 'F': ContF = ContF + 1;
               AcuF = AcuF + EDAD;
           }
      
  if (EDAD > EdadMayor)
     EdadMayor = EDAD;
  if (EDAD <EdadMenor)
     EdadMenor = EDAD;
  }
  
 
/********************** FUNCION IMPRIMIR ************************/
 
  
void IMPRIMIR(int ContM, int ContF, int AcuM, int AcuF, int EdadMayor, int EdadMenor )
  {
  TITULOS();
  if ((ContF > 0 ) || (ContM > 0 ))
     {
     gotoxy(20,12); cout <<" Numero de Personas de Sexo Masculino    = " << ContM;
     if (ContM > 0)
        {
	    gotoxy(20,13); cout <<" Promedio Edad de edad de Sexo Masculino = " << AcuM/ContM;
        }
      else
        {
        gotoxy(20,13); cout <<" Promedio Edad de edad de Sexo Masculino = 0 ";
        }
     gotoxy(20,14); cout <<" Numero de Personas de Sexo femenino     = " << ContF;
     if (ContF > 0 )
        {
        gotoxy(20,15); cout <<" Promedio Edad de edad de Sexo Femenino  = " << AcuF/ContF;;
        }
      else
        {
        gotoxy(20,15); cout <<" Promedio Edad de edad de Sexo Femenino  = 0 ";
	    }
     gotoxy(20,16); cout <<" Promedio de Edad de todo el grupo       = " << (AcuM+AcuF)/(ContM+ContF);
    
     gotoxy(20,17); cout <<" Edad Mayor de todo el grupo             = " << EdadMayor;
     gotoxy(20,18); cout <<" Edad Menor de todo el grupo             = " << EdadMenor;
     }
   else
     {
     gotoxy(27,15); cout << "NO SE HAN PROCESADO DATOS ";
  	 }
  gotoxy(22,22); cout << "PULSE CUALQUIER TECLA PARA VOLVER AL MENU";
  getch();
  }

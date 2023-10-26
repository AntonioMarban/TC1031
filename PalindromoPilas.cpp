#include <iostream>
#include "TStack.h"
#include "Pilas1.cpp"
using namespace std;

#define MAX 200

string limpiaCadena(char *cadena,char * cadenaLimpia) { // elimina signos de puntuación y cambia acentos
	int c=0;
  for(int i =0; i< strlen(cadena); i++){
    char car=tolower(cadena[i]);
  	switch (car) 
    {
        // reemplazar
      case 'á': cadenaLimpia[c++]='a'; break;
      case 'é': cadenaLimpia[c++]='e'; break;
      case 'í': cadenaLimpia[c++]='i'; break;
      case 'ó': cadenaLimpia[c++]='o'; break;
      case 'ú': cadenaLimpia[c++]='u'; break;
        // ignorar:
      case ' ':
      case '-':
      case ';':
      case '.':
      case ',':
        				break;
      default:
        		cadenaLimpia[c++]=car;    			
    }
  }
  cadenaLimpia[c]='\0';
  return cadenaLimpia;
}

int main() {
	 char cadena[MAX];
	 char cadenaLimpia[MAX];
   
   cin.gets(cadena);
   
   limpiaCadena(cadena, cadenaLimpia); // elimina signos de puntuación y cambia acentos     //no que un establo
   char *p1=cadenaLimpia, *p2=&cadenaLimpia[strlen(cadenaLimpia)-1];
   TStack <char> *pila1=new TStack<char>();
   TStack <char> *pila2=new TStack<char>();
   while ( *p1 ) {
           pila1->push(*p1);
           pila2->push(*p2);
           p1++; p2--;
    } 
	  while (!pila1->empty() && !(pila2->empty()) {
	     if (pila1->pop()!=pila2->pop())
            break;
    } 
    if (pila1->empty() && pila2->empty())
         cout << “La cadena es palíndromo”;
    else 
         cout << “La cadena no es palíndromo”; 
}
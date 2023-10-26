//
//     Antonio Marbán Regalado
//    Actividad 2.3 - A01424831
//
//  



#include <iostream>
#include "TStack.h"
using namespace std;

#define MAX 200

int main() {
	char cadena[MAX]; // Crea variable cadena
   
   cin.gets(cadena);
   char *p1=cadena;
   TStack <char> *pila=new TStack<char>();

   while ( *p1 ) {
        
            pila1->push(*p1);
            pila2->push(*p2);
            p1++; p2--;
    } 
	  while (!pila1->empty() && !(pila2->empty()) {
	    if (pila1->pop()!=pila2->pop())
            break;
    } 

    if (pila->empty())
        cout << “Esta operacion es valida”;
    else 
        cout << “Esta operacion no es valida”; 
}
#include <iostream>
#include "BST.h"
using namespace std;

int main() {
    // int arr[] {20,1,4,7,23,5,10,8,11,21}; // Caso de prueba 1
    // int arr3[] {10, 5, 1, 20}; // Caso de prueba personal

    int arr2[] {13,7,9,11,23,3,6,2,23,28,4,8,1,19}; // Caso de prueba 2

    BST<int> *arbolito=new BST<int>();

    for (int i=0; i<14;i++) {
        arbolito->addValue(&arr2[i]);
    }

    // Act 2.0 - A01424831

    
  	cout<<"Valores del arbol:";
  	arbolito->display();  
    
  	int val = 0;
    do {
  		cout<<endl<<"Que valor quieres eliminar?";
      cin>>val;
      arbolito->removeValue(&val);
      cout<<"Nuevo arbol:";	
      arbolito->display();
      int nodeCount = arbolito->countNodes();
      cout << "Numero de nodos: " << nodeCount << endl;
    } while (val!=0);

    

    // Act 3.0 - A01424831

    cout << "\nBinary tree displayed via preorder traversal:" << endl;
    arbolito -> visit(1); // Preorder
    cout << "\nBinary tree displayed via inorder traversal:" << endl;
    arbolito -> visit(2); // Inorder
    cout << "\nBinary tree displayed via postorder traversal:" << endl;
    arbolito -> visit(3); // Postorder
    cout << "\nBinary tree displayed via level-by-level traversal:" << endl;
    arbolito -> visit(4); // Breadth-first Search
    cout << "\nAncestors of 1:" << endl;
    arbolito->ancestors(1);
    cout << "\nLevel of value 13:" << endl;
    cout << arbolito->whatLevelAmI(13);
    cout << "\nHeight:" << endl;
    cout << arbolito -> height();
}



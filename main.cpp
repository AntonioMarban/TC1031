//
//     Antonio Marbán Regalado
//    Actividad 2.3 - A01424831
//

#include <iostream>
#include "TStack.h"
using namespace std;

#define MAX 200

int main() {
    char expression[MAX] = "{A+B + (a+b)}"; // Creates string variable that will store the mathematic expression
    bool valid = true; // Boolean variable that checks if our expression is valid
   
    cout << "Please enter a mathematic expression to validate its parentheses use." << endl;
    cout << ">>>";

    //  cin.get(expression, MAX); // Receives string input and stores it in the expression variable

    char * expressionPointer = expression; // Makes a char type pointer that is set to the expression which is a char[]
    cout << *expressionPointer << " esto es lo que pushea cuando pongo *expressionPointer" << endl; // flags
    cout << expressionPointer << "  esto es lo que pushea cuando pongo expressionPointer" << endl; // flags porque no entiendo qp con el error

    TStack <char> *stack = new TStack<char>(); // Creates stack object

    char expressionArray[MAX];
    int expressionArrayIndex = 0; // Needed to make the push() function parameters work

    while (*expressionPointer) { // Traverses our string
        cout << *expressionPointer;
        if (*expressionPointer == '(' || *expressionPointer == '[' || *expressionPointer == '{') { // If it encounters opening symbol
            expressionArray[expressionArrayIndex] = *expressionPointer; // Sets current index on expressionArray to what the pointer is pointing to
            stack->push(&expressionArray[expressionArrayIndex]); 
            expressionArrayIndex++; // 
        }
        if (*expressionPointer == ')' || *expressionPointer == ']' || *expressionPointer == '}') { // If it encounters closing symbol
            if (stack->empty()) { // Checks if our stack is empty
                valid = false; // If it is empty, then it is an invalid expression because there is no opening symbol to match it
            }
            else { // If it is not empty
                cout << "pila no vacia";
                cout << "\n========" << stack->stacktop() << "=====\n";
                char *popped = stack->pop(); // Pops the top element
                cout << "llegue aqui";
                cout << *popped;
                switch(*expressionPointer) { 
                    case ')': if (*popped != '(') valid = false; // If the closing symbol is a ')' but the popped element isn't a '('
                    break; 
                    case ']': if (*popped != '[') valid = false; // it becomes an invalid expression
                    break;
                    case '}': if (*popped != '{') valid = false; // Same process for all the other symbols
                    break; 
                }
            }
        }
        expressionPointer++;
    }
    cout << "\nWhile closed." << endl;
    if (!stack->empty()) { // If by the time we finish traversing the string, our stack is NOT empty
        valid = false; // Then it is an invalid expression, because there is an opening symbol waiting to be closed (and therefore, popped)
    }
    cout << "Empty checked" << endl;
    cout << endl;
    if (valid) {
        cout << "Valid expression" << endl; // If valid, valid
    }
    else {
        cout << "Invalid expression" << endl; // If not valid, not valid
    }
}
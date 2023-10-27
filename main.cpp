//
//     Antonio Marbán Regalado
//    Actividad 2.3 - A01424831
//

#include <iostream>
#include "TStack.h"
using namespace std;

#define MAX 200

int main() {
    char expression[MAX]; // Creates string variable that will store the mathematic expression
    bool valid = true; // Boolean variable that checks if our expression is valid
   
    cin.get(expression); // Receives string input and stores it in the expression variable

    char *expressionPointer=expression; // Makes a char type pointer that points to the expression variable

    TStack <char> *stack=new TStack<char>(); // Creates stack object

    while (*expressionPointer) { // Traverses our string
        if (*expressionPointer == '(' || *expressionPointer == '[' || *expressionPointer == '{') { // If it encounters opening symbol
            stack->push(expressionPointer); // Pushes it into our stack
        }
        if (*expressionPointer == ')' || *expressionPointer == ']' || *expressionPointer == '}') { // If it encounters closing symbol
            if (stack->empty()) { // Checks if our stack is empty
                valid = false; // If it is empty, then it is an invalid expression because there is no opening symbol to match it
            }
            else { // If it is not empty
                char *popped = stack->pop(); // Pops the top element
                switch(*expressionPointer) { 
                    case ')': if (*popped != '(') {valid = false;}; break; // If the closing symbol is a ')' but the popped element isn't a '('
                    case ']': if (*popped != '[') {valid = false;}; break; // it becomes an invalid expression
                    case '}': if (*popped != '{') {valid = false;}; break; // Same process for all the other symbols
                }
            }
        }
    }
    if (!stack->empty()) { // If by the time we finish traversing the string, our stack is NOT empty
        valid = false; // Then it is an invalid expression, because there is an opening symbol waiting to be closed (and therefore, popped)
    }

    if (valid) {
        cout << "Valid expression" << endl; // If valid, valid
    }
    else {
        cout << "Invalid expression" << endl; // If not valid, not valid
    }
}
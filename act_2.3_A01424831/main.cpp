//
// Antonio Marbán Regalado - A01424831
// 29/10/2023
// Act 2.3
// Stack Implementation to validate the correct use of parentheses in a mathematical expression
//

#include <iostream>
#include "TStack.h"
using namespace std;

#define MAX 200

int main() {
    char expression[MAX]; // Creates string variable that will store the mathematic expression
    bool valid = true; // Boolean variable that checks if our expression is valid
    
    while (true) { // Loops until an empty expression is entered
        cout << "Please enter a mathematic expression to validate its parentheses use or enter an empty expression to end the program." << endl;
        cout << ">>>";

        cin.get(expression, MAX); // Receives string input and stores it in the expression variable
        cin.ignore(); // Clears input buffer so it can ask for the input again in the next iteration of the while loop.
        if (expression[0] == '\0') { // Checks if the expression entered is empty (\0 is the NULL equivalent)
            cout << "\nEMPTY EXPRESSION.\n"; // If empty, the program stops
            break; // Exits the while loop
        }

        // If not empty, executes the program:

        char * expressionPointer = expression; // Makes a char type pointer that is set to the expression which is a char[]

        TStack <char> *stack = new TStack<char>(); // Creates stack object
        while (*expressionPointer) { // Traverses our string
            cout << *expressionPointer; // Prints as it reads
            if (*expressionPointer == '(' || *expressionPointer == '[' || *expressionPointer == '{') { // If it encounters opening symbol
                cout << "\n\nOPENING SYMBOL DETECTED: " << *expressionPointer << endl;
                stack->push(expressionPointer); // Pushes the opening symbol
                cout << "\n>>>"; 
            }
            if (*expressionPointer == ')' || *expressionPointer == ']' || *expressionPointer == '}') { // If it encounters closing symbol
                cout << "\n\nCLOSING SYMBOL DETECTED: " << *expressionPointer << endl;
                if (stack->empty()) { // Checks if our stack is empty
                    cout << "\nSTACK EMPTY\n";
                    valid = false; // If it is empty, then it is an invalid expression because there is no opening symbol to match it
                }
                else { // If it is not empty
                    cout << "\nSTACK NOT EMPTY\n";
                    char popped = *stack->pop(); // Pops the top element
                    cout << "\nTHIS IS THE POPPED ELEMENT: " << popped << endl;
                    cout << "\nTHIS IS THE *expressionPointer: " << *expressionPointer << endl;

                    // If the closing symbol is a ')' but the popped element isn't a '(' it becomes an invalid expression
                    // it becomes an invalid expression
                    // Same process for all the other symbols
                    switch(*expressionPointer) { 
                        case ')': if (popped != '(') {
                            cout << "\nCLOSING SYMBOL DOES NOT MATCH OPENING SYMBOL" << endl; 
                            valid = false;
                        } else cout << "\nCLOSING SYMBOL MATCHES OPENING SYMBOL" << endl;
                        break; 
                        case ']': if (popped != '[') {
                            cout << "\nCLOSING SYMBOL DOES NOT MATCH OPENING SYMBOL" << endl; 
                            valid = false; 
                        } else cout << "\nCLOSING SYMBOL MATCHES OPENING SYMBOL" << endl;
                        break;
                        case '}': if (popped != '{') {
                            cout << "\nCLOSING SYMBOL DOES NOT MATCH OPENING SYMBOL" << endl; 
                            valid = false;
                        } else cout << "\nCLOSING SYMBOL MATCHES OPENING SYMBOL" << endl;
                        break; 
                    }
                }
                cout << "\n>>>";
            }
            expressionPointer++;
        }
        if (!stack->empty()) { // If by the time we finish traversing the string, our stack is NOT empty
            cout << "\nEXPECTED A CLOSING SYMBOL\n";
            valid = false; // Then it is an invalid expression, because there is an opening symbol waiting to be closed (and therefore, popped)
        }

        cout << endl;
        if (valid) {
            cout << "Valid expression" << endl; // If valid, valid
        }
        else {
            cout << "Invalid expression" << endl; // If not valid, not valid
        }
    }
    cout << "\nProgram finished\n";
}
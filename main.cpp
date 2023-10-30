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
    char expression[MAX];
    // char expression[MAX] = "[{A+B + (a+b) a+b }]"; // Creates string variable that will store the mathematic expression
    bool valid = true; // Boolean variable that checks if our expression is valid
   
    cout << "Please enter a mathematic expression to validate its parentheses use." << endl;
    cout << ">>>";

    cin.get(expression, MAX); // Receives string input and stores it in the expression variable

    char * expressionPointer = expression; // Makes a char type pointer that is set to the expression which is a char[]

    TStack <char> *stack = new TStack<char>(); // Creates stack object

    char expressionArray[MAX];
    int index = 0; // Needed to make the push() function parameters work

    while (*expressionPointer) { // Traverses our string
        cout << *expressionPointer;
        if (*expressionPointer == '(' || *expressionPointer == '[' || *expressionPointer == '{') { // If it encounters opening symbol
            cout << "\n\nOPENING SYMBOL" << endl;
            expressionArray[index] = *expressionPointer; // Sets current index on expressionArray to what the pointer is pointing to
            stack->push(&expressionArray[index]);
            index++; // 
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
                cout << "\nTHIS IS AT THE TOP OF THE STACK (TO BE POPPED): " << stack->stacktop() << endl;
                char popped = *stack->pop(); // Pops the top element
                cout << "\nTHIS IS THE POPPED ELEMENT: " << popped << endl;
                // cout << "\nTHIS IS AT THE TOP OF THE STACK NOW: " << stack->stacktop() << endl;

                cout << "\nTHIS IS THE *expressionPointer: " << *expressionPointer << endl;

                // If the closing symbol is a ')' but the popped element isn't a '(' it becomes an invalid expression
                // it becomes an invalid expression
                // Same process for all the other symbols
                switch(*expressionPointer) { 
                    case ')': if (popped != '(') {
                        cout << "\nPOPPED ELEMENT DOES NOT MATCH STACKTOP ELEMENT" << endl; 
                        valid = false;
                    } else cout << "\nPOPPED ELEMENT MATCHES STACKTOP ELEMENT" << endl;
                    break; 
                    case ']': if (popped != '[') {
                        cout << "\nPOPPED ELEMENT DOES NOT MATCH STACKTOP ELEMENT" << endl; 
                        valid = false; 
                    } else cout << "\nPOPPED ELEMENT MATCHES STACKTOP ELEMENT" << endl;
                    break;
                    case '}': if (popped != '{') {
                        cout << "\nPOPPED ELEMENT DOES NOT MATCH STACKTOP ELEMENT" << endl; 
                        valid = false;
                    } else cout << "\nPOPPED ELEMENT MATCHES STACKTOP ELEMENT" << endl;
                    break; 
                }
            }
            cout << "\n>>>";
        }
        expressionPointer++;
    }
    cout << "\n\nWhHILE LOOP FINISHED." << endl;
    if (!stack->empty()) { // If by the time we finish traversing the string, our stack is NOT empty
        cout << "\nSTACK NOT EMPTY\n";
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

//--------------------------------------------------------------------
//
//  Laboratory 6                                           PostFix.cpp
//
//  Version # 1
//  Date Originally Written: 03/02/2021 
//  Date Last Modified: 03/13/2021
//  Authors: Manraj Singh (Programming and documentation) & 
//           Corey Shimshock (Documentation and programming)
//  Purpose: Test for programming exercise 1, used to understand postfix and infix
//           notation for arithmetic stack implementation.
//
//--------------------------------------------------------------------
#include <iostream>
#include <string>
#include <cmath>  //exponents
#include "LinkedStacks.cpp"
using namespace std;

///Preconditions: There are valid numbers to perform operations on in the postfix
///Postconditions: The operands are operated on by corresponding operators and stored in result variable.
///Inputs: Two integer operands.
///Outputs: An operator performs the correct calculation on the operands, and a result is outputted.
double performCalculations(const double firstNum, const double secondNum, char whichOp) {
    //result of x (+ || - || * || / || ^) y
    double result = 0;

    //switch function checks which operator is used in the postfix, and returns result
    switch (whichOp) {
    case '*': return firstNum * secondNum;
    case '/': return secondNum / firstNum;
    case '+': return secondNum + firstNum;
    case '-': return secondNum - firstNum;
    case '^': return pow(secondNum, firstNum);
    //if the operator is not listed, output error
    default: cout << "Operator is not supported!" << endl;
    }
}

///Preconditions: There must be valid numbers to push and pop in the linked list implementation.
///Postconditions: The function pushes the number values in the list to continue the multiple operations.
///Inputs: Multiple number values in the postfix alongside their respective operators (multiple calculations made).
///Outputs: The overall result of the postfix input, pushed along by the linked list stack.
double linkedCalculation(string member) {
    //Linked stack objects of type double and char to push or pop
    LinkedStacks<double> numValues;
    LinkedStacks<char> nonNumValues;
    //final resultant value
    double result = 0;

    //pop the objects' memory so that there is no unnecessary memory usage
    numValues.clearStack();
    nonNumValues.clearStack();

    //for loop goes through each calculation in the postfix and pushes them to layer the calculations
    for (int i = 0; i < member.length(); i++) {
        //if the value is not a number, push them further back as a character ASCII equivalent
        if (member[i] != '^' && member[i] != '+' && member[i] != '-' && member[i] != '*' 
            && member[i] != '/' && member[i] != ' ') {
            numValues.push(member[i] - 48);
        }
        //if the value is a whitespace, push it further back
        else if (member[i] == ' ')
            nonNumValues.push(member[i]);
        //the non-final results are popped
        else {
            double firstResult = numValues.pop();
            double secondResult = numValues.pop();

            //the final result is calculated and pushed to the top
            result = performCalculations(firstResult, secondResult, member[i]);
            numValues.push(result);
        }
    }
    return result;
}

int main() {
    //This file conducts test plan 6-2 automatically from pre-inputted postfix operations to work on.
    cout << "Test Plan 6-2: " << endl;
    cout << "==============================================" << endl;

    //One operator case
    cout << "Test case 1 (One operator): " << endl;
    cout << "Postfix: 3 4 + " << endl;
    cout << "Infix: 3 + 4" << endl;
    cout << "Result: " << linkedCalculation("3 4 +") << endl;

    cout << "\n==============================================" << endl;

    //Nested operator case
    cout << "Test case 2 (Nested operators): " << endl;
    cout << "Postfix: 3 4 + 5 2 / * " << endl;
    cout << "Infix: (3 + 4) * (5 / 2)" << endl;
    cout << "Result: " << linkedCalculation("3 4 + 5 2 / *") << endl;

    cout << "\n==============================================" << endl;

    //Uneven nesting case
    cout << "Test case 3 (Uneven nesting): " << endl;
    cout << "Postfix: 9 3 + 2 + 1 -" << endl;
    cout << "Infix: 9 + 3 + 2 - 1" << endl;
    cout << "Result: " << linkedCalculation("9 3 + 2 + 1 -") << endl;

    cout << "\n==============================================" << endl;

    //All operators at end of calculation case
    cout << "Test case 4 (All operators at end): " << endl;
    cout << "Postfix: 4 6 7 5 - + *" << endl;
    cout << "Infix: 4 * (6 + 7 - 5)" << endl;
    cout << "Result: " << linkedCalculation("4 6 7 5 - + *") << endl;

    cout << "\n==============================================" << endl;

    //0 divided by a number case
    cout << "Test case 5 (Zero dividend): " << endl;
    cout << "Postfix: 0 2 /" << endl;
    cout << "Infix: (0 / 2)" << endl;
    cout << "Result: " << linkedCalculation("0 2 /") << endl;

    cout << "\n==============================================" << endl;

    //one single number case
    cout << "Test case 6 (Single number): " << endl;
    cout << "Postfix: 7 0 +" << endl;
    cout << "Infix: (7 + 0)" << endl;
    cout << "Result: " << linkedCalculation("7 0 +") << endl;

    cout << "\n==============================================" << endl;

    //end of exercise 1
    return 0;
}


//--------------------------------------------------------------------
//
//  Laboratory 6                                             test6.cpp
//
//  Version # 1
//  Date Originally Written: 03/02/2021
//  Date Last Modified: 03/13/2021
//  Authors: Manraj Singh (Programming and documentation) &
//           Corey Shimshock (Documentation and programming)
//  Purpose: Test program plan 9-1 for the operations in the Stack ADT, 
//           allowing user input for stack popping and pushing (array or linked list type).
//
//--------------------------------------------------------------------
#include <iostream>
#include "FileConfig.h"
using namespace std;

#if LAB6_TEST1
#  include "ArrayStacks.cpp"
#else
#  include "LinkedStacks.cpp"
#endif

///Preconditions: The test program is run, so that the menu can be shown.
///Postconditions: The menu is shown for the user to manipulate the stack.
///Inputs: No input
///Outputs: The helper menu for the user to use as a guide to manipulate the stack.
void print_help()
{
	cout << "===========================================*" << endl;
	cout << "* Commands:                                =" << endl;
	cout << "=   H: Help (displays this menu)           *" << endl;
	cout << "*   +: Push (enter then enter char or #)   =" << endl;
	cout << "=   -: Pop recent value                    *" << endl;
	cout << "*   C: Clear                               =" << endl;
	cout << "=   E: Empty stack?                        *" << endl;
	cout << "*   F: Full stack?                         =" << endl;
	cout << "=   Q: Quit the test program               *" << endl;
	cout << "*===========================================" << endl << endl;
}

///Preconditions: The stack implementations are valid so the user can push and pop values into it
///Postconditions: The stack is manipulated by the user to push, pop, and check the stack's status.
///Inputs: User input to push, pop, and check.
///Outputs: The user-manipulated stack.
template <typename TypeOfData>
void test_stack(Stack<TypeOfData>& testStack)
{
	//the user's pushed integer or character
	TypeOfData userPushValue;
	
	//the command the user wants to manipulate the stack with
	char userStackCommand;                       
	
	//menu outputted
	print_help();

	//do while the user does not input 'Q' to quit the program.
	do {
		//Output the stack
		testStack.showStructure();

		//Prompt user for command
		cout << "Command: ";              
		cin >> userStackCommand;

		//if the user inputs +, then prompt them for a value to push
		if (userStackCommand == '+')
			cin >> userPushValue;

		//try-catch to catch exceptions when user inputs invalid command
		try {
			//switch case checks for user's stack command (push, pop, peek, check, etc).
			switch (userStackCommand) {
			
			//output menu for help
			case 'H': case 'h':
				print_help();
				break;

			//push command
			case '+':                                  
				cout << "Push " << userPushValue << endl;
				testStack.push(userPushValue);
				break;

			//pop command
			case '-':                                  
				cout << "Popped " << testStack.pop() << endl;
				break;

			//Clear the whole stack
			case 'C': case 'c':                      
				cout << "Clear the stack" << endl;
				testStack.clearStack();
				break;

		    //bool check if stack is empty or not
			case 'E': case 'e':                     
				if (testStack.isStackEmpty())
					cout << "Stack is empty!" << endl;
				else
					cout << "Stack is NOT empty!" << endl;
				break;

			//bool check if stack is full or not
			case 'F': case 'f':                      
				if (testStack.isStackFull())
					cout << "Stack is full!" << endl;
				else
					cout << "Stack is NOT full!" << endl;
				break;
				
			//Quit the program test plan 9-1
			case 'Q': case 'q':        
				break;

			//If user inputs invalid command
			default:       
				cout << "Invalid command!" << endl;
			}
		}

		//catch statement
		catch (logic_error e) {
			cout << "Error: " << e.what() << endl;
		}

		//do while the user does not quit, or program ends.
	} while (cin && userStackCommand != 'Q' && userStackCommand != 'q');
}

int main() {
//if the config is set to 1, then array stack
#if LAB6_TEST1
	cout << "Testing array implementation" << endl;
	ArrayStacks<char> s1;
	test_stack(s1);

//if the config is set to 0, then link stack
#else
	cout << "Testing linked implementation" << endl;
	LinkedStacks<char> s2;
	test_stack(s2);
#endif
}

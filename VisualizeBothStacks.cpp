//--------------------------------------------------------------------
//
//  Laboratory 6                                             Show6.cpp
// 
//  Physical template creating class for Stack ADT type, if array or 
//  linked list is needed for the program.
//
//--------------------------------------------------------------------
#include <iostream>
#include "FileConfig.h"
#include "ArrayStacks.h"
#include "LinkedStacks.h"
using namespace std;

//=========================================================================================

///Preconditions: The array stack implementation is config at 0
///Postconditions: The stack is outputted with array implementation in mind. For testing & debugging
///Inputs: Inputs come from user commands, which output and are visualized in the stack.
///Outputs: Stack that visualizes user's push and pop commands. If empty stack, output "empty"
template <typename TypeOfData>
void ArrayStacks<TypeOfData>::showStructure() const
{
	//if the stack is empty, output empty
	if (isStackEmpty())
		cout << "Empty stack!";
	//else, loop through stack, output top and other values until max end
	else {
		int j;
		cout << "Top: " << topStack << endl;
		for (j = 0; j < maxPossibleStackSize; j++)
			cout << j << "\t";
		cout << endl;
		//output top value with brackets
		for (j = 0; j <= topStack; j++)
		{
			if (j == topStack)
				cout << '[' << valData[j] << ']' << "\t"; // Identify top
			else
				cout << valData[j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

//=========================================================================================

///Preconditions: The linked list stack implementation is config at 1
///Postconditions: The stack is outputted with linked list implementation in mind. For testing & debugging
///Inputs: Inputs come from user commands, which output and are visualized in the stack.
///Outputs: Stack that visualizes user's push and pop commands. If empty stack, outputs "empty"
template <typename TypeOfData>
void LinkedStacks<TypeOfData>::showStructure() const
{
	//if empty, output stack as empty
	if(isStackEmpty())
		cout << "Empty stack!" << endl;
	//else, output stack utilizing node values
	else {
		cout << "Top\t";
	for (LinkNodeStack* temp = topOfStack; temp != 0; temp = temp->next) {
		//output top value with brackets
		if( temp == topOfStack )
		cout << '[' << temp->dataVal << "]\t";
		else
		cout << temp->dataVal << "\t";
	}
		cout << "Bottom" << endl;
	}
}
//=========================================================================================
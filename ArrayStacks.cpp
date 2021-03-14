//--------------------------------------------------------------------
//
//  Laboratory 6                                         StackArray.cpp
// 
//  Function definitions for the array implementation of the Stack ADT
//
//--------------------------------------------------------------------
#include <iostream>
#include "ArrayStacks.h"

///Preconditions: The max size has to be defined and the dataItems have to be initialized with a value.
///Postconditions: dataItems are instantiated as a new dataType
///Inputs: dataItems are inputted by the user until the max size is reached.
///Outputs: Values stored for the stack until called by showStructure
template <typename TypeOfData>
ArrayStacks<TypeOfData>::ArrayStacks(int maximumSize) : maxPossibleStackSize(maximumSize), topStack(-1) {
    valData = new TypeOfData[maxPossibleStackSize];
}

///Preconditions: dataItems must be initialized and have values to store in array stack
///Postconditions: All values in array are indexed for the stack.
///Inputs: User values for the stack
///Outputs: The values are indexed and their memories are copied, output when user calls showStructure.
template <typename TypeOfData>
ArrayStacks<TypeOfData>::ArrayStacks(const ArrayStacks& another) : maxPossibleStackSize(another.maxPossibleStackSize), topStack(another.topStack) {
    //data items initialized 
    valData = new TypeOfData[maxPossibleStackSize];

    //for each value i until the top is reached, array stores value as a copy of data member.
    for (int i = 0; i < topStack; i++)
        valData[i] = another.valData[i];
}

///Preconditions: The values must have a valid memory address and equal to other.
///Postconditions: The values are either deleted and recreated if not equal, or are returned.
///Inputs: The data values from the user.
///Outputs: The data items in an indexed array, waiting to be called by showStructure to output.
template <typename TypeOfData>
ArrayStacks<TypeOfData>& ArrayStacks<TypeOfData>:: operator=(const ArrayStacks& another) {
   //member function has this pointer to access the memory address of data values
    //if the this pointer is not equal to the memory value, the data items are deleted
    if (this != another) {
        maxPossibleStackSize = another.maxPossibleStackSize;
        delete valData;
        topStack = another.topStack;

        //new data items are initialized
        valData = new TypeOfData[maxPossibleStackSize];

        //for each index until the top, the values are stored in an array
        for (int k = 0; k < topStack; k++) 
            valData[k] = another.valData[k];
    }
    return this;
}

///Preconditions: There should be memory of values to delete memory addresses.
///Postconditions: The memory is cleared of the data items
///Inputs: User inputs to clear memory of data items
///Outputs: Cleared data items.
template <typename TypeOfData>
ArrayStacks<TypeOfData>::~ArrayStacks() {
    //destructor deletes data items
    delete valData;
}

///Preconditions: Stack must be valid so it can exist and the bool can look at it.
///Postconditions: If the stack is full, an exception is thrown so no more values can be pushed to stack.
///Inputs: User input push to stack.
///Outputs: Error message that stack is full.
template <typename TypeOfData>
void ArrayStacks<TypeOfData>::push(const TypeOfData& newDataItem) throw (logic_error) {
    //if stack full, throw exception message
    if (isStackFull())
        throw logic_error("Stack is full! Cannot push more values to stack!");

    //index incremented value of variable top before processing current statement
    valData[++topStack] = newDataItem;
}

///Preconditions: Stack must be valid so it can exist and the bool can look at it.
///Postconditions: If the stack is full, an exception is thrown so no more values can be popped from stack.
///Inputs: User input pop from stack.
///Outputs: Error message that stack is empty.
template <typename TypeOfData>
TypeOfData ArrayStacks<TypeOfData>::pop() throw(logic_error) {
    //if stack empty, throw exception message
    if (isStackEmpty())
        throw logic_error("Stack is empty! Cannot pop more values from stack!");

    //top is decremented and next index returned
    topStack--;
    return valData[topStack + 1];
}

///Preconditions: Stack must be valid and instantiated.
///Postconditions: Stack is cleared.
///Inputs: User input to clear stack automatically.
///Outputs: Stack clears and no values in there anymore.
template <typename TypeOfData>
void ArrayStacks<TypeOfData>::clearStack() {
    //top is equated to -1, so there is no value in there now
    topStack = -1;
}

///Preconditions: Stack must be valid and defined to check.
///Postconditions: Stack is checked and either true or false is returned for being empty.
///Inputs: User input to check if empty stack
///Outputs: Either stack is empty or not empty outputted
template <typename TypeOfData>
bool ArrayStacks<TypeOfData>::isStackEmpty() const {
    //top is equal to -1, so if equal to that, then empty.
    return topStack == -1;
}

///Preconditions: Stack must be valid and defined to check.
///Postconditions: Stack is checked and either true or false is returned for being full.
///Inputs: User input to check if full stack
///Outputs: Either stack is full or not full outputted
template <typename TypeOfData>
bool ArrayStacks<TypeOfData>::isStackFull() const {
    //top is equal to max size -1, so if there are no values behind it, then not full.
    return topStack == maxPossibleStackSize - 1;
}

///Preconditions: The array stack implementation is config at 0
///Postconditions: The stack is outputted with array implementation in mind. For testing & debugging
///Inputs: Inputs come from user commands, which output and are visualized in the stack.
///Outputs: Stack that visualizes user's push and pop commands. If empty stack, output "empty"
template <typename TypeOfData>
void ArrayStacks<TypeOfData>::showStructure() const {
    //if the stack is empty, output empty
    if (isStackEmpty())
        cout << "Empty stack!" << endl;
    //else, loop through stack, output top and other values until max end
    else {
        int index;
        cout << "Top = " << topStack << endl;
        for (index = 0; index < maxPossibleStackSize; index++)
            cout << index << "\t";
        cout << endl;
        //output top value with brackets
        for (index = 0; index <= topStack; index++)
        {
            if (index == topStack)
                cout << '[' << valData[index] << ']' << "\t"; // Identify top
            else
                cout << valData[index] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
//--------------------------------------------------------------------
//
//  Laboratory 6                                         StackLinked.cpp                   
// 
//  Function definitions for the linked list implementation of the Stack ADT
//
//--------------------------------------------------------------------
#include <iostream>
#include "LinkedStacks.h"

///Preconditions: Stack must be valid and defined.
///Postconditions: Member function values are instantiated for pointer and node data.
///Inputs: No inputs now.
///Outputs: Data items are equated to nodes and pointers are there for memory addresses
template <typename TypeOfData>
LinkedStacks<TypeOfData>::LinkNodeStack::LinkNodeStack(const TypeOfData& nodeData, LinkNodeStack* nextPtr) :
    dataVal(nodeData), next(nextPtr) {
}

///Preconditions: Stack must be valid and defined.
///Postconditions: Top values is equated to null pointer before values added.
///Inputs: User input of first value.
///Outputs: No output, top value of stack is equal to null pointer.
template <typename TypeOfData>
LinkedStacks<TypeOfData>::LinkedStacks(int maxPossibleNumber) {
    topOfStack = nullptr;
}

///Preconditions: Stack must be valid and defined.
///Postconditions: A placeholder value is added to allow for values to be pushed.
///Inputs: User input of values.
///Outputs: Value is pushed to stack.
template <typename TypeOfData>
LinkedStacks<TypeOfData>::LinkedStacks(const LinkedStacks& another) {
    //data type object created.
    TypeOfData* holder;
    topOfStack = nullptr;

    //while the top is not null, the placeholder is set to the top and values are pushed.
    while (topOfStack != nullptr) {
        holder = another.topOfStack;

        //for every index until the max, the place holder is sent to next value in list.
        for (int index = 0; index < another.maxNumber - 1; index++)
            holder = holder->next;

        //the place holders are pushed to the list
        push(holder->dataVal);
    }
}

///Preconditions: Stack must be valid and defined.
///Postconditions: The values are pushed to the stack unless the memory address is not equal to the pointer
///Inputs: User input of values.
///Outputs: Memory address of values as they are pushed to the stack.
template <typename TypeOfData>
LinkedStacks<TypeOfData>& LinkedStacks<TypeOfData>::operator=(const LinkedStacks& another) {
    //if this is not equal to address of other, then it is cleared   
    if (this != &another) {
        clearStack();

        //object of type stacknode
        LinkNodeStack* holder;
        //while the top of the stack is not equal to null, the value is at the top
        while (topOfStack != nullptr) {
            holder = another.topOfStack;

            //for every index until max, the values are pushed to the list
            for (int index = 0; index < this.maxNumber; index++) 
                holder = holder->next;

            //push values to list
            push(holder->dataVal);
        }
    }
    //this is returned
    return *this;
}

///Preconditions: Stack must be valid with values to clear.
///Postconditions: Stack is cleared of memory.
///Inputs: User input to clear stack.
///Outputs: Stack is cleared with no values left in stack.
template <typename TypeOfData>
LinkedStacks<TypeOfData>::~LinkedStacks() {
    clearStack();
}

///Preconditions: Stack must be valid and defined. 
///Postconditions: Value is pushed to stack unless the stack is full.
///Inputs: User input to push values.
///Outputs: Stack with pushed value, or an exception message if stack is full.
template <typename TypeOfData>
void LinkedStacks<TypeOfData>::push(const TypeOfData& newDataItem) throw(logic_error) {
    //top of stack is instantiated and count increments when values are pushed
    topOfStack = new LinkNodeStack(newDataItem, topOfStack);
    count++;
}

///Preconditions: Stack must be valid and defined. 
///Postconditions: Stack has values popped, or if empty has exception message thrown.
///Inputs: User input to pop values.
///Outputs: Stack with popped value, or an exception message if stack is empty.
template <typename TypeOfData>
TypeOfData LinkedStacks<TypeOfData>::pop() throw (logic_error) {
    //if the stack is empty, the error is thrown so no more can be popped
    if (isStackEmpty())
        throw logic_error("Stack is empty. Cannot pop to empty stack.");

    //object is used to pop values and decrement count of stack.
    TypeOfData popTemp = topOfStack->dataVal;
    topOfStack = topOfStack->next;
    count--;

    //value is returned of the popped stack.
    return popTemp;
}

///Preconditions: Stack must be valid and defined.
///Postconditions: Stack is cleared of values.
///Inputs: User input to clear stack.
///Outputs: A cleared stack with all values popped.
template <typename TypeOfData>
void LinkedStacks<TypeOfData>::clearStack() {
    //while the top of the stack is not null, values can be popped.
    while (topOfStack != nullptr) 
        pop();
}

///Preconditions: Stack must be valid and defined.
///Postconditions: Stack returns message if empty or not.
///Inputs: User input to check if stack empty.
///Outputs: Message of empty or not empty stack.
template <typename TypeOfData>
bool LinkedStacks<TypeOfData>::isStackEmpty() const {
    //if top has a value, it is not empty
    return topOfStack == nullptr;
}

///Preconditions: Stack must be valid and defined.
///Postconditions: Stack returns message if full or not.
///Inputs: User input to check if stack full.
///Outputs: Message of full or not full stack.
template <typename TypeOfData>
bool LinkedStacks<TypeOfData>::isStackFull() const {
    //the count is returned, if count is equal to max, then full
    return count == maxStackSize;
}

///Preconditions: The linked list stack implementation is config at 1
///Postconditions: The stack is outputted with linked list implementation in mind. For testing & debugging
///Inputs: Inputs come from user commands, which output and are visualized in the stack.
///Outputs: Stack that visualizes user's push and pop commands. If empty stack, outputs "empty"
template <typename TypeOfData>
void LinkedStacks<TypeOfData>::showStructure() const {
    //if empty, output stack as empty
    if (isStackEmpty())
        cout << "Empty stack!" << endl;
    //else, output stack utilizing node values
    else {
        cout << "Top\t";
        for (LinkNodeStack* temp = topOfStack; temp != 0; temp = temp->next) {
            //output top value with brackets
            if (temp == topOfStack)
                cout << '[' << temp->dataVal << "]\t";
            else
                cout << temp->dataVal << "\t";
        }
        cout << "Bottom" << endl;
    }
}
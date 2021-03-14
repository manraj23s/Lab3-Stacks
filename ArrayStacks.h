#pragma once
//--------------------------------------------------------------------
//
//  Laboratory 6                                         StackArray.h
// 
//  Class declaration for the array implementation of the Stack ADT
//
//--------------------------------------------------------------------
#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>
#include <iostream>
#include "BaseStack.h"
using namespace std;

//--------------------------------------------------------------------
//this array stack class is inherited from the foundation stack class
template <typename TypeOfData>
class ArrayStacks : public Stack<TypeOfData> {
public:
    //stack max size is what the foundation stack says, which is 8
    ArrayStacks(int maximumSize = Stack<TypeOfData>::MAX_STACK_SIZE);
    //used to check top and max size of stack
    ArrayStacks(const ArrayStacks& another);
    //operator and this interact to check addresses
    ArrayStacks& operator=(const ArrayStacks& another);
    //stackArray destructor
    ~ArrayStacks();

    //push and pop try-catch exception possibilities
    void push(const TypeOfData& newDataItem) throw (logic_error);
    TypeOfData pop() throw (logic_error);

    //clear the stack
    void clearStack();

    //bool to check if stack empty or full
    bool isStackEmpty() const;
    bool isStackFull() const;

    //show stack structure from show6
    void showStructure() const;

 //private class variables for StackArray
private:
    TypeOfData* valData;
    int maxPossibleStackSize;
    int topStack;
};
#endif		//#ifndef STACKARRAY_H

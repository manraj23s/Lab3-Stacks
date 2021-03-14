#pragma once
//--------------------------------------------------------------------
//
//  Laboratory 6                                               Stack.h
// 
//  Class declaration of the abstract class interface to be used as
//  the basis for implementations of the Stack ADT.
//
//--------------------------------------------------------------------

#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <iostream>
using namespace std;

//--------------------------------------------------------------------

template <typename TypeOfData>
class Stack {
public:
    //max stack size can be 8
    static const int MAX_STACK_SIZE = 8;

    //destructor for stack
    virtual ~Stack();

    //push and pop try-catch exception possibilities
    virtual void push(const TypeOfData& newDataItem) throw (logic_error) = 0;
    virtual TypeOfData pop() throw (logic_error) = 0;

    //clear the stack
    virtual void clearStack() = 0;

    //bool checks if stack empty or full
    virtual bool isStackEmpty() const = 0;
    virtual bool isStackFull() const = 0;

    //show the structure of the stack from Show6
    virtual void showStructure() const = 0;
};

//destructor for stack, which is usually not worth separate class implementation
template <typename TypeOfData>
Stack<TypeOfData>::~Stack()
{}
#endif		// #ifndef STACK_H

//--------------------------------------------------------------------
//
//  Laboratory 6                                         StackLinked.h                   
// 
//  Class declaration for the linked list implementation of the Stack ADT
//
//--------------------------------------------------------------------

#ifndef STACKLINKED_H
#define STACKLINKED_H

#include <stdexcept>
#include <iostream>
#include "BaseStack.h"
using namespace std;

//--------------------------------------------------------------------
//this linked list stack class is inherited from the foundation stack class
template <typename TypeOfData>
class LinkedStacks : public Stack<TypeOfData> {
public:

    //two variables initialized to count values and inherit stack's max size of 8
    int count = 0;
    int maxStackSize = Stack<TypeOfData>::MAX_STACK_SIZE;

    //stack linked has a max value of 8
    LinkedStacks(int maxPossibleNumber = Stack<TypeOfData>::MAX_STACK_SIZE);
    //used to check top and max size of stack
    LinkedStacks(const LinkedStacks& another);
    //operator and this interact to check addresses
    LinkedStacks& operator=(const LinkedStacks& another);
    //destructor
    ~LinkedStacks();

    //push and pop try catch exception possibilities
    void push(const TypeOfData& newDataItem) throw (logic_error);
    TypeOfData pop() throw (logic_error);

    //clear the stack
    void clearStack();

    //bool to check if stack is full or empty
    bool isStackEmpty() const;
    bool isStackFull() const;

    //show the structure of the stack with show6
    void showStructure() const;
private:
    class LinkNodeStack {
    public:
        //stack node uses pointers to utilize memory data
        LinkNodeStack(const TypeOfData& nodeData, LinkNodeStack* nextPtr);

        //objects of data and stack type
        TypeOfData dataVal;
        LinkNodeStack* next;
    };
    LinkNodeStack* topOfStack;
};
#endif		//#ifndef STACKARRAY_H
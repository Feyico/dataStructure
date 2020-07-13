#ifndef _HEAPSTACK_H_
#define _HEAPSTACK_H_

#include "Common.h"

typedef int DataType;

class ArrayStack
{
private:
    enum {MAXSIZE = 10};
    DataType stack_list[MAXSIZE];
    int top; //栈顶
public:
    ArrayStack();
    //ArrayStack(const unsigned int size);
    ~ArrayStack();
public:
    //压栈出栈操作
    DSReturn Push(const DataType &item);//压栈操作
    DSReturn Pop(DataType &item);//出栈操作
    DSReturn ClearStack(void);//清空堆栈

    //访问栈顶
    DSReturn Peek(DataType &item)const;

private:
    //判断满和空
    bool IsFull(void)const { return this->top >= (MAXSIZE - 1) ? true:false; };
    bool IsEmpty(void)const { return this->top <= -1 ? true:false; };
};

#endif
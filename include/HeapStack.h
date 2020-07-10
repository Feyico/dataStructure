#ifndef _HEAPSTACK_H_
#define _HEAPSTACK_H_

#include "Common.h"

typedef int DataType;
const int MAXSIZE = 10;

class ArrayStack
{
private:
    DataType stack_list[MAXSIZE];//堆栈
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
    bool IsFull(void)const;
    bool IsEmpty(void)const;
};

#endif
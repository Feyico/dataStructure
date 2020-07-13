#ifndef _DOUBLESTACK_H_
#define _DOUBLESTACK_H_

#include "Common.h"

typedef int DataType;

class DoubleStack
{
private:
    enum {MAXSIZE = 10};
    int stack_size;
    DataType* double_stack_list;
    int top_1;
    int top_2;

public:
    explicit DoubleStack(int ss = MAXSIZE);
    DoubleStack(const DoubleStack &item);
    ~DoubleStack() { delete [] double_stack_list; };

public:
    DSReturn Pop(DataType& data, const int stackNumber = 1);
    DSReturn Push(const DataType& data, const int stackNumber = 1);

private:
    bool IsEmpty(void);
    bool IsFull(void);
};

#endif
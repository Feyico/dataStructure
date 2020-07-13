#include "DoubleStack.h"

/*构造函数*/
DoubleStack::DoubleStack(int ss) : stack_size(ss)
{
    this->double_stack_list = new DataType [stack_size];
    this->top_1 = -1;
    this->top_2 = stack_size;
}

/*拷贝构造函数*/
DoubleStack::DoubleStack(const DoubleStack &item)
{
    this->stack_size = item.stack_size;
    this->top_1 = item.top_1;
    this->top_2 = item.top_2;
    this->double_stack_list = item.double_stack_list;
    for (int i = 0; i < item.stack_size; i++)
    {
        this->double_stack_list[i] = item.double_stack_list[i];
    }
}

bool DoubleStack::IsEmpty(void)
{
    if (this->top_1 == -1 && this->top_2 == this->stack_size)
    {
        return true;
    }
    
    return false;
}

bool DoubleStack::IsFull(void)
{
    if ((this->top_2 - this->top_1) == 1)
    {
        return true;
    }
    
    return false;
}

DSReturn DoubleStack::Pop(DataType& data, const int stackNumber)
{
    if (1 == stackNumber)
    {
        if (this->top_1 != -1)
        {
            data = this->double_stack_list[this->top_1--];
        }
        
    }
    else if (2 == stackNumber)
    {
        if (this->top_2 != this->stack_size)
        {
            data = this->double_stack_list[this->top_2++];
        }
    }
    else
    {
        return DSRETERRVAILDCHECK;
    }

    return DSRETSUCCESS;
}

DSReturn DoubleStack::Push(const DataType& data, const int stackNumber)
{
    //判断栈是否已经满了
    if (!IsFull())
    {
        if (1 == stackNumber)
        {
            this->double_stack_list[++this->top_1] = data;
        }
        else if (2 == stackNumber)
        {
            this->double_stack_list[--this->top_2] = data;
        }
        else
        {
            return DSRETERRVAILDCHECK;
        }
    }
    else
    {
        return DSRETFULLSTACK;
    }
    
    return DSRETSUCCESS;
}
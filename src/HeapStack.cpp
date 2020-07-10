#include "HeapStack.h"

ArrayStack::ArrayStack()
{
    this->top = -1;//表示空栈
}

// ArrayStack::ArrayStack(const unsigned int size)
// {
//     this->top = -1;
// }

ArrayStack::~ArrayStack()
{
    this->top = -1;//表示空栈
    std::cout << "ArrayStack is died!" << std::endl;
}

//压栈出栈操作
DSReturn ArrayStack::Push(const DataType &item)
{
    if (!IsFull())
    {
        this->top++;
        this->stack_list[this->top] = item;
    }
    else
    {
        return DSRETPUSHERR;
    }

    return DSRETSUCCESS;
}

DSReturn ArrayStack::Pop(DataType &item)
{
    if (!IsEmpty())
    {
        this->top--;
        item = this->stack_list[this->top];
    }
    else
    {
        return DSRETPOPERR;
    }

    return DSRETSUCCESS;
}

DSReturn ArrayStack::ClearStack(void)
{
    if (!IsEmpty())
    {
        while (this->top > -1)
        {
            this->stack_list[this->top] = 0;
            this->top--;
        }
    }
    else
    {
        return DSRETEMPTYSTACK;
    }

    return DSRETSUCCESS;
}

//访问栈顶
DSReturn ArrayStack::Peek(DataType &item)const
{
    if (!IsEmpty())
    {
        item = this->stack_list[this->top];
    }
    else
    {
        return DSRETEMPTYSTACK;
    }

    return DSRETSUCCESS;
}

//判断满和空
bool ArrayStack::IsFull(void)const
{
    //当栈顶大于等于栈空间-1视为栈满
    return this->top >= (MAXSIZE - 1) ? true:false;
}
bool ArrayStack::IsEmpty(void)const
{
    return this->top <= -1 ? true:false;
}

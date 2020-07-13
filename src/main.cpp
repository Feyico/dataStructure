#include <stdlib.h>
#include "Common.h"
#include "HeapStack.h"
#include "DoubleStack.h"

#define STACKSIZE 10

using namespace std;

void OperateStack()
{
    int result = 0;
    int count = 0;
    int push_data = 0;
    int top_data = 0;
    // int top_data_2 = -1;
    DSReturn ret = DSRETSUCCESS;
    ArrayStack stackMember;

    for (int i = 0; i < STACKSIZE; i++)
    {
        push_data = rand();
        count++;
        cout << "Stack Count: " << count << " | " << "PUSH data: " << push_data << endl;
        ret = stackMember.Push(push_data);
        if (ret != DSRETSUCCESS)
        {
            break;
        }
    }

    ret = stackMember.Peek(top_data);
    cout << "Top Data: " << top_data << endl;

    for (int i = 0; i < STACKSIZE; i++)
    {
        ret = stackMember.Pop(result);
        if (ret == DSRETSUCCESS)
        {
            cout << "Stack Count: " << count << " | " << "POP Data: " << result << endl;
            count--;
        }
        else
        {
            cout << "RET: " << (int)ret << endl;
            break;
        }
    }

    // ret = stackMember.ClearStack();
    // if (ret == DSRETSUCCESS)
    // {
    //     ret = stackMember.Peek(top_data_2);
    //     cout << "Top Data: " << top_data_2 << endl;
    // }
    
    return;
}

void OperateDoubleStack()
{
    DSReturn ret = DSRETSUCCESS;
    DoubleStack dStackMember(STACKSIZE);
    int push_data = 0;
    int count = 0;
    int result = 0;

    for (int i = 0; i < STACKSIZE; i++)
    {
        push_data = rand();
        cout << "Stack Count: " << ++count << " | " << "PUSH data: " << push_data << endl;
        ret = dStackMember.Push(push_data, 1);
        if (ret != DSRETSUCCESS)
        {
            break;
        }
    }

    for (int i = 0; i < STACKSIZE; i++)
    {
        ret = dStackMember.Pop(result, 2);
        if (ret == DSRETSUCCESS)
        {
            cout << "Stack Count: " << count-- << " | " << "POP Data: " << result << endl;
        }
        else
        {
            break;
        }
    }
    
    return;
}

int main()
{
    OperateStack();
    OperateDoubleStack();
    return 0;
}
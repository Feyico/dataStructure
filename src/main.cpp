#include <stdlib.h>
#include "Common.h"
#include "HeapStack.h"
#include "DoubleStack.h"
#include "LinkStack.h"
#include "Test.h"
#include "Queue.h"

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

void MainMenu()
{
    int choose = 0;
    cout << "+----------------------------------------+" << endl;
    cout << "|    0.EXIT         1.TEST Stack         |" << endl;
    cout << "+----------------------------------------+" << endl;
    cout << "|    2.TEST Queue   3.TEST Chain Table   |" << endl;
    cout << "+----------------------------------------+" << endl;
    cout << "|    4.TEST Tree                         |" << endl;
    cout << "+----------------------------------------+" << endl;
    
    while (true)
    {
        cout << "Please enter your choice: ";
        cin >> choose;
        switch (choose)
        {
        case 0:
            cout << "Good Bye !" <<endl;
            return;
        case 1:
            OperateStack();
            return;
        case 2:
            OperateQueue();
            return;
        case 3:
            OperateLinkList();
            return;
        case 4:
            return;
        default:
            cout << "ERROR Choice!" << endl;
            break;
        }
    }
}

void StackMenu()
{
    cout<<"+===========================================+"<<endl;
    cout<<"|    1.测试元素进栈      2.测试元素出栈         |"<<endl;
    cout<<"+===========================================+"<<endl;
    cout<<"|    3.得到栈顶元素      4.判断栈是否为空       |"<<endl;
    cout<<"+===========================================+"<<endl;
    cout<<"|    5.打印栈元素        0.退出               |"<<endl;
    cout<<"+===========================================+"<<endl;
}

void OperateLinkStack()
{
    LinkStack<int> lStackMember;

    for(int i=0;i<10;i++)
    {
        lStackMember.Push(i+1);
    }
    StackMenu();
    int choose=1;
    int tmp;
    while(choose)
    {
        cout<<"请输入你的选择："<<endl;
        cin>>choose;
        switch (choose) 
        {
        
            case 1:
                {
                    cout<<"请输入你要进栈的元素：";
                    cin>>tmp;
                    lStackMember.Push(tmp);
                }
                break;
            case 2:
                {
                    int x;
                    lStackMember.Pop(x);
                    cout<<"出栈的元素为："<<x<<endl;
                }
                break;
            // case 3:
            //     {
            //         int x1;
            //         lStackMember.getTop(x1);
            //         cout<<"栈顶元素为："<<x1<<endl;
            //     }
            //     break;
            // case 4:
            //     if(lStackMember.isEmpty() == true){
            //         cout<<"该栈为空！"<<endl;
            //     }
            //     else{
            //         cout<<"栈不为空！"<<endl;
            //     }
            //     break;
            case 5:
                cout<<"栈的元素为:"<<endl;
                lStackMember.printStackData();
                break;
            case 0:
                return;
                break;
            default:
                break;
            cout << endl;
            StackMenu();
        }
        cout<<endl;
        StackMenu();
    }
    return;
}

int main()
{
    MainMenu();
    return 0;
}
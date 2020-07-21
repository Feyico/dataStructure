#include "TestQueue.h"
#include "Queue.h"

using namespace std;

void QueueMenu(void)
{
    cout<<"+===========================================+"<<endl;
    cout<<"|    1.测试进队列      2.测试出队列         |"<<endl;
    cout<<"+===========================================+"<<endl;
    cout<<"|    3.获取队列长度    4.打印队列元素       |"<<endl;
    cout<<"+===========================================+"<<endl;
    cout<<"|    0.退出                                 |"<<endl;
    cout<<"+===========================================+"<<endl;
    return;
}

void OperateQueue(void)
{
    Queue<int> qMember(10);

    for (int i = 0; i < 10; i++)
    {
        (void)qMember.Enqueue(i+1);
    }
    QueueMenu();

    int choose = 1;
    int tmp;
    int outQueueElement;
    int qLength;
    DSReturn ret = DSRETSUCCESS;
    while (true)
    {
        cout << "Please enter your choise: ";
        cin >> choose;
        switch (choose)
        {
            case 0:
                cout << "***Good Bye !" <<endl;
                return;
            case 1:
                cout << "Please enter the element which you want enqueue: ";
                cin >> tmp;
                ret = qMember.Enqueue(tmp);
                if (ret != DSRETSUCCESS)
                {
                    cout << "Enqueue ERROR!" << endl;
                }
                break;
            case 2:
                ret = qMember.Dequeue(outQueueElement);
                if (ret == DSRETSUCCESS)
                {
                    cout << "***Out Queue Element is: " << outQueueElement << endl;
                }
                break;
            case 3:
                qLength = qMember.GetQueueLength();
                cout << "***Queue Length is: " << qLength << endl;
                break;
            case 4:
                ret = qMember.PrintQueue();
                break;
            default:
                cout << "ERROR Choice!" << endl;
                break;
            cout << endl;
            QueueMenu();
        }
        cout << endl;
        QueueMenu();
    }
    return;
}
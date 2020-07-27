#include "Test.h"
#include "Queue.h"
#include "LinkList.h"

using namespace std;

/***************************  QUEUE  ****************************/
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
/***************************  QUEUE  ****************************/

/***************************  LinkList  ****************************/
void LinkListMenu(void)
{
    cout<<"+===========================================+"<<endl;
    cout<<"|    1.测试单链表插入   2.测试单链表删除     |"<<endl;
    cout<<"+===========================================+"<<endl;
    cout<<"|    3.获取链表长度    4.打印链表元素       |"<<endl;
    cout<<"+===========================================+"<<endl;
    cout<<"|    5.获取某一位置元素 0.退出              |"<<endl;
    cout<<"+===========================================+"<<endl;
    return;
}

void OperateLinkList(void)
{
    SingleLinkList sllMember;

    LinkListMenu();

    int choose = 1;
    int tmp;
    int siteTmp = 0;
    int outSllElement;
    int sllLength;
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
                cout << "Please enter the element which you want insert: ";
                cin >> tmp;
                cout << "Please enter the site: ";
                cin >> siteTmp;
                ret = sllMember.InsertSingleLinkList(tmp, siteTmp);
                if (ret != DSRETSUCCESS)
                {
                    cout << "Insert ERROR!" << endl;
                }
                break;
            case 2:
                cout << "Please enter the site: ";
                cin >> siteTmp;
                ret = sllMember.DeleteSingleLinkList(siteTmp, outSllElement);
                if (ret == DSRETSUCCESS)
                {
                    cout << "***Out Element is: " << outSllElement << endl;
                }
                break;
            case 3:
                sllLength = sllMember.GetSingleLinkListLength();
                cout << "***Length is: " << sllLength << endl;
                break;
            case 4:
                ret = sllMember.PrintSingleLink();
                break;
            case 5:
                cout << "Please enter the element which you want get: ";
                cin >> siteTmp;
                ret = sllMember.GetLinkListMember(outSllElement, siteTmp);
                cout << "***Out Element is: " << outSllElement << endl;
                break;
            default:
                cout << "ERROR Choice!" << endl;
                break;
            cout << endl;
            LinkListMenu();
        }
        cout << endl;
        LinkListMenu();
    }
    return;
}
/***************************  LinkList  ****************************/




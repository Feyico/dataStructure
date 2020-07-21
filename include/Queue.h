#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Common.h"

template <class T>
class Queue
{
private:
    /*
    * Node,定义在类内，作用域为整个类
    */
    struct QueueNode { T data; struct QueueNode * next; };
    enum { SIZE = 10 };
    /*
     * class member
    */
    QueueNode * front;
    QueueNode * rear;
    int qCounts;
    const int qSize;
public:
    /*
    * 定义构造函数和析构函数
    */
    Queue(int qs);
    ~Queue();
public:
    /*
    * 常用的方法
    */
    bool IsEmpty()const { return qCounts == 0; };
    bool IsFull()const { return qCounts == qSize; };
    DSReturn PrintQueue();
    int GetQueueLength()const { return qCounts; };
    DSReturn Enqueue(const T & item);
    DSReturn Dequeue(T & item);
};

template <class T>
inline Queue<T>::Queue(int qs):qSize(qs)
{
    front = rear = NULL;
    qCounts = 0;
}

template <class T>
inline Queue<T>::~Queue()
{
    /*
    * 依次删除队列内所有数据
    */
    //1、定义一个新的节点
    //2、当队列不为空时，删除所有节点
    QueueNode * tempNode;
    while (front != NULL)
    {
        tempNode = front;
        front = front->next;
        delete tempNode;
    }
    
}

template <class T>
inline DSReturn Queue<T>::PrintQueue()
{
    if (qCounts > 0)
    {
        QueueNode * pMove;
        pMove = front;
        while (pMove->next != nullptr)
        {
            std::cout << "***Queue Data: [" << pMove->data << "]" << std::endl;
            pMove = pMove->next;
        }
        std::cout << "***Queue Data: [" << pMove->data << "]" << std::endl;
    }

    return DSRETSUCCESS;
}

template <class T>
inline DSReturn Queue<T>::Enqueue(const T & item)
{
    //1.判断队列是否满了
    if (IsFull())
    {
        return DSRETFULLQUEUE;
    }
    
    //2.创建一个新的节点
    QueueNode * newNode = new QueueNode;
    newNode->data = item;
    newNode->next = NULL;

    //3.插入队列,数量+1
    if (front == NULL)
    {
        front = newNode;
    }
    else
    {
        rear->next = newNode;
    }
    rear = newNode;//尾节点更新
    qCounts++;
    
    return DSRETSUCCESS;
}

template <class T>
inline DSReturn Queue<T>::Dequeue(T & item)
{
    //1.判断队列是否为空
    if (IsEmpty())
    {
        return DSRETTEMPTYQUEUE;
    }

    //2.创建一个新的节点
    QueueNode * delNode = new QueueNode;

    //3.删除头节点
    delNode = front;
    item = delNode->data;
    front = front->next;
    qCounts--;
    delete delNode;

    //4.若队伍为空,更新位节点
    if (qCounts == 0)
    {
        rear = NULL;
    }

    return DSRETSUCCESS;
}

#endif
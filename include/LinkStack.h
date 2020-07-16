#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

#include "Common.h"

template <class T>
struct LinkStackNode
{
    T data;
    LinkStackNode<T> *next;
};

template <class T>
class LinkStack
{
private:
    LinkStackNode<T> *top;
public:
    LinkStack();
    ~LinkStack();
    DSReturn Pop(T& item);
    DSReturn Push(const T& item);
    DSReturn printStackData();
private:
    bool IsEmpty();
};

template <class T>
inline LinkStack<T>::LinkStack()
{
    top = new LinkStackNode<T>;//创建一个新的节点
    top->next = NULL;
}


template <class T>
inline LinkStack<T>::~LinkStack()
{
    delete [] top;
}


template <class T>
inline DSReturn LinkStack<T>::Pop(T& item)
{
    //先判空
    if (IsEmpty())
    {
        return DSRETEMPTYSTACK;
    }
    
    //创建一个释放的节点,不必分配空间
    LinkStackNode<T>* free_node;
    free_node = top->next;
    item = free_node->data;
    top->next = free_node->next;//就是top->next->next,这里的top为原来的top,变为top->next后删除原先的栈顶
    delete free_node;

    return DSRETSUCCESS;
}

template <class T>
inline DSReturn LinkStack<T>::Push(const T& item)
{
    //先创建一个新的节点
    LinkStackNode<T>* new_node = new LinkStackNode<T>;
    if (!new_node)
    {
        return DSRETERRCREATE;
    }
    new_node->data = item;
    new_node->next = top->next;//新节点指向未知的下一个
    top->next = new_node;//新节点赋值给原top的下一个，即移动top指针
    return DSRETSUCCESS;
}

template <class T>
inline DSReturn LinkStack<T>::printStackData()
{
    if (!IsEmpty())
    {
        LinkStackNode<T>* pMove;
        pMove = top->next;
        while (pMove->next != NULL)
        {
            std::cout << "LinkStackData: [" << pMove->data << "]" << std::endl;
            pMove = pMove->next;
        }
        std::cout << "LinkStackData: [" << pMove->data << "]" << std::endl;
    }
    
    return DSRETSUCCESS;
}

template <class T>
inline bool LinkStack<T>::IsEmpty()
{
    return top->next == NULL ? true:false;
}

#endif
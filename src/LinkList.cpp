#include "LinkList.h"

SingleLinkList::SingleLinkList()
{
    head = new SingleLinkListNode;
    head->data = 0;
    head->next = nullptr;
}

SingleLinkList::~SingleLinkList()
{
    if (head->data > 0)
    {
        SingleLinkListNode * pMove = nullptr;
        SingleLinkListNode * pDel = nullptr;
        pMove = head->next;
        while (pMove != nullptr)
        {
            pDel = pMove;
            pMove = pMove->next;
            delete pDel;
            std::cout << "~~~" << (head->data)-- << std::endl;
        }
        head->data = 0;
    }

    delete head;
}

DSReturn SingleLinkList::PrintSingleLink()
{
    std::cout << "***Single LinkList Head NUM: [" << head->data << "]" << std::endl;
    
    if (head->data > 0)
    {
        SingleLinkListNode * pMove;//自动销毁
        pMove = head->next;
        while (pMove != nullptr)
        {
            std::cout << "***Single LinkList Data: [" << pMove->data << "]" << std::endl;
            pMove = pMove->next;
        }
    }
    
    return DSRETSUCCESS;
}

// DSReturn SingleLinkList::CreateSingleLink(const int slls) : sllSize(slls)
// {
//     if (sllSize <= 0)
//     {
//         //参数不合法，创建失败
//         return DSRETERRCREATE;
//     }
    
//     SingleLinkListNode * pTmp = nullptr;
//     SingleLinkListNode * pNew = nullptr;

//     pTmp = head;

//     for (int i = 1; i <= sllSize; i++)
//     {
//         pNew = new SingleLinkListNode;
//         pNew->data = i;
//         pNew->next = nullptr;

//         pTmp->next = pNew;
//         pTmp = pNew;
//     }

//     sllCounts = slls;

//     return DSRETSUCCESS;
// }

DSReturn SingleLinkList::DestroySingleLinkList()
{
    if (head->data > 0)
    {
        SingleLinkListNode * pMove = nullptr;
        SingleLinkListNode * pDel = nullptr;
        pMove = head->next;
        while (pMove != nullptr)
        {
            pDel = pMove;
            pMove = pMove->next;
            delete pDel;
            std::cout << "~~~" << (head->data)-- << std::endl;
        }
        head->next = nullptr;
        head->data = 0;
    }

    return DSRETSUCCESS;
}

DSReturn SingleLinkList::InsertSingleLinkList(const DATATYPE& item, const int site)
{
    if (site <= 0)
    {
        //位置参数错误
        return DSRETERRVAILDCHECK;
    }

    SingleLinkListNode * pTmp = head;
    int num = 1;
    
    while (pTmp->next && num < site)//寻找第site-1个结点
    {
        pTmp = pTmp->next;
        ++num;
    }

    if (!pTmp || num > site)//若该结点不存在
    {
        return DSRETNOTEXISTNODE;
    }

    //创建一个待插入的节点
    SingleLinkListNode * pNew = new SingleLinkListNode;
    pNew->data = item;
    pNew->next = nullptr;

    pNew->next = pTmp->next;
    pTmp->next = pNew;
    head->data++;
    
    return DSRETSUCCESS;
}

DSReturn SingleLinkList::DeleteSingleLinkList(const int site, DATATYPE & item)
{
    if (head->data == 0)
    {
        //空链表
        return DSRETEMPTYLINKLIST;
    }

    if (site <= 0 || site > head->data)
    {
        //位置参数错误
        return DSRETERRVAILDCHECK;
    }

    SingleLinkListNode* pDel = nullptr;
    SingleLinkListNode* pMove = nullptr;

    int num = 1;
    pMove = head;

    while (pMove->next && num < site)//找到第site-1个结点
    {
        pMove = pMove->next;
        ++num;
    }

    if (!(pMove->next) || num > site)
    {
        return DSRETNOTEXISTNODE;
    }

    pDel = pMove->next;
    item = pDel->data;
    pMove->next = pDel->next;
    delete pDel;//释放删除的结点
    head->data--;

    return DSRETSUCCESS;
}

DSReturn SingleLinkList::GetLinkListMember(DATATYPE& item, const int site)
{
    if (head->data == 0)
    {
        //空链表
        return DSRETEMPTYLINKLIST;
    }

    if (site <= 0)
    {
        //位置参数错误
        return DSRETERRVAILDCHECK;
    }

    int siteTmp = site;
    if (site > head->data)
    {
        siteTmp = head->data;
    }
    
    SingleLinkListNode * pTmp = head->next;
    for (int i = 1; i < siteTmp; i++)
    {
        pTmp = pTmp->next;
    }

    item = pTmp->data;

    return DSRETSUCCESS;
}

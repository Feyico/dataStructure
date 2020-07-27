#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include "Common.h"

typedef int DATATYPE;

class SingleLinkListNode
{
public:
    DATATYPE data;
    SingleLinkListNode * next;
};

class SingleLinkList
{
private:
    SingleLinkListNode *head;//头结点，为了操作的统一和方便而设立，放在第一元素的结点之前
public:
    SingleLinkList();
    ~SingleLinkList();
public:
    bool IsEmpty()const { return head->data == 0; };
    int GetSingleLinkListLength()const { return head->data; };
    DSReturn PrintSingleLink();
    //DSReturn CreateSingleLinkList(const int slls);
    DSReturn DestroySingleLinkList();
    DSReturn InsertSingleLinkList(const DATATYPE & item, const int site);
    DSReturn DeleteSingleLinkList(const int site, DATATYPE & item);
    DSReturn GetLinkListMember(DATATYPE & item, const int site);
};

#endif
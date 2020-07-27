#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>

enum DSReturn
{
    DSRETSUCCESS = 0,       //0--成功
    DSRETPUSHERR,           //1--push失败
    DSRETPOPERR,            //2--pop失败
    DSRETEMPTYSTACK,        //3--空栈
    DSRETFULLSTACK,         //4--满栈
    DSRETERRVAILDCHECK,     //5--参数检测错误
    DSRETERRCREATE,         //6--创建失败
    DSRETFULLQUEUE,         //7--满队列
    DSRETEMPTYQUEUE,        //8--空队列
    DSRETEMPTYLINKLIST,     //9--空链表
    DSRETNOTEXISTNODE       //10--不存在的结点
};

#endif
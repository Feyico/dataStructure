#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>

enum DSReturn
{
    DSRETSUCCESS = 0,   //0--成功
    DSRETPUSHERR,       //1--push失败
    DSRETPOPERR,        //2--pop失败
    DSRETEMPTYSTACK,    //3--空栈
    DSRETFULLSTACK      //4--满栈
};

#endif
//
//  GoldCardTask.h
//  solitraire
//
//  Created by Jinko on 15/10/9.
//
//

#ifndef __solitraire__GoldCardTask__
#define __solitraire__GoldCardTask__

#include <stdio.h>
#include "TaskVO.h"

class GoldCardTask:public TaskVO{
public:
    GoldCardTask(int type, int current,int target):TaskVO(type,current,target){};
    ~GoldCardTask();
    bool checkFinish();
};

#endif /* defined(__solitraire__GoldCardTask__) */

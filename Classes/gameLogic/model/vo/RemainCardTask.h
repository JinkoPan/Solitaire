//
//  RemainCardTask.h
//  solitraire
//
//  Created by Jinko on 15/10/9.
//
//

#ifndef __solitraire__RemainCardTask__
#define __solitraire__RemainCardTask__

#include <stdio.h>
#include "TaskVO.h"

class RemainCardTask:public TaskVO{
public:
    RemainCardTask(int type, int current,int target):TaskVO(type,current,target){};
    ~RemainCardTask();
    bool checkFinish();
    
};

#endif /* defined(__solitraire__RemainCardTask__) */

//
//  ComboCardTask.h
//  solitraire
//
//  Created by Jinko on 15/10/9.
//
//

#ifndef __solitraire__ComboCardTask__
#define __solitraire__ComboCardTask__

#include <stdio.h>
#include "TaskVO.h"

class ComboCardTask:public TaskVO{
public:
    ComboCardTask(int type, int current,int target):TaskVO(type,current,target){};
    ~ComboCardTask();
    bool checkFinish();
};

#endif /* defined(__solitraire__ComboCardTask__) */

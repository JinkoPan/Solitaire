//
//  TaskVO.h
//  solitraire
//
//  Created by Jinko on 15/10/9.
//
//

#ifndef __solitraire__TaskVO__
#define __solitraire__TaskVO__

#include <stdio.h>

class TaskVO {
public:
    TaskVO();
    TaskVO(int type, int current,int target):type(type),currentCount(current),targetCount(target){};
    virtual ~TaskVO();
    virtual bool checkFinish() = 0;
    
public:
    int type;
    int currentCount;
    int targetCount;
    bool finish;
};

#endif /* defined(__solitraire__TaskVO__) */


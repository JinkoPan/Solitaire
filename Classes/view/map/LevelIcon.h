//
//  LevelIcon.h
//  solitraire
//
//  Created by Jinko on 15/8/19.
//
//

#ifndef __solitraire__LevelIcon__
#define __solitraire__LevelIcon__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class LevelIcon:public Sprite{
public:
    static LevelIcon* create(int data);
    virtual bool init();
//    bool initView(int index);
    CREATE_FUNC(LevelIcon);
    bool onBeganHandler(Touch* touch,Event* event);
public:
    int index;
    Label* label;
};

#endif /* defined(__solitraire__LevelIcon__) */

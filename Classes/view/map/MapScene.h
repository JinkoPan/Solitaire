//
//  MapScene.h
//  solitraire
//
//  Created by Jinko on 15/8/19.
//
//

#ifndef __solitraire__MapScene__
#define __solitraire__MapScene__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class MapScene:public Layer{
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MapScene);
    void onCloseClick(Ref* pSender);
public:
    static const int offsetX = 300;
    static const int offsetY = 50;
};

#endif /* defined(__solitraire__MapScene__) */

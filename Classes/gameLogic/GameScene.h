//
//  GameScene.h
//  solitraire
//
//  Created by Jinko on 15/7/15.
//
//

#ifndef solitraire_GameScene_h
#define solitraire_GameScene_h

#include "cocos2d.h"
#include "GameLayer.h"
#include "utils/utils.h"

USING_NS_CC;

class GameScene:public Scene{
public:
    bool init();
    CREATE_FUNC(GameScene);
};

#endif

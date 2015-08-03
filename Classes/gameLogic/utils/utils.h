//
//  utils.h
//  solitraire
//
//  Created by Jinko on 15/7/19.
//
//

#ifndef solitraire_utils_h
#define solitraire_utils_h

#include <string>
#include "cocos2d.h"
#include <cmath>

using namespace std;
using namespace cocos2d;

inline void addSpriteFrameWithFileExt(string fileName);
inline Sprite* createSprite(string spriteName);
inline bool checkIsRight(int card1,int card2);






void addSpriteFrameWithFileExt(string fileName)
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(fileName);
    
}

Sprite* createSprite(string spriteName){
    SpriteFrame* sf = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteName);
    return Sprite::createWithSpriteFrame(sf);
}

bool checkIsRight(int card1,int card2){
    if (card1 == 0 || card2 == 0) {
        return true;
    }
    
    if ((card1 == 1 && card2 == 13) || (card1==13 && card2 == 1) ) {
        return true;
    }
    
    int diff = abs(card1-card2);
    if (diff == 1) {
        return true;
    }
    return false;
}


#endif

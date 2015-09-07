//
//  CardSprite.h
//  solitraire
//
//  Created by Jinko on 15/7/27.
//
//

#ifndef __solitraire__CardSprite__
#define __solitraire__CardSprite__

#include <stdio.h>
#include "cocos2d.h"
#include "utils.h"

using namespace cocos2d;

class CardSprite:public Sprite{
public:
//    bool initWithFile(const std::string& filename);
//    CREATE_FUNC(CardSprite);
//    CardSprite();
    ~CardSprite();
    bool initView(string filename);
    static CardSprite* create(string filename);
    
    void onButtonClicked(std::function<bool(Touch*, Event*)> callback);
    void onExit();
};
#endif /* defined(__solitraire__CardSprite__) */

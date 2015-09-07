//
//  BaseCardView.h
//  solitraire
//
//  Created by Jinko on 15/7/15.
//
//

#ifndef __solitraire__BaseCardView__
#define __solitraire__BaseCardView__

#include "cocos2d.h"
#include "CardVO.h"
#include "../utils/utils.h"
#include "CardFaceUpView.h"
#include "AppConstant.h"


USING_NS_CC;


class BaseCardView:public Sprite{
public:
//    bool init();    
//    CREATE_FUNC(BaseCardView);
    virtual ~BaseCardView();
    bool initView(CardVO* cardVO);
    virtual bool touchBegan(Touch* touch,Event* event)=0;
    virtual void moveToPosition(Vec2 vec) = 0;
    virtual void shakeCard(EventCustom* ec) = 0;
    virtual void openCard(std::function<void()> callback = NULL);
    
public:
    Sprite* container;
    CardFaceUpView* cardView;
    Sprite* cardBackView;
    ActionInterval* inAction;
    ActionInterval* outAction;
    CardVO* cardVO;
    int offsetX = 300;
    int offsetY = 300;
    
};

#endif /* defined(__solitraire__BaseCardView__) */

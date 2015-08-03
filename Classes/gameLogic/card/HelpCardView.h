//
//  HelpCardView.h
//  solitraire
//
//  Created by Jinko on 15/7/25.
//
//

#ifndef __solitraire__HelpCardView__
#define __solitraire__HelpCardView__

#include <stdio.h>
#include "BaseCardView.h"

class HelpCardView:public BaseCardView{
public:
    bool initView(CardVO* cardVO);
    bool touchBegan(Touch* touch,Event* event);
    void moveToPosition(Vec2 vec);
    void shakeCard(EventCustom* ec);
//    void openCard(std::function<void()> callback);
    ~HelpCardView();
public:
    
    
};

#endif /* defined(__solitraire__HelpCardView__) */

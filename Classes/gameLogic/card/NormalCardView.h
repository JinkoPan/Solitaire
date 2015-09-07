//
//  NormalCardView.h
//  solitraire
//
//  Created by Jinko on 15/7/19.
//
//

#ifndef __solitraire__NormalCardView__
#define __solitraire__NormalCardView__

#include <stdio.h>
#include "BaseCardView.h"
#include "AppConstant.h"
#include <string>
#include <map>
#include "CardFaceUpView.h"

using namespace std;

class NormalCardView:public BaseCardView{
public:
//    bool init();
//    CREATE_FUNC(NormalCardView);
    ~NormalCardView();
    bool initView(CardVO* cardVO);
    bool touchBegan(Touch* touch,Event* event);
    void moveToPosition(Vec2 vec);
    void shakeCard(EventCustom* ec);
//    void openCard();
    void onOpenCardHandler(EventCustom* ec);
    void onExit();
public:
    EventListenerCustom* collectionCardListener;
    EventListenerCustom* shakeCardListener;
    EventListenerCustom* openCardListener;
    
};

#endif /* defined(__solitraire__NormalCardView__) */

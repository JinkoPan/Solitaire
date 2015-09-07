//
//  CardFaceUpView.h
//  solitraire
//
//  Created by Jinko on 15/7/27.
//
//

#ifndef __solitraire__CardFaceUpView__
#define __solitraire__CardFaceUpView__

#include <stdio.h>
#include "cocos2d.h"
#include <string>
#include "CardVO.h"
#include "../utils/utils.h"
#include "AppConstant.h"


using namespace std;
using namespace cocos2d;


class CardFaceUpView:public Sprite{
public:
    bool init(CardVO* cardvo);
    static CardFaceUpView* create(CardVO* cardvo);
    ~CardFaceUpView();
    void onExit();
//    CREATE_FUNC(CardFaceUpView);
};
#endif /* defined(__solitraire__CardFaceUpView__) */

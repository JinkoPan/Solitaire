//
//  GameLayer.h
//  solitraire
//
//  Created by Jinko on 15/7/15.
//
//

#ifndef __solitraire__GameLayer__
#define __solitraire__GameLayer__

#include "cocos2d.h"
#include "json/document.h"
#include <vector>
#include "card/NormalCardView.h"
#include "model/vo/CardVO.h"
#include "model/GameModel.h"
#include "AppConstant.h"
#include "card/CardSprite.h"
#include "CardFaceUpView.h"

USING_NS_CC;
using namespace std;
using namespace rapidjson;

class GameLayer:public Layer{
public:
    bool init();
    CREATE_FUNC(GameLayer);
    void readJsonFile();
    void createCardView();
    bool onCollectionCardClick(Touch* touch, Event* event);
    void updateCollectionCard();
    void openCardCheck();
    void gameCheck();
    void createReturnBtn();
    void onReturnBtnClick(Ref* pSender);
    void onExit();
public:
    Node* card_container;
    Node* control_layer;
    vector<CardVO*> cardVOList;
    GameModel* gameModel = nullptr;
    Size visibleSize;
    Sprite* collection_card;
};

#endif /* defined(__solitraire__GameLayer__) */

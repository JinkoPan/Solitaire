//
//  GameLayer.cpp
//  solitraire
//
//  Created by Jinko on 15/7/15.
//
//

#include "GameLayer.h"
#include "utils/utils.h"
#include "HelpCardView.h"


bool GameLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    control_layer = Node::create();
    this->addChild(control_layer);
    card_container = Node::create();
//    card_container->setPosition(Vec2(300,300));
    this->addChild(card_container);
    
    readJsonFile();
    createCardView();
    
    visibleSize = Director::getInstance()->getVisibleSize();
    
    updateCollectionCard();
    
    CardSprite* card_view1 = CardSprite::create("card_face_back.png");
    card_view1->setPosition(Vec2(visibleSize.width/2-88,80));
    card_container->addChild(card_view1);
    card_view1->onButtonClicked(CC_CALLBACK_2(GameLayer::onCollectionCardClick, this));
    
    _eventDispatcher->addCustomEventListener("check_card_is_right", [=](EventCustom* ec){
//        printf("check_card_is_right ===== ");
        CardVO* cardVO = static_cast<CardVO*>(ec->getUserData());
        string eventName = "";
        if (gameModel->cardCheck(cardVO)){
            printf("card is right !");
            eventName = "collection_card_event";
            openCardCheck();
        }else{
            eventName = "shake_card_event";
        }
        EventCustom* event = new EventCustom(eventName);
        event->setUserData(cardVO);
        _eventDispatcher->dispatchEvent(event);
    });
    
    _eventDispatcher->addCustomEventListener("update_collection_card", [=](EventCustom* ec){
        updateCollectionCard();
        gameCheck();
    });
    
    return true;
}

bool GameLayer::onCollectionCardClick(Touch* touch, Event* event){
    Sprite* target = static_cast<Sprite*>(event->getCurrentTarget());
    Size s = target->getContentSize();
    Vec2 p = target->convertToNodeSpace(touch->getLocation());
    Rect rect = Rect(0,0,s.width,s.height);
    
    printf("face back width: %f, height: %f\n",s.width,s.height);
    
    if (rect.containsPoint(p)) {
        HelpCardView* cardView = new HelpCardView();
        CardVO* cardVo = gameModel->getRandomCardVO();
        gameModel->curCardVO = cardVo;
        gameModel->collection_card.push_back(cardVo);
        cardView->initView(cardVo);
        cardView->setPosition(Vec2(visibleSize.width/2-88,80));
        int t = (int)card_container->getChildrenCount();
        card_container->addChild(cardView,t);
        cardView->openCard([=](){
            updateCollectionCard();
            cardView->removeFromParentAndCleanup(true);
        });
        
        return true;
    }
    return false;
}

void GameLayer::readJsonFile(){
    string jsonFileName = "level1.json";
    if (gameModel == nullptr) {
        gameModel = new GameModel();
    }
    gameModel->createLevelDefinition(jsonFileName);
//    printf("\n");
//    for (int i = 0; i<100; i++) {
//        int num = RANDOMNUM(13);
//        printf("num: %d\n",num);
//    }
//    int k = 1;
//    AppConstant::cards_face[k];
    
}

void GameLayer::createCardView(){
    if (gameModel->mode == "puzzle") {
        cardVOList = gameModel->puzzleLevelDefinition->cards;
    }
    for (int i =0 ; i<cardVOList.size(); i++) {
            NormalCardView* cardView = new NormalCardView();
            cardView->initView(cardVOList[i]);
            card_container->addChild(cardView);
    }
}

void GameLayer::updateCollectionCard(){
    if (collection_card != nullptr) {
        collection_card->removeFromParentAndCleanup(true);
    }
    printf("curcard cardvalue: %d\n",gameModel->curCardVO->card_value);
    collection_card = CardFaceUpView::create(gameModel->curCardVO);
    collection_card->setPosition(Vec2(visibleSize.width/2,80));
    card_container->addChild(collection_card);
}

void GameLayer::openCardCheck(){
    vector<CardVO*> cards = gameModel->puzzleLevelDefinition->cards;
    for (int i=0; i<cards.size(); ++i) {
        if(cards[i]->coverCount == 0 && !cards[i]->face_up){
            EventCustom event("open_card_event");
            event.setUserData(cards[i]);
            _eventDispatcher->dispatchEvent(&event);
        }
    }
}

void GameLayer::gameCheck(){
    //是否完成任务
}



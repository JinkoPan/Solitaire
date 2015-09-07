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
#include "MapScene.h"


bool GameLayer::init(){
    if (!Layer::init()) {
        return false;
    }
    control_layer = Node::create();
    this->addChild(control_layer);
    card_container = Node::create();
    card_container->setPosition(Vec2(OFFSETX,OFFSETY));
    this->addChild(card_container);
    
    readJsonFile();
    createCardView();
    
    visibleSize = Director::getInstance()->getVisibleSize();
    
    updateCollectionCard();
    
    CardSprite* card_view1 = CardSprite::create("card_face_back.png");
    card_view1->setPosition(Vec2(visibleSize.width/2-OFFSETX-88,CARD_Y));
    card_container->addChild(card_view1);
    card_view1->onButtonClicked(CC_CALLBACK_2(GameLayer::onCollectionCardClick, this));
    
    createReturnBtn();
    
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
        EventCustom event(eventName);
        event.setUserData(cardVO);
        _eventDispatcher->dispatchEvent(&event);
    });
    
    _eventDispatcher->addCustomEventListener("update_collection_card", [=](EventCustom* ec){
        updateCollectionCard();
        gameCheck();
    });
    
    return true;
}

void GameLayer::createReturnBtn(){
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(GameLayer::onReturnBtnClick, this));
    
    closeItem->setPosition(Vec2(visibleSize.width - closeItem->getContentSize().width ,
                                closeItem->getContentSize().height));
    
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

}

void GameLayer::onReturnBtnClick(Ref* pSender){
    Director::getInstance()->replaceScene(MapScene::createScene());
}

bool GameLayer::onCollectionCardClick(Touch* touch, Event* event){
    Sprite* target = static_cast<Sprite*>(event->getCurrentTarget());
    Size s = target->getContentSize();
    Vec2 p = target->convertToNodeSpace(touch->getLocation());
    Rect rect = Rect(0,0,s.width,s.height);
    
//    printf("face back width: %f, height: %f\n",s.width,s.height);
    
    if (rect.containsPoint(p)) {
        CardVO* cardVo = gameModel->getRandomCardVO();
        gameModel->curCardVO = cardVo;
        gameModel->collection_card.push_back(cardVo);
        HelpCardView* cardView = HelpCardView::create(cardVo);
        cardView->setPosition(Vec2(visibleSize.width/2-OFFSETX-88,CARD_Y));
        int t = (int)card_container->getChildrenCount();
        card_container->addChild(cardView,t);
        cardView->openCard([=](){
            updateCollectionCard();
            cardView->removeFromParentAndCleanup(true);
        });
        cardVo = nullptr;
        return true;
    }
    return false;
}

void GameLayer::readJsonFile(){
    int k = AppConstant::getInstance()->levelId;
    char jsonFileName[20];
    sprintf(jsonFileName, "level%d.json",k);
    if (gameModel == nullptr) {
        gameModel = new GameModel();
    }
    gameModel->createLevelDefinition(jsonFileName);
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
    collection_card->setPosition(Vec2(visibleSize.width/2-OFFSETX,CARD_Y));
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

void GameLayer::onExit(){
    Layer::onExit();
//    _eventDispatcher->removeEventListenersForTarget(this);
    _eventDispatcher->removeCustomEventListeners("update_collection_card");
    _eventDispatcher->removeCustomEventListeners("check_card_is_right");
    delete gameModel;
    CCLOG("GameLayer:: onExit() ");
}



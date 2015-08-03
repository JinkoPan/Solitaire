//
//  NormalCardView.cpp
//  solitraire
//
//  Created by Jinko on 15/7/19.
//
//

#include "NormalCardView.h"

//bool init(){
//    if (!Node::init()) {
//        return false;
//    }
//    return true;
//}

bool NormalCardView::initView(CardVO* cardVO){
    
    if (!BaseCardView::initView(cardVO)){
        return false;
    }
    
//    container = Sprite::create();
//    container->setAnchorPoint(Vec2(0,0));
//    this->addChild(container);
   
    cardView = CardFaceUpView::create(cardVO);
    Size size = cardView->getContentSize();
    Point pos = Vec2(size.width/2,size.height/2);
    this->setContentSize(size);
    cardView->setPosition(pos);
    this->addChild(cardView);


    if (!cardVO->face_up){
        cardView->setScaleX(0.1);
        cardView->setVisible(false);
        cardBackView = createSprite("card_face_back.png");
        cardBackView->setPosition(pos);
        this->addChild(cardBackView);
    }
    
    this->setRotation(cardVO->rotation);
    this->setPosition(Vec2(cardVO->posX+offsetX,cardVO->posY+offsetY));
    
    
    EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(NormalCardView::touchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    

    EventListenerCustom* customListener = EventListenerCustom::create("collection_card_event", [=](EventCustom* ec){
        CardVO* _cardVO = static_cast<CardVO*>(ec->getUserData());
        if (_cardVO->cardIndex == cardVO->cardIndex) {
            Size visibleSize = Director::getInstance()->getVisibleSize();
            moveToPosition(Vec2(visibleSize.width/2,80));
        }        
    });
    
    _eventDispatcher->addEventListenerWithFixedPriority(customListener, 1);
    
    _eventDispatcher->addCustomEventListener("shake_card_event", CC_CALLBACK_1(NormalCardView::shakeCard, this));
    _eventDispatcher->addCustomEventListener("open_card_event", CC_CALLBACK_1(NormalCardView::onOpenCardHandler, this));
    return true;
    
}

void NormalCardView::onOpenCardHandler(EventCustom* ec){
    CardVO* _cardVO = static_cast<CardVO*>(ec->getUserData());
    if (_cardVO->cardIndex == cardVO->cardIndex) {
        printf("\n  open_card_event  cardIndex: %d    ",_cardVO->cardIndex);
        openCard([=](){cardVO->face_up = true;});
    }
}

void NormalCardView::moveToPosition(Vec2 vec){
    int t = static_cast<int>(this->getParent()->getChildrenCount());
    this->setZOrder(t);
    MoveTo* movetoAction = MoveTo::create(0.5, vec);
    CallFunc* callFunc = CallFunc::create([=](){
        _eventDispatcher->dispatchCustomEvent("update_collection_card");
        this->removeFromParentAndCleanup(true);
    });
    Sequence* seq = Sequence::create(movetoAction,callFunc, NULL);
    this->runAction(seq);
}

void NormalCardView::shakeCard(EventCustom* ec){
    CardVO* _cardVO = static_cast<CardVO*>(ec->getUserData());
    if (_cardVO->cardIndex == cardVO->cardIndex) {
        RotateTo* rotateAction1 = RotateTo::create(0.08, 30);
        RotateTo* rotateAction2 = RotateTo::create(0.08, -30);
        RotateTo* rotateAction3 = RotateTo::create(0.08, 0);
        Sequence* seq = Sequence::create(rotateAction1,rotateAction3,rotateAction2,rotateAction3, NULL);
        this->runAction(seq);
    }
}

//void NormalCardView::openCard(){
//    float duration = 0.4;
//    inAction = Sequence::create(DelayTime::create(duration*0.5),
//                                Show::create(),
////                                OrbitCamera::create(duration * 0.5, 1, 0, 90, -90, 0, 0),
//                                ScaleTo::create(duration * 0.5, 1,1),
//                                NULL);
//    inAction->retain();
//    outAction = Sequence::create(
////                                 OrbitCamera::create(duration * 0.5, 1, 0, 0, -90, 0, 0),
//                                 ScaleTo::create(duration * 0.5, 0.1, 1),
//                                 Hide::create(),
////                                 DelayTime::create(duration*0.5),
//                                 NULL);
//    outAction->retain();
//    
//    cardView->runAction(inAction);
//    cardBackView->runAction(outAction);
//}

bool NormalCardView::touchBegan(Touch* touch, Event* event){
    //判断点击是否合法,然后做相应处理
//    CCLOG("%s","click card~");
    Sprite* target = static_cast<Sprite*>(event->getCurrentTarget());
    Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
    Size s = target->getContentSize();
//    printf("width: %f, height: %f\n",s.width,s.height);
    Rect rect = Rect(0,0,s.width,s.height);
    if (rect.containsPoint(locationInNode)) {
//        moveToPosition(Vec2(300,100));
        if (cardVO->face_up && cardVO->coverCount == 0) {
//            Size visibleSize = Director::getInstance()->getVisibleSize();
//            moveToPosition(Vec2(visibleSize.width/2,80));
            EventCustom event("check_card_is_right");
            event.setUserData(cardVO);
            _eventDispatcher->dispatchEvent(&event);
        }else{
//            openCard([=](){cardVO->face_up = true;});
        }
        return true;
    }
    return false;
}

NormalCardView::~NormalCardView(){
    inAction->release();
    outAction->release();
    this->cardVO = nullptr;
    _eventDispatcher->removeAllEventListeners();
}
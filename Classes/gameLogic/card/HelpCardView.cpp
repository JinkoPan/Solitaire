//
//  HelpCardView.cpp
//  solitraire
//
//  Created by Jinko on 15/7/25.
//
//

#include "HelpCardView.h"

bool HelpCardView::initView(CardVO* cardVO){
    
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
    cardView->setPosition(Vec2(size.width+15,size.height/2));
    this->addChild(cardView);
    
    
//    if (!cardVO->face_up){
        cardView->setScaleX(0.1);
        cardView->setVisible(false);
        cardView->setAnchorPoint(Vec2(0,0.5));
        cardBackView = createSprite("card_face_back.png");
        cardBackView->setPosition(size.width,size.height/2);
        this->addChild(cardBackView);
        cardBackView->setAnchorPoint(Vec2(1,0.5));
        
//        EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
//        listener->setSwallowTouches(true);
//        listener->onTouchBegan = CC_CALLBACK_2(HelpCardView::touchBegan, this);
        //    listener->onTouchBegan = [=](Touch* touch, Event* event){
        ////        CCLOG("%s","click ~~~~");
        //        auto target =  static_cast<Sprite*>(event->getCurrentTarget());
        //        Vec2 locationInSprite = target->convertToNodeSpace(touch->getLocation());
        //        Size s = target->getContentSize();
        //        Rect rect = Rect(0,0,s.width,s.height);
        //        if (rect.containsPoint(locationInSprite)) {
        //            moveToPosition(Vec2(300,100));
        //            return true;
        //        }
        //        return false;
        //    };
        
//        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
//    }
    
    
    this->setRotation(cardVO->rotation);
    this->setPosition(Vec2(cardVO->posX,cardVO->posY));
    
    return true;
    
}

void HelpCardView::moveToPosition(Vec2 vec){
    MoveTo* movetoAction = MoveTo::create(0.5, vec);
    cardView->runAction(movetoAction);
}

void HelpCardView::shakeCard(EventCustom* ec){
    
}

//void HelpCardView::openCard(std::function<void()> callback){
//    float duration = 0.4;
//    inAction = Sequence::create(DelayTime::create(duration*0.5),
//                                Show::create(),
//                                //                                OrbitCamera::create(duration * 0.5, 1, 0, 90, -90, 0, 0),
//                                ScaleTo::create(duration * 0.5, 1,1),
////                                DelayTime::create(duration*0.5),
//                                CallFunc::create([=](){
////                                    this->removeFromParentAndCleanup(true);
//                                }),
//                                NULL);
//    inAction->retain();
//    outAction = Sequence::create(
//                                 //                                 OrbitCamera::create(duration * 0.5, 1, 0, 0, -90, 0, 0),
//                                 ScaleTo::create(duration * 0.5, 0.1, 1),
//                                 Hide::create(),
//                                 //                                 DelayTime::create(duration*0.5),
//                                 NULL);
//    outAction->retain();
//    
//    cardView->runAction(inAction);
//    cardBackView->runAction(outAction);
//}

bool HelpCardView::touchBegan(Touch* touch, Event* event){
    //判断点击是否合法,然后做相应处理
    CCLOG("%s","click card~");
    Sprite* target = static_cast<Sprite*>(event->getCurrentTarget());
    Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
    Size s = target->getContentSize();
    printf("width: %f, height: %f\n",s.width,s.height);
    Rect rect = Rect(0,0,s.width,s.height);
    if (rect.containsPoint(locationInNode)) {
        //        moveToPosition(Vec2(300,100));
        openCard();
        return true;
    }
    return false;
}

HelpCardView::~HelpCardView(){
    inAction->release();
    outAction->release();
}
//
//  BaseCardView.cpp
//  solitraire
//
//  Created by Jinko on 15/7/15.
//
//

#include "BaseCardView.h"

//bool BaseCardView::init(){
//    if (!Node::init()) {
//        return false;
//    }
//    return true;
//}

BaseCardView::~BaseCardView(){
    
}

bool BaseCardView::initView(CardVO* cardVO){
    if (!Sprite::init()) {
        return false;
    }
    this->cardVO = cardVO;
//    EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
//    listener->onTouchBegan = CC_CALLBACK_2(BaseCardView::touchBegan, this);
//    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
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

    return true;
}



void BaseCardView::openCard(std::function<void()> callback){
    float duration = 0.4;
    inAction = Sequence::create(DelayTime::create(duration*0.5),
                                Show::create(),
                                //                                OrbitCamera::create(duration * 0.5, 1, 0, 90, -90, 0, 0),
                                ScaleTo::create(duration * 0.5, 1,1),
                                CallFunc::create(callback),
                                NULL);
    inAction->retain();
    outAction = Sequence::create(
                                 //                                 OrbitCamera::create(duration * 0.5, 1, 0, 0, -90, 0, 0),
                                 ScaleTo::create(duration * 0.5, 0.1, 1),
                                 Hide::create(),
                                 //                                 DelayTime::create(duration*0.5),
                                 NULL);
    outAction->retain();
    
    cardView->runAction(inAction);
    cardBackView->runAction(outAction);
}


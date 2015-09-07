//
//  CardSprite.cpp
//  solitraire
//
//  Created by Jinko on 15/7/27.
//
//

#include "CardSprite.h"

//CardSprite::CardSprite(){
//    
//}

CardSprite::~CardSprite(){
    
}

bool CardSprite::initView(string filename){
    if (!Sprite::init()) {
        return false;
    }
    Sprite* sp = createSprite(filename);
    Size spSize = sp->getContentSize();
    sp->setPosition(spSize.width/2,spSize.height/2);
    this->addChild(sp);
    this->setContentSize(spSize);
    return true;
}

CardSprite* CardSprite::create(string filename){
    CardSprite* sp = new (std::nothrow) CardSprite();
    if (sp && sp->initView(filename)) {
        sp->autorelease();
        return sp;
    }
    CC_SAFE_DELETE(sp);
    return nullptr;
}


void CardSprite::onButtonClicked(std::function<bool(Touch*, Event*)> callback){
    EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = callback;
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void CardSprite::onExit(){
    Sprite::onExit();
    CCLOG("CardSprite onExit");
}

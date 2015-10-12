//
//  UIButton.cpp
//  solitraire
//
//  Created by Jinko on 15/10/10.
//
//

#include "UIButton.h"
bool UIButton::initView(const std::string &normal,const std::string &clicked){
    if (!Node::init()) {
        return false;
    }
    
    normal_sp  = createSprite(normal);
    this->addChild(normal_sp);
    Size btnSize = normal_sp->getContentSize();
    this->setContentSize(btnSize);
    normal_sp->setPosition(Vec2(btnSize.width/2,btnSize.height/2));
    
    if (clicked != "" && normal != clicked) {
        clicked_sp = createSprite(clicked);
        this->addChild(clicked_sp);
        clicked_sp->setVisible(false);
        clicked_sp->setPosition(Vec2(btnSize.width/2,btnSize.height/2));
    }
    
    return true;
}

UIButton* UIButton::create(const std::string &normal,const std::string &clicked){
    UIButton* btn = new UIButton();
    if (btn && btn->initView(normal,clicked)) {
        btn->autorelease();
        return btn;
    }
    
    CC_SAFE_DELETE(btn);
    return nullptr;
}


void UIButton::onButtonClicked(std::function<void()> callback){
    
    EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [=](Touch* t, Event* e)->bool{
        Sprite* target = static_cast<Sprite*>(e->getCurrentTarget());
        Vec2 p = target->convertToNodeSpace(t->getLocation());
        Size s = target->getContentSize();
        Rect r(0,0,s.width,s.height);
        
        if (r.containsPoint(p)) {
            if (callback != nullptr) {
                callback();
            }
            if (clicked_sp) {
                clicked_sp->setVisible(true);
                normal_sp->setVisible(false);
            }
            return true;
        }
        return false;
    };
    listener->onTouchEnded = [=](Touch* t,Event* e){
        if (clicked_sp) {
            clicked_sp->setVisible(false);
            normal_sp->setVisible(true);
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
}
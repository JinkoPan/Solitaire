//
//  LevelIcon.cpp
//  solitraire
//
//  Created by Jinko on 15/8/19.
//
//

#include "LevelIcon.h"
#include "GameScene.h"

bool LevelIcon::init(){
    if (!Sprite::init()) {
        return false;
    }
    
    label = Label::createWithTTF("1","fonts/Marker Felt.ttf", 24);
//    label->setPosition(Vec2(100,100));
    this->addChild(label);
    
    
    this->setContentSize(Size(60,60));
    
    EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(LevelIcon::onBeganHandler, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}


bool LevelIcon::onBeganHandler(Touch* touch, Event* event){
    Sprite* target = static_cast<Sprite*>(event->getCurrentTarget());
    Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
    Size s = target->getContentSize();
    Rect rect = Rect(-s.width/2,-s.height/2,s.width,s.height);
    
    if (rect.containsPoint(locationInNode)) {
//        printf("LABEL CLICK %d ===== \n",this->index);
        if (this->index != 11) {
            AppConstant::getInstance()->levelId = this->index;
            Director::getInstance()->replaceScene(GameScene::create());
        }
        return true;
    }
    
    return false;
}

LevelIcon* LevelIcon::create(int data){
    LevelIcon* icon = LevelIcon::create();
    icon->index = data;
    char ss[10];
    sprintf(ss, "%d",icon->index);
    icon->label->setString(ss);
    return icon;
}
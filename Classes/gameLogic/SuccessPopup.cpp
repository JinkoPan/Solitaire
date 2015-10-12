//
//  SuccessPopup.cpp
//  solitraire
//
//  Created by Jinko on 15/10/12.
//
//

#include "SuccessPopup.h"

bool SuccessPopup::init(){
    if (!BasePopup::init()) {
        return false;
    }
    
    //    auto sprite1 = cocos2d::ui::Scale9Sprite::create("green_button_normal.png");
    
    auto sprite1 = cocos2d::ui::Scale9Sprite::createWithSpriteFrameName("popup_common_fg.png");
    //    sprite1->setPosition(Vec2(960/2,540/2));
    addChild(sprite1);
    //设置伸缩后的外框大小
    sprite1->setPreferredSize(Size(Vec2(500, 200)));
    //设置伸缩后的内框大小
    sprite1->setCapInsets(Rect(10, 10, 4, 4));
    
    auto label = Label::createWithTTF("success pass!", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(0,30));
    label->setTextColor(Color4B(0,0,0,255));
    this->addChild(label);
    this->setVisible(false);
    this->setScale(0.05);
    
    //    Sprite* btn = createSprite("green_button_normal.png");
    //    btn->setPosition(Vec2(0,-50));
    //    addChild(btn);
    
    UIButton* btn = UIButton::create("green_button_normal.png", "green_button_normal.png");
    btn->setPosition(Vec2(-80,-80));
    btn->onButtonClicked([=](){
        hide();
        _eventDispatcher->dispatchCustomEvent("back_to_map");
    });
    addChild(btn);
    return true;
}

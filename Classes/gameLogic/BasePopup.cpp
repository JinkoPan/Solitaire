//
//  BasePopup.cpp
//  solitraire
//
//  Created by Jinko on 15/10/10.
//
//

#include "BasePopup.h"
#include "UIScale9Sprite.h"
#include "UIButton.h"


bool BasePopup::init(){
    if (!Node::init()) {
        return false;
    }
    
    return true;
}

void BasePopup::show(){
    auto seq = Sequence::create(
//                                DelayTime::create(0.5),
                                Show::create(),
                                Spawn::create(FadeIn::create(0.5f),
                                              EaseBackIn::create(ScaleTo::create(0.5f, 1)),
                                              NULL),
                                NULL);
    this->runAction(seq);
}

void BasePopup::hide(){
    auto seq = Sequence::create(
//                                DelayTime::create(0.5),
                                Spawn::create(FadeOut::create(0.5f),
                                              EaseBackIn::create(ScaleTo::create(0.5f, 0.05)), NULL),
                                Hide::create(),
                                NULL);
    this->runAction(seq);
}

void BasePopup::showComplete(){
    
}

void BasePopup::hideComplete(){
    
}
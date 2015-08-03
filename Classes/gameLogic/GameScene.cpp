//
//  GameScene.cpp
//  solitraire
//
//  Created by Jinko on 15/7/15.
//
//

#include "GameScene.h"



bool GameScene::init(){
    if (!Scene::init()) {
        return false;
    }
    addSpriteFrameWithFileExt("res/CardAssets.plist");
    this->addChild(GameLayer::create());
    return true;
}
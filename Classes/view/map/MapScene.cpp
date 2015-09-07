//
//  MapScene.cpp
//  solitraire
//
//  Created by Jinko on 15/8/19.
//
//

#include "MapScene.h"
#include "LevelIcon.h"

Scene* MapScene::createScene(){
    Scene* scene = Scene::create();
    MapScene* layer = MapScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool MapScene::init(){
    if (!Layer::init()) {
        return false;
    }
    
//    Label* label = Label::createWithTTF("adfasdfasdfaf","fonts/Marker Felt.ttf", 24);
//    label->setPosition(Vec2(100,100));
//    this->addChild(label);
    LevelIcon* icon;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    for (int i=0; i<10; ++i) {
        for (int j=0; j<5; ++j) {
            icon = LevelIcon::create(i*5+j+1);
            icon->setPosition(Vec2(j*65+MapScene::offsetX,visibleSize.height - i*65-MapScene::offsetY));
            this->addChild(icon);
        }
    }
    
    MenuItemImage* closeItem = MenuItemImage::create("CloseNormal.png","CloseSelected.png",CC_CALLBACK_1(MapScene::onCloseClick, this));
    closeItem->setPosition(Vec2(visibleSize.width-closeItem->getContentSize().width,
                                visibleSize.height-closeItem->getContentSize().height));
    Menu* menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu,1);
    
    
    return true;
}

void MapScene::onCloseClick(Ref* pSender){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
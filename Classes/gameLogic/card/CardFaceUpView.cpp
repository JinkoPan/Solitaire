//
//  CardFaceUpView.cpp
//  solitraire
//
//  Created by Jinko on 15/7/27.
//
//

#include "CardFaceUpView.h"

bool CardFaceUpView::init(){
    if (!Sprite::init()) {
        return false;
    }
    
    return true;
}

Sprite* CardFaceUpView::create(CardVO* cardVO){
    
    Sprite* cardView = createSprite("card_face_up.png");
    char card_tome[16];
    sprintf(card_tome, "card_totem_%d.png",cardVO->card_value);
    Sprite* totem = createSprite(card_tome);
    totem->setScale(0.7);
    Size spSize = cardView->getContentSize();
    totem->setPosition(Vec2(spSize.width/2,spSize.height/2-10));
    cardView->addChild(totem);
    char card_type_str[16];
    sprintf(card_type_str, "card_type_%d.png",cardVO->card_type);
    Sprite* cardType = createSprite(card_type_str);
    cardType->setScale(0.5);
    cardType->setPosition(Vec2(15,spSize.height-40));
    cardView->addChild(cardType);
    char colorType = cardVO->card_type % 2 == 0?'r':'b';
    char card_value_str[20];
    sprintf(card_value_str, "card_value_%c_%s.png",colorType,AppConstant::cards_face[cardVO->card_value].c_str());
    Sprite* card_value = createSprite(card_value_str);
    card_value->setPosition(Vec2(15,spSize.height-16));
    cardView->addChild(card_value);
    
    Sprite* rcardType = createSprite(card_type_str);
    rcardType->setScale(0.3,-0.3);
    rcardType->setPosition(Vec2(spSize.width-10,22));
    cardView->addChild(rcardType);
    
    Sprite* rcard_value = createSprite(card_value_str);
    rcard_value->setScale(-0.3,-0.3);
    rcard_value->setPosition(Vec2(spSize.width-10,10));
    cardView->addChild(rcard_value);
    
    if (cardVO->style == "goal") {
        Sprite* glodBoard = createSprite("card_board.png");
//        Size glodBoardSize = glodBoard->getContentSize();
//        cardView->setContentSize(glodBoardSize);
        glodBoard->setPosition(Vec2(spSize.width/2+2,spSize.height/2-2));
        cardView->addChild(glodBoard);
    }
    return cardView;
}

CardFaceUpView::~CardFaceUpView(){
    
}
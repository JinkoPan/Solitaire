//
//  CardVO.cpp
//  solitraire
//
//  Created by Jinko on 15/7/16.
//
//

#include "CardVO.h"

CardVO::CardVO(){
}

CardVO::CardVO(int cardIndex,int posX,int posY,int rotation, bool face_up,bool key_card,vector<int> cover_cards,int zOrder,string style){
    this->cardIndex = cardIndex;
    this->posX = posX;
    this->posY = posY;
    this->rotation = rotation;
    this->face_up = face_up;
    this->key_card = key_card;
    this->cover_cards = cover_cards;
    this->zOrder = zOrder;
    this->style = style;
}

CardVO::~CardVO(){
    if (cover_cards.size() > 0) {
        cover_cards.clear();
    }
    CCLOG(" destruction CardVO");
}

//CardVO::CardVO(const CardVO& cardVo){
//    this->cardIndex = cardVo.cardIndex;
//    this->posX = cardVo.posX;
//    this->posY = cardVo.posY;
//    this->rotation = cardVo.rotation;
//    this->face_up = cardVo.face_up;
//    this->key_card = cardVo.key_card;
//    this->cover_cards = cardVo.cover_cards;
//    this->zOrder = cardVo.zOrder;
//    this->style = cardVo.style;
//}

CardVO* CardVO::clone(){
    CardVO* cardVO = new CardVO();
    cardVO->cardIndex = this->cardIndex;
    cardVO->card_type = this->card_type;
    cardVO->card_value = this->card_value;
    cardVO->posX = this->posX;
    cardVO->posY = this->posY;
    cardVO->rotation = this->rotation;
    cardVO->face_up = this->face_up;
    cardVO->key_card = this->key_card;
    cardVO->cover_cards = this->cover_cards;
    cardVO->zOrder = this->zOrder;
    cardVO->style = this->style;
    return cardVO;
}


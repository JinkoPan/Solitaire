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
    
}


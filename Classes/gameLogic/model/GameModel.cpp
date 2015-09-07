//
//  GameModel.cpp
//  solitraire
//
//  Created by Jinko on 15/7/27.
//
//

#include "GameModel.h"

GameModel::GameModel(){
    curCardVO = getRandomCardVO();
    collection_card.push_back(curCardVO);
}

GameModel::~GameModel(){
    if (puzzleLevelDefinition != nullptr) {
        delete puzzleLevelDefinition;
        puzzleLevelDefinition = nullptr;
    }
    
    if (blitzLevelDefinition != nullptr) {
        delete blitzLevelDefinition;
        blitzLevelDefinition = nullptr;
    }
    
    for (int i; i<collection_card.size(); ++i) {
        if (collection_card[i]!= nullptr) {
            delete collection_card[i];
        }
    }
    collection_card.clear();
    
    if (curCardVO != NULL) {
        //delete curCardVO;
        curCardVO = nullptr;
    }
    
    CCLOG("gamemodel destruction");
}

void GameModel::createLevelDefinition(string fileName){

    rapidjson::Document doc;
    ssize_t size;
    unsigned char* pByte = NULL;
    do{
        pByte = FileUtils::getInstance()->getFileData(fileName, "r", &size);
        CC_BREAK_IF(pByte == NULL || strcmp((char*)pByte, "")== 0);
        std::string data((char*)pByte,size);
        CC_SAFE_DELETE_ARRAY(pByte);
        doc.Parse<kParseDefaultFlags>(data.c_str());
        CC_BREAK_IF(doc.HasParseError());
        
        rapidjson::Value &mode_ = doc["mode"];
        mode = mode_.GetString();
        
        if (mode == "puzzle") {
            puzzleLevelDefinition = new PuzzleLevelDefinition();
            puzzleLevelDefinition->initData(doc);
        }else{
            blitzLevelDefinition = new BlitzLevelDefinition();
            blitzLevelDefinition->initData(doc);
        }
        
    }while (0);
}

CardVO* GameModel::getCardVOByIndex(int index){
    vector<CardVO*> cards = puzzleLevelDefinition->cards;
    for (int i = 0; i<cards.size(); ++i) {
        if (cards[i]->cardIndex == index){
            return cards[i];
        }
    }
    return nullptr;
}

bool GameModel::cardCheck(CardVO* card){
    if (puzzleLevelDefinition->cards_deck <= 0) {
        return false;
    }
    if (checkIsRight(curCardVO->card_value,card->card_value)){
        this->curCardVO = card;
        this->collection_card.push_back(card);
        updateCoverCardCount(card->cardIndex);
        puzzleLevelDefinition->cards_deck--;
        return true;
    }
    return false;
}



CardVO* GameModel::getRandomCardVO(){
    CardVO* cardVO = new (nothrow) CardVO();
    if (cardVO) {
        cardVO->cardIndex = 0;
        cardVO->card_type = RANDOMNUM(4)+1;
        cardVO->card_value = RANDOMNUM(13)+1;
        cardVO->rotation = 0;
        cardVO->coverCount = 0;
        cardVO->face_up = true;
    }
    return cardVO;
}

void GameModel::updateCoverCardCount(int cardIndex){
    vector<CardVO*> cards = puzzleLevelDefinition->cards;
    vector<int> vec;
    for (int i=0; i<cards.size(); ++i) {
        if (cards[i]->cardIndex == cardIndex) {
            vec = cards[i]->cover_cards;
            for (int j=0; j<vec.size(); ++j) {
                
                cards[vec[j]]->coverCount--;
            }
        }
        
    }
}
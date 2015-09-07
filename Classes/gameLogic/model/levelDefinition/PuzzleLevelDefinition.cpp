//
//  PuzzleLevelDefinition.cpp
//  solitraire
//
//  Created by Jinko on 15/7/24.
//
//

#include "PuzzleLevelDefinition.h"
PuzzleLevelDefinition::PuzzleLevelDefinition(){
    
}

PuzzleLevelDefinition::~PuzzleLevelDefinition(){
    CCLOG("~PuzzleLevelDefinition");
    for (int i = 0; i<cards.size(); ++i) {
        if (cards[i] != NULL) {
            delete cards[i];
        }
    }
    cards.clear();
    i_b_percent.clear();
    i_b_strength.clear();
    tasks_values.clear();
    tasks.clear();
}


void PuzzleLevelDefinition::initData(rapidjson::Document &doc){
    int cardIndex;
    int posX;
    int posY;
    int rotation;
    bool face_up;
    bool key_card;
    vector<int> cover_cards;
    int zOrder;
    string style;
    Size visibleSize = Director::getInstance()->getVisibleSize();

    do{
        if (doc.HasMember("wood_pieces")) {
            rapidjson::Value &wood_pieces_ = doc["wood_pieces"];
            wood_pieces = wood_pieces_.GetInt();
        }
        
        
        rapidjson::Value &cards_deck_ = doc["cards_deck"];
        cards_deck = cards_deck_.GetInt();
        
        rapidjson::Value &mode_ = doc["mode"];
        mode = mode_.GetString();
        
        rapidjson::Value &i_b_moves_ = doc["i_b_moves"];
        i_b_moves = i_b_moves_.GetInt();
        
        rapidjson::Value &i_b_time_ = doc["i_b_time"];
        i_b_time = i_b_time_.GetInt();
        
        rapidjson::Value &i_b_percent_ = doc["i_b_percent"];
        i_b_percent = getIntVector(i_b_percent_);
        
        rapidjson::Value &i_b_strength_ = doc["i_b_strength"];
        i_b_strength = getIntVector(i_b_strength_);
        
        rapidjson::Value &tasks_values_ = doc["tasks_values"];
        tasks_values = getIntVector(tasks_values_);
        
        rapidjson::Value &tasks_ = doc["tasks"];
        tasks = getIntVector(tasks_);
        
        
        rapidjson::Value &array = doc["cards"];
        
        if (array.IsArray()) {
            for (rapidjson::SizeType i=0; i<array.Size(); i++) {
                rapidjson::Value &item = array[i];
                if (item.IsArray()) {
                    int k = 0;
                    cardIndex = item[k++].GetInt();
                    posX = item[k++].GetInt();
                    posY = visibleSize.height - item[k++].GetInt();
                    rotation = item[k++].GetInt();
                    face_up = item[k++].GetBool();
                    key_card = item[k++].GetBool();
                    rapidjson::Value &arr = item[k++];
                    cover_cards.clear();
                    for (rapidjson::SizeType j=0; j<arr.Size(); j++) {
                        cover_cards.push_back(arr[j].GetInt());
                    }
                    zOrder = item[k++].GetInt();
                    style = item[k++].GetString();
//                    printf("%d  %s ",cardIndex,style.c_str());
                    CardVO* cardvo = new CardVO(cardIndex,posX,posY,rotation,face_up,key_card,cover_cards,zOrder,style);
                    cardvo->card_type = RANDOMNUM(4)+1;
                    cardvo->card_value = RANDOMNUM(13)+1;
                    cards.push_back(cardvo);
                }
            }
        }
    }while (0);
    sort(cards.begin(), cards.end(), std::bind(&PuzzleLevelDefinition::sortCompareFunc,this,std::placeholders::_1,std::placeholders::_2));
    initCoverCount();
//    for (int i=0; i<cards.size(); ++i) {
//        printf("\n index: %d,   value: %d  coverCount:%d",cards[i]->cardIndex,cards[i]->card_value,cards[i]->coverCount);
//    }
}

bool PuzzleLevelDefinition::sortCompareFunc(CardVO* a, CardVO* b){
    return a->cardIndex < b->cardIndex;
}

vector<int> PuzzleLevelDefinition::getIntVector(rapidjson::Value &arr){
    vector<int> result;
    int k;
    if (arr.IsArray()) {
        for (rapidjson::SizeType i=0; i<arr.Size(); i++) {
            k = arr[i].GetInt();
            result.push_back(k);
        }
    }
    return result;
}

void PuzzleLevelDefinition::initCoverCount(){
    vector<int> covers;
    for (int i=0; i<cards.size(); ++i) {
        covers = cards[i]->cover_cards;
        for (int j=0; j<covers.size(); ++j) {
            cards[covers[j]]->coverCount++;
        }
    }
}

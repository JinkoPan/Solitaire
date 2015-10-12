//
//  PuzzleLevelDefinition.h
//  solitraire
//
//  Created by Jinko on 15/7/24.
//
//

#ifndef __solitraire__PuzzleLevelDefinition__
#define __solitraire__PuzzleLevelDefinition__

#include <stdio.h>
#include "cocos2d.h"
#include <string>
#include "json/document.h"
#include <vector>
#include "../vo/CardVO.h"
#include "LevelDefinition.h"
#include "AppConstant.h"
#include "TaskVO.h"
#include "GoldCardTask.h"
#include "RemainCardTask.h"
#include "ComboCardTask.h"


using namespace std;
using namespace cocos2d;
using namespace rapidjson;

class PuzzleLevelDefinition:public LevelDefinition {
public:
    PuzzleLevelDefinition();
    ~PuzzleLevelDefinition();
    vector<int> getIntVector(rapidjson::Value &arr);
    void initData(rapidjson::Document &doc);
    void initCoverCount();
    bool sortCompareFunc(CardVO* a, CardVO* b);
    void createTaskVec(const vector<int> &t,const vector<int> &t_v);
public:
    int wood_pieces;
    int cards_deck;
    vector<int> i_b_percent;
    string mode;
    int i_b_time;
    vector<int> i_b_strength;
    vector<int> tasks_values;
    int i_b_moves;
    vector<CardVO*> cards;
    vector<int> tasks;
    vector<TaskVO*> taskVec;
};

#endif /* defined(__solitraire__PuzzleLevelDefinition__) */

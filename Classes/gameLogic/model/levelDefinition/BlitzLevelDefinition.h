//
//  BlitzLevelDefinition.h
//  solitraire
//
//  Created by Jinko on 15/7/24.
//
//

#ifndef __solitraire__BlitzLevelDefinition__
#define __solitraire__BlitzLevelDefinition__

#include <stdio.h>
#include "cocos2d.h"
#include "json/document.h"
#include "../vo/CardVO.h"
#include "LevelDefinition.h"

#include <string>
#include <vector>

using namespace std;
using namespace cocos2d;
using namespace rapidjson;

class BlitzLevelDefinition:public LevelDefinition {
public:
    BlitzLevelDefinition();
    ~BlitzLevelDefinition();
    void initData(rapidjson::Document &doc);
public:
    int area;
    int cards_table;
    string mode;
    int key_card_1;
    int key_card_2;
    vector<int> i_b_strength;
    int number;
    int time_bonus;
    int timelines;
    int level_time;
    int cards_deck;
    vector<int> stars;
    string title;
    int lines;

    
};

#endif /* defined(__solitraire__BlitzLevelDefinition__) */

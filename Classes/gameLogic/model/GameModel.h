//
//  GameModel.h
//  solitraire
//
//  Created by Jinko on 15/7/27.
//
//

#ifndef __solitraire__GameModel__
#define __solitraire__GameModel__

#include <stdio.h>
#include <string>
#include "cocos2d.h"
#include "LevelDefinition.h"
#include "levelDefinition/PuzzleLevelDefinition.h"
#include "levelDefinition/BlitzLevelDefinition.h"
#include <vector>
#include "CardVO.h"
#include "utils.h"

using namespace std;
using namespace cocos2d;

class GameModel{
public:
    GameModel();
    ~GameModel();
    void createLevelDefinition(string fileName);
    CardVO* getCardVOByIndex(int index);
    bool cardCheck(CardVO* card);
    CardVO* getRandomCardVO();
    void updateCoverCardCount(int cardIndex);
public:
    PuzzleLevelDefinition* puzzleLevelDefinition = nullptr;
    BlitzLevelDefinition* blitzLevelDefinition = nullptr;
    string mode;
    vector<CardVO*> collection_card;
    CardVO* curCardVO = nullptr;
    int combo;
    
};

#endif /* defined(__solitraire__GameModel__) */

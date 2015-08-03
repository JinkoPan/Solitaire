//
//  LevelDefinition.h
//  solitraire
//
//  Created by Jinko on 15/7/27.
//
//

#ifndef __solitraire__LevelDefinition__
#define __solitraire__LevelDefinition__

#include <stdio.h>
#include "cocos2d.h"
#include <string>
#include "json/document.h"
#include <vector>
#include "../vo/CardVO.h"
#include "AppConstant.h"


using namespace std;
using namespace rapidjson;

class LevelDefinition {
public:
    LevelDefinition();
    virtual ~LevelDefinition();
    virtual void initData(rapidjson::Document &doc) = 0;
};

#endif /* defined(__solitraire__LevelDefinition__) */

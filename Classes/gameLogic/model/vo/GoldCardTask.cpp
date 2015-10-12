//
//  GoldCardTask.cpp
//  solitraire
//
//  Created by Jinko on 15/10/9.
//
//

#include "GoldCardTask.h"

bool GoldCardTask::checkFinish(){
    bool finish = false;
    if (this->currentCount == this->targetCount) {
        finish = true;
    }
    return finish;
}

GoldCardTask::~GoldCardTask(){
    
}
//
//  AppConstant.h
//  solitraire
//
//  Created by Jinko on 15/7/27.
//
//

#ifndef __solitraire__AppConstant__
#define __solitraire__AppConstant__

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <time.h>

using namespace std;

#define RANDOMNUM(x) (rand()%x)

class AppConstant{
public:
    AppConstant();
    ~AppConstant();
    static map<int,string> createCardFace();
    static map<string,int> createCardValue();
public:
    int levelId;
    static map<int,string> cards_face;
    static map<string,int> card_value;
    
};

#endif /* defined(__solitraire__AppConstant__) */

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
#define OFFSETX (300)
#define OFFSETY (-100)
#define CARD_Y (160)

class AppConstant{
public:
    ~AppConstant();
    static map<int,string> createCardFace();
    static map<string,int> createCardValue();
    static AppConstant* getInstance();
public:
    int levelId;
    static map<int,string> cards_face;
    static map<string,int> card_value;
private:
    AppConstant();
    AppConstant(const AppConstant&);
    AppConstant& operator=(const AppConstant&);
    static AppConstant* _instance;
    
};

#endif /* defined(__solitraire__AppConstant__) */

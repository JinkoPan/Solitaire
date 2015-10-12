//
//  CardVO.h
//  solitraire
//
//  Created by Jinko on 15/7/16.
//
//

#ifndef __solitraire__CardVO__
#define __solitraire__CardVO__


#include <string.h>
#include <vector>


using namespace std;



class CardVO {
public:
    CardVO();
    CardVO(int cardIndex,int posX,int posY,int rotation,bool face_up,bool key_card,vector<int> cover_cards,int zOrder,string style);
    virtual ~CardVO();
//    CardVO(const CardVO& cardVo);
    CardVO* clone();
public:
    int card_value;
    int card_type;
    int cardIndex;
    int posX;
    int posY;
    int rotation;
    bool face_up;
    bool key_card;
    vector<int> cover_cards;
    int zOrder;
    string style;
    int coverCount = 0;
    
};

#endif /* defined(__solitraire__CardVO__) */

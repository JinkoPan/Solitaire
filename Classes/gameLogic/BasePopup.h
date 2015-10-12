//
//  BasePopup.h
//  solitraire
//
//  Created by Jinko on 15/10/10.
//
//

#ifndef __solitraire__BasePopup__
#define __solitraire__BasePopup__

#include <stdio.h>
#include "cocos2d.h"
#include "utils.h"

USING_NS_CC;

class BasePopup:public Node{
public:
    virtual bool init();
    CREATE_FUNC(BasePopup);
    void show();
    void showComplete();
    void hide();
    void hideComplete();
};


#endif /* defined(__solitraire__BasePopup__) */

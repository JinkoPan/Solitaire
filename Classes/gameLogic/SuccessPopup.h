//
//  SuccessPopup.h
//  solitraire
//
//  Created by Jinko on 15/10/12.
//
//

#ifndef __solitraire__SuccessPopup__
#define __solitraire__SuccessPopup__

#include <stdio.h>
#include "cocos2d.h"
#include "BasePopup.h"
#include "UIScale9Sprite.h"
#include "UIButton.h"

using namespace cocos2d;

class SuccessPopup:public BasePopup{
public:
    bool init();
    CREATE_FUNC(SuccessPopup);
    
};

#endif /* defined(__solitraire__SuccessPopup__) */

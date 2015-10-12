//
//  UIButton.h
//  solitraire
//
//  Created by Jinko on 15/10/10.
//
//

#ifndef __solitraire__UIButton__
#define __solitraire__UIButton__

#include <stdio.h>
#include "cocos2d.h"
#include <string>
#include "utils.h"

using namespace cocos2d;
using namespace std;

class UIButton:public Node{
public:
    bool initView(const std::string &normal,const std::string &clicked);
    static UIButton* create(const std::string &normal,const std::string &clicked);
    void onButtonClicked(std::function<void()> callback);
public:
    Sprite* normal_sp;
    Sprite* clicked_sp;
};
#endif /* defined(__solitraire__UIButton__) */

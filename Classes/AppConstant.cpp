//
//  AppConstant.cpp
//  solitraire
//
//  Created by Jinko on 15/7/27.
//
//

#include "AppConstant.h"

map<int,string> AppConstant::cards_face = AppConstant::createCardFace();
map<string,int> AppConstant::card_value = AppConstant::createCardValue();


AppConstant::AppConstant(){
    levelId = 1;
    
}
AppConstant::~AppConstant(){
    
}

AppConstant* AppConstant::_instance = new(nothrow) AppConstant();

AppConstant* AppConstant::getInstance(){
    return _instance;
}

AppConstant::AppConstant(const AppConstant&){
    
}

AppConstant& AppConstant::operator=(const AppConstant&){
    return *this;
}

map<int,string> AppConstant::createCardFace(){
//    srand((unsigned)time(NULL));
    map<int,string> tempMap;
    tempMap.insert({1,"2"});
    tempMap.insert({2,"3"});
    tempMap.insert({3,"4"});
    tempMap.insert({4,"5"});
    tempMap.insert({5,"6"});
    tempMap.insert({6,"7"});
    tempMap.insert({7,"8"});
    tempMap.insert({8,"9"});
    tempMap.insert({9,"10"});
    tempMap.insert({10,"J"});
    tempMap.insert({11,"Q"});
    tempMap.insert({12,"K"});
    tempMap.insert({13,"A"});
    tempMap.insert({0,"JO"});
    return tempMap;
}

map<string,int> AppConstant::createCardValue(){
    map<string,int> tempMap;
    tempMap.insert({"2",1});
    tempMap.insert({"3",2});
    tempMap.insert({"4",3});
    tempMap.insert({"5",4});
    tempMap.insert({"6",5});
    tempMap.insert({"7",6});
    tempMap.insert({"8",7});
    tempMap.insert({"9",8});
    tempMap.insert({"10",9});
    tempMap.insert({"J",10});
    tempMap.insert({"Q",11});
    tempMap.insert({"K",12});
    tempMap.insert({"A",13});
    tempMap.insert({"JO",0});
    return tempMap;
}


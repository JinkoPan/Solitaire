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
    
    
//    cards_face.insert({1,"2"});
//    cards_face.insert({2,"3"});
//    cards_face.insert({3,"4"});
//    cards_face.insert({4,"5"});
//    cards_face.insert({5,"6"});
//    cards_face.insert({6,"7"});
//    cards_face.insert({7,"8"});
//    cards_face.insert({8,"9"});
//    cards_face.insert({9,"10"});
//    cards_face.insert({10,"J"});
//    cards_face.insert({11,"Q"});
//    cards_face.insert({12,"K"});
//    cards_face.insert({13,"A"});
//    cards_face.insert({0,"JO"});
//    
//    
//    card_value.insert({"2",1});
//    card_value.insert({"3",2});
//    card_value.insert({"4",3});
//    card_value.insert({"5",4});
//    card_value.insert({"6",5});
//    card_value.insert({"7",6});
//    card_value.insert({"8",7});
//    card_value.insert({"9",8});
//    card_value.insert({"10",9});
//    card_value.insert({"J",10});
//    card_value.insert({"Q",11});
//    card_value.insert({"K",12});
//    card_value.insert({"A",13});
//    card_value.insert({"JO",0});
}
AppConstant::~AppConstant(){
    
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
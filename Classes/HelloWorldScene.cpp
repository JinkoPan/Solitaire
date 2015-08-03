#include "HelloWorldScene.h"

#include "json/document.h"
#include <iostream>
#include "cocostudio/CocoStudio.h"
#include "cocostudio/CocoLoader.h"
#include "cocostudio/ActionTimeline/CSLoader.h"
#include "cocostudio/CSParseBinary_generated.h"
#include "cocostudio/FlatBuffersSerialize.h"
#include "ui/CocosGUI.h"


using namespace rapidjson;
using namespace std;


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
    readJsonFileTest2();
    
    
    return true;
}


void HelloWorld::readJsonFileTest2(){
    Document doc;
    ssize_t size;
    std::string data = (char*) FileUtils::getInstance()->getFileData("level1.json", "r", &size);
    doc.Parse<kParseDefaultFlags>(data.c_str());
    printf("%s\n",data.c_str());
}


void HelloWorld::readJsonFileTest(){
    Document doc;
    ssize_t size;
    std::string data = (char*) FileUtils::getInstance()->getFileData("ball.json", "r", &size);
//    (char*)CCFileUtils::sharedFileUtils()->getFileData("ball.json", "r", &size);
    doc.Parse<kParseDefaultFlags>(data.c_str());
    printf("%s\n",data.c_str());
    printf("\n");
//    rapidjson::Value &array = doc["entities"];
//    if (array.IsArray()) {
//        for (rapidjson::SizeType i=0; i<array.Size(); i++) {
//            rapidjson::Value &p = array[i];
//            if (p.HasMember("entity")) {
//                rapidjson::Value &enty = p["entity"];
//                if (enty.HasMember("TapOpposite")) {
//                    rapidjson::Value &tapOpposite = enty["TapOpposite"];
//                    int tap = tapOpposite.GetInt();
//                    cout<< tap<<endl;
//                }
//                if (enty.HasMember("Interval")) {
//                    rapidjson::Value &tapOpposite = enty["Interval"];
//                    double tap = tapOpposite.GetDouble();
//                    cout<< tap<<endl;
//                }
//
//                if (enty.HasMember("BallNum")) {
//                    rapidjson::Value &tapOpposite = enty["BallNum"];
//                    int tap = tapOpposite.GetInt();
//                    cout<< tap<<endl;
//                }
//
//            }
//        }
//    }
    rapidjson::Value &array = doc["entities"];

        int t = 2;
        rapidjson::Value &p = array[t];

        rapidjson::Value &item = p["entity"];

        rapidjson::Value &ballNum = item["BallNum"];
        int num = ballNum.GetInt();
        printf("%d\n",num);

    for (auto it = item.MemberonBegin();it!=item.MemberonEnd(); ++it) {
        auto name = (&it->name)->GetString();
//        type_info type_id = typeid(name);
        const char* ch = name;
        string _name = (string)ch;
        
        cout<< name <<endl;
//        cout<< (&it->value)->GetDouble() <<endl;
//        cout<< decltype(name)<<endl;
        rapidjson::Value &_value = item[name];

        if (_value.IsInt()) {
            int _num = _value.GetInt();
            printf("%d\n",_num);
        }else if(_value.IsString()){
            string _num = (string)_value.GetString();
            printf("%s\n",_num.c_str());
        }else if(_value.IsDouble()){
            double _num = _value.GetDouble();
            printf("%f\n",_num);
        }
//        cout<<(&it->value)->GetInt()<<endl;
        
    }

    
    
    
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

#include"GameScene.h"
#include"HomeScene.h"
#include"MapLayer.h"
#include"SimpleAudioEngine.h"
#include"Hero.h"
#include"cocos2d.h" 
#include"cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d;

Scene*GameScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}                                       
bool GameScene::init()
{
    if (!Layer::init())
        return false;

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto bg = Sprite::create("frame.png");
    bg->setPosition(Vec2::ZERO);
    bg->setAnchorPoint(Vec2::ZERO);
    this->addChild(bg);                                  //将游戏场景的主界面作为背景

    auto exitItem = MenuItemImage::create(
        "game_exit.png",
        "game_exit.png",
        CC_CALLBACK_1(GameScene::menuExitcallback, this));
    exitItem->setPosition(Vec2(640, 7));
    exitItem->setAnchorPoint(Vec2::ZERO);               //设置游戏时的“退出”按钮

    auto menu = Menu::create(exitItem, NULL);            //创建菜单项
    menu->setPosition(Vec2::ZERO);
    menu->setAnchorPoint(Vec2::ZERO);
    addChild(menu, 1);                                   //将退出按钮加入到菜单项中
    
	player1 = new Hero();                               //创建人物
	player1 -> addPlayerAnimation();
	player1 -> addPlayer();
	this->addChild(player1, 1);

	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	
    this->initMapLayer();
    return true;
}

//点击退出按钮之后的回调函数
void GameScene::menuExitcallback(Ref*pSender)
{
    Director::getInstance()->popScene();         //点击退出按钮后返回到home界面
}                                     

//创建地图层的函数定义
void GameScene::initMapLayer()
{
    MapLayer*map = MapLayer::create();            //创建地图
    this->addChild(map);                          //将地图层加入到该场景中
}

void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event*event)
{
	player1->Moveto(player1->getDirection(keyCode));
	player1->stopAllActions();
}



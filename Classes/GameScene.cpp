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
    this->addChild(bg);                                  //����Ϸ��������������Ϊ����

    auto exitItem = MenuItemImage::create(
        "game_exit.png",
        "game_exit.png",
        CC_CALLBACK_1(GameScene::menuExitcallback, this));
    exitItem->setPosition(Vec2(640, 7));
    exitItem->setAnchorPoint(Vec2::ZERO);               //������Ϸʱ�ġ��˳�����ť

    auto menu = Menu::create(exitItem, NULL);            //�����˵���
    menu->setPosition(Vec2::ZERO);
    menu->setAnchorPoint(Vec2::ZERO);
    addChild(menu, 1);                                   //���˳���ť���뵽�˵�����
    
	player1 = new Hero();                               //��������
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

//����˳���ť֮��Ļص�����
void GameScene::menuExitcallback(Ref*pSender)
{
    Director::getInstance()->popScene();         //����˳���ť�󷵻ص�home����
}                                     

//������ͼ��ĺ�������
void GameScene::initMapLayer()
{
    MapLayer*map = MapLayer::create();            //������ͼ
    this->addChild(map);                          //����ͼ����뵽�ó�����
}

void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event*event)
{
	player1->Moveto(player1->getDirection(keyCode));
	player1->stopAllActions();
}



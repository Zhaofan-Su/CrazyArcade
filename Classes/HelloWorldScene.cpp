#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "HomeScene.h"


USING_NS_CC;
using namespace CocosDenshion;

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
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto bg = TMXTiledMap::create("map/first_scene.tmx");
    addChild(bg);                                               //Ϊ��Ϸ����������ñ���

    //���á��رա���ť
    auto closeItem = MenuItemImage::create(
        "closeNormal.png",
        "closeSelected.png",
        CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
        origin.y + closeItem->getContentSize().height / 2));

    //���á�go����ť
    auto goItem = MenuItemImage::create(
        "menuItem/go1.png",
        "menuItem/go2.png",
        CC_CALLBACK_1(HelloWorld::menuNextCallback, this));
    goItem->setPosition(Vec2::ZERO);
    goItem->setAnchorPoint(Vec2::ZERO);

    auto menu = Menu::create(closeItem, goItem, NULL);         //����һ���˵���
    menu->setPosition(Vec2::ZERO);                             //�����رհ�ť��go��ť���뵽�ò˵�����
    this->addChild(menu, 1);                                   //��Ӹò˵��������

    SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/home_bgm.mp3", true);
    return true;
}


//�رհ�ť�ĺ�������
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();                          //�˳���������
}

//go��ť�ĺ�������
void HelloWorld::menuNextCallback(Ref*pSender)
{
    auto sc = Home::createScene();                            
    Director::getInstance()->replaceScene(sc);                //���뵽home������
    SimpleAudioEngine::getInstance()->playEffect("sound/click.wav"); //���ŵ����Ч
}

/*void HelloWorld::onEnterTransitionDidFinish()
{
    Layer::onEnterTransitionDidFinish();
    log("HellowWorld onEnterTransitionDidFinish");
    SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/home_bgm.mp3", true);    //���Ÿý��汳������
}

void HelloWorld::onExitTransitionDidStart()
{
    Layer::onExitTransitionDidStart();
    log("HelloWorld onExitTransitionDidStart");
    SimpleAudioEngine::getInstance()->stopBackgroundMusic("sound/home_bgm.mp3");
}*/
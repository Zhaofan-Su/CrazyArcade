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
    addChild(bg);                                               //为游戏最初界面设置背景

    //设置“关闭”按钮
    auto closeItem = MenuItemImage::create(
        "closeNormal.png",
        "closeSelected.png",
        CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
        origin.y + closeItem->getContentSize().height / 2));

    //设置“go”按钮
    auto goItem = MenuItemImage::create(
        "menuItem/go1.png",
        "menuItem/go2.png",
        CC_CALLBACK_1(HelloWorld::menuNextCallback, this));
    goItem->setPosition(Vec2::ZERO);
    goItem->setAnchorPoint(Vec2::ZERO);

    auto menu = Menu::create(closeItem, goItem, NULL);         //声明一个菜单项
    menu->setPosition(Vec2::ZERO);                             //并将关闭按钮、go按钮加入到该菜单项中
    this->addChild(menu, 1);                                   //添加该菜单项到场景中

    SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/home_bgm.mp3", true);
    return true;
}


//关闭按钮的函数定义
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();                          //退出整个程序
}

//go按钮的函数定义
void HelloWorld::menuNextCallback(Ref*pSender)
{
    auto sc = Home::createScene();                            
    Director::getInstance()->replaceScene(sc);                //进入到home界面中
    SimpleAudioEngine::getInstance()->playEffect("sound/click.wav"); //播放点击音效
}

/*void HelloWorld::onEnterTransitionDidFinish()
{
    Layer::onEnterTransitionDidFinish();
    log("HellowWorld onEnterTransitionDidFinish");
    SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/home_bgm.mp3", true);    //播放该界面背景音乐
}

void HelloWorld::onExitTransitionDidStart()
{
    Layer::onExitTransitionDidStart();
    log("HelloWorld onExitTransitionDidStart");
    SimpleAudioEngine::getInstance()->stopBackgroundMusic("sound/home_bgm.mp3");
}*/
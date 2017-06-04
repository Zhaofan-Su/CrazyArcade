#include"HomeScene.h"
#include"SettingScene.h"
#include"HelpScene.h"
#include"GameScene.h"
#include"SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;
Scene*Home::createScene()
{
    auto scene = Scene::create();
    auto layer = Home::create();
    scene->addChild(layer);
    return scene;
}
bool Home::init()
{
    if (!Layer::init())
        return false;

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto background = Sprite::create("bg.png");
    background->setPosition(Vec2::ZERO);
    background->setAnchorPoint(Vec2::ZERO);
    this->addChild(background);                                 //为主界面创建背景

    auto startItem = MenuItemImage::create(
        "menuItem/home_start_butt_1.png",
        "menuItem/home_start_butt_2.png",
        CC_CALLBACK_1(Home::menuStartCallback, this));
    startItem->setPosition(Vec2(0, 10));                      //设置“开始游戏”按钮
    //startItem->setAnchorPoint(Vec2::ZERO);

    auto setItem = MenuItemImage::create(
        "menuItem/home_set_butt_1.png",
        "menuItem/home_set_butt_2.png",
        CC_CALLBACK_1(Home::menuSetCallback, this));           //设置“设置”按钮
    //setItem->setAnchorPoint(Vec2::ZERO);
    setItem->setPosition(Vec2(0,150));

    auto helpItem = MenuItemImage::create(
        "menuItem/home_help_butt_1.png",
        "menuItem/home_help_butt_2.png",
        CC_CALLBACK_1(Home::menuHelpCallback, this));          //设置“帮助”按钮
    //helpItem->setAnchorPoint(Vec2::ZERO);
    helpItem->setPosition(Vec2(0,-150));

    auto menu = Menu::create(startItem, setItem, helpItem, NULL);
    menu->setAnchorPoint(Vec2::ZERO);
    this->addChild(menu, 3);                               //将所有的按钮添加到菜单项中

    return true;
}

//点击开始按钮调用的函数
void Home::menuStartCallback(Ref*pSender)
{
    auto sc = GameScene::createScene();
    Director::getInstance()->pushScene(sc);             //进入游戏界面
    SimpleAudioEngine::getInstance()->playEffect("sound/click.wav");   //播放点击音效
    //SimpleAudioEngine::getInstance()->stopBackgroundMusic("sound/home_bgm.mp3");   //停止播放主页音乐
}

//点击设置按钮调用的函数
void Home::menuSetCallback(Ref*pSender)
{
    auto sc = Setting::createScene();
    Director::getInstance()->pushScene(sc);               //进入设置界面
    SimpleAudioEngine::getInstance()->playEffect("sound/click.wav");    //播放点击音效
}

//点击帮助按钮调用的函数
void Home::menuHelpCallback(Ref*pSender)
{
    
    auto sc = Help::createScene();
    Director::getInstance()->pushScene(sc);               //进入帮助界面
    SimpleAudioEngine::getInstance()->playEffect("sound/click.wav");
}

/*void Home::onEnter()
{
    Layer::onEnter();
    log("Home onEnter");
}
void Home::onEnterTransitionDidFinish()
{
    Layer::onEnterTransitionDidFinish();
    log("Home onEnterTransitionDidFinish");
    SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/home_bgm.mp3", true);
}
void Home::onExit()
{
    Layer::onExit();
    log("Home onExit");
}
void Home::onExitTransitionDidStart()
{
    Layer::onExitTransitionDidStart();
    log("Home onExitTransitionDidStart");
}
void Home::cleanup()
{
    Layer::cleanup();
    log("Home cleanup");
}*/
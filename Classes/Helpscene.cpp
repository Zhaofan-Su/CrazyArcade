#include"HelpScene.h"
//#include"HomeScene.h"
#include"SimpleAudioEngine.h"

USING_NS_CC;

Scene* Help::createScene()
{
    auto scene = Scene::create();
    auto layer = Help::create();
    scene->addChild(layer);
    return scene;
}

bool Help::init()
{
    if (!Layer::init())
        return false;

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto background = Sprite::create("bg.png");
    background->setPosition(Vec2::ZERO);
    background->setAnchorPoint(Vec2::ZERO);
    this->addChild(background);                                //为帮助界面设置背景

    auto GobackItem = MenuItemImage::create(
        "menuItem/goback1.png",
        "menuItem/goback2.png",
        CC_CALLBACK_1(Help::menuGobackCallback, this));
    GobackItem->setPosition(Vec2::ZERO);            //创建返回按钮
    GobackItem->setAnchorPoint(Vec2::ZERO);

    auto menu = Menu::create(GobackItem, NULL);
    menu->setPosition(Vec2::ZERO);
    addChild(menu, 1);                                 //将返回按钮添加到菜单项中，并加入到该场景中

    return true;
}
void Help::menuGobackCallback(Ref*pSender)
{
    Director::getInstance()->popScene();                 //点击返回按钮后回到home界面
}
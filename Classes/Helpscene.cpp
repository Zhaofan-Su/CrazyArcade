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
    this->addChild(background);                                //Ϊ�����������ñ���

    auto GobackItem = MenuItemImage::create(
        "menuItem/goback1.png",
        "menuItem/goback2.png",
        CC_CALLBACK_1(Help::menuGobackCallback, this));
    GobackItem->setPosition(Vec2::ZERO);            //�������ذ�ť
    GobackItem->setAnchorPoint(Vec2::ZERO);

    auto menu = Menu::create(GobackItem, NULL);
    menu->setPosition(Vec2::ZERO);
    addChild(menu, 1);                                 //�����ذ�ť��ӵ��˵����У������뵽�ó�����

    return true;
}
void Help::menuGobackCallback(Ref*pSender)
{
    Director::getInstance()->popScene();                 //������ذ�ť��ص�home����
}
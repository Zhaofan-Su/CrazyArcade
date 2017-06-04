#include"HomeScene.h"
#include"SettingScene.h"
#include"HelpScene.h"
#include"GameScene.h"
#include"SimpleAudioEngine.h"

USING_NS_CC;
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
    this->addChild(background);                                 //Ϊ�����洴������

    auto startItem = MenuItemImage::create(
        "menuItem/home_start_butt_1.png",
        "menuItem/home_start_butt_2.png",
        CC_CALLBACK_1(Home::menuStartCallback, this));
    startItem->setPosition(Vec2(0, 10));                      //���á���ʼ��Ϸ����ť
    //startItem->setAnchorPoint(Vec2::ZERO);

    auto setItem = MenuItemImage::create(
        "menuItem/home_set_butt_1.png",
        "menuItem/home_set_butt_2.png",
        CC_CALLBACK_1(Home::menuSetCallback, this));           //���á����á���ť
    //setItem->setAnchorPoint(Vec2::ZERO);
    setItem->setPosition(Vec2(0,150));

    auto helpItem = MenuItemImage::create(
        "menuItem/home_help_butt_1.png",
        "menuItem/home_help_butt_2.png",
        CC_CALLBACK_1(Home::menuHelpCallback, this));          //���á���������ť
    //helpItem->setAnchorPoint(Vec2::ZERO);
    helpItem->setPosition(Vec2(0,-150));

    auto menu = Menu::create(startItem, setItem, helpItem, NULL);
    menu->setAnchorPoint(Vec2::ZERO);
    this->addChild(menu, 3);                               //�����еİ�ť���ӵ��˵�����

    return true;
}

//�����ʼ��ť���õĺ���
void Home::menuStartCallback(Ref*pSender)
{
    auto sc = GameScene::createScene();
    Director::getInstance()->pushScene(sc);             //������Ϸ����
}

//������ð�ť���õĺ���
void Home::menuSetCallback(Ref*pSender)
{
    auto sc = Setting::createScene();
    Director::getInstance()->pushScene(sc);               //�������ý���
}

//���������ť���õĺ���
void Home::menuHelpCallback(Ref*pSender)
{
    
    auto sc = Help::createScene();
    Director::getInstance()->pushScene(sc);               //�����������
}
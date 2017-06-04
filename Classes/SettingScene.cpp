#include"SettingScene.h"
//#include"HomeScene.h"
#include"SimpleAudioEngine.h"

USING_NS_CC;

Scene* Setting::createScene()
{
    auto scene = Scene::create();
    auto layer = Setting::create();
    scene->addChild(layer);
    return scene;
}

bool Setting::init()
{
    if (!Layer::init())
        return false;

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto background = Sprite::create("bg.png");
    background->setPosition(Vec2::ZERO);
    background->setAnchorPoint(Vec2::ZERO);
    this->addChild(background);               //��������ͼƬ

    auto GobackItem = MenuItemImage::create(
        "menuItem/goback1.png",
        "menuItem/goback2.png",
        CC_CALLBACK_1(Setting::menuGoCallback, this));
    GobackItem->setPosition(Vec2::ZERO);            //�������ذ�ť
    GobackItem->setAnchorPoint(Vec2::ZERO);

    auto menu = Menu::create(GobackItem, NULL);
    menu->setPosition(Vec2::ZERO);
    addChild(menu, 1);

    return true;

}

//������ذ�ť���õĺ���
void Setting::menuGoCallback(Ref*pSender)
{
    Director::getInstance()->popScene();                      //�ص�home����
} 
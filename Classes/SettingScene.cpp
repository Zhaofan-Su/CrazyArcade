#include"SettingScene.h"
//#include"HomeScene.h"
#include"SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

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
    background->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
    //background->setAnchorPoint(Vec2::ZERO);
    this->addChild(background);               //��������ͼƬ

    auto GobackItem = MenuItemImage::create(
        "menuItem/goback1.png",
        "menuItem/goback2.png",
        CC_CALLBACK_1(Setting::menuGoCallback, this));
    GobackItem->setPosition(Vec2::ZERO);            //�������ذ�ť
    GobackItem->setAnchorPoint(Vec2::ZERO);

    //the sound //��������
    auto soundOnMenuItem = MenuItemImage::create(
        "SettingsScene/sound-on.png",
        "SettingsScene/sound-on.png");
    auto soundOffMenuItem = MenuItemImage::create(
        "SettingsScene/sound-off.png",
        "SettingsScene/sound-off.png");
    auto soundToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(Setting::menuSoundToggleCallback, this),
        soundOnMenuItem,
        soundOffMenuItem, NULL);
    soundToggleMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(400,400)));

    //the music //�������ֵ�����
    auto musicOnMenuItem = MenuItemImage::create(
        "SettingsScene/music-on.png",
        "SettingsScene/music-on.png");
    auto musicOffMenuItem = MenuItemImage::create(
        "SettingsScene/music-off.png",
        "SettingsScene/music-off.png");
    auto musicToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(Setting::menuMusicToggleCallback, this),
        musicOnMenuItem,
        musicOffMenuItem,
        NULL);
    musicToggleMenuItem->setPosition(Director::getInstance()->convertToGL(Vec2(400,200)));

    auto menu = Menu::create(GobackItem, soundToggleMenuItem,
        musicToggleMenuItem, NULL);
    menu->setPosition(Vec2::ZERO);
    addChild(menu, 1);

    
    //������Ч������ѡ��״̬
    UserDefault*defaults = UserDefault::getInstance();
    if (defaults->getBoolForKey("music_key"))
    {
        musicToggleMenuItem->setSelectedIndex(0);
    }
    else
    {
        musicToggleMenuItem->setSelectedIndex(1);
    }

    return true;

}

//������ذ�ť���õĺ���
void Setting::menuGoCallback(Ref*pSender)
{
    Director::getInstance()->popScene();                      //�ص�home����
    SimpleAudioEngine::getInstance()->playEffect("sound/click.wav");   //���ŵ����Ч
} 



void Setting::menuSoundToggleCallback(cocos2d::Ref * pSender)
{
    UserDefault*defaults = UserDefault::getInstance();
    if (defaults->getBoolForKey("music_key"))
    {
        defaults->setBoolForKey("music_key", false);
        SimpleAudioEngine::getInstance()->stopAllEffects();
    }
    else
    {
        defaults->setBoolForKey("music_key", true);
        SimpleAudioEngine::getInstance()->playEffect("sound/click.wav");
    }
}
void Setting::menuMusicToggleCallback(cocos2d::Ref * pSender)
{
    UserDefault*defaults = UserDefault::getInstance();
    if (defaults->getBoolForKey("music_key"))
    {
        defaults->setBoolForKey("music_key", false);
        SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    }
    else
    {
        defaults->setBoolForKey("music_key", true);
        SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/bgm.wav");
    }
}
void Setting::menuOkCallback(cocos2d::Ref * pSender)
{
    Director::getInstance()->popScene();
}
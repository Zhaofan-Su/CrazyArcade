#include "LoadingScene.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene*Loading::createScene()
{
    auto scene = Scene::create();
    auto layer = Loading::create();
    scene->addChild(layer);
    return scene;
}

bool Loading::init()
{
    if (!Layer::init())
        return false;

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //����loading������֡����
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("loading/loading_anim.plist");

    auto loading = Sprite::create("loading/loading.png");
    loading->setPosition(Vec2::ZERO);
    loading->setAnchorPoint(Vec2::ZERO);
    addChild(loading);


    ///////////////������ʼ/////////////////
    Animation*animation = Animation::create();
    for (int i = 1; i <= 3; i++)
    {
        __String*frameName = __String::createWithFormat("loading_%d.png", i);
        log("frameName=%s", frameName->getCString());
        SpriteFrame*spriteFrame = SpriteFrameCache::getInstance()->
            getSpriteFrameByName(frameName->getCString());
        animation->addSpriteFrame(spriteFrame);
    }
    
    //��������֡����ʱ��
    animation->setDelayPerUnit(0.5f);
    //����ִ�к�ԭ��ʼ״̬
    animation->setRestoreOriginalFrame(true);

    Animate*action = Animate::create(animation);
    loading->runAction(RepeatForever::create(action));
    ///////////////��������//////////////////


    //loading resources
    {
        //֡����
        auto spriteFrameCache = SpriteFrameCache::getInstance();
        
        spriteFrameCache->addSpriteFramesWithFile("hero/player1_anim.plist");

        //������
        auto textureCache = Director::getInstance()->getTextureCache();
        textureCache->addImage("first_bg.png");
        textureCache->addImage("bg.png");
        textureCache->addImage("frame.png");
        textureCache->addImage("game_exit.png");
        textureCache->addImage("CloseNormal.png");
        textureCache->addImage("CloseSelected.png");
        textureCache->addImage("SettingsScene/music-off.png");
        textureCache->addImage("SettingsScene/music-on.png");
        textureCache->addImage("SettingsScene/sound-off.png");
        textureCache->addImage("SettingsScene/sound-on.png");
        textureCache->addImage("menuItem/go1.png");
        textureCache->addImage("menuItem/go2.png");
        textureCache->addImage("menuItem/goback1.png");
        textureCache->addImage("menuItem/goback2.png");
        textureCache->addImage("menuItem/home_help_butt_1.png");
        textureCache->addImage("menuItem/home_help_butt_2.png");
        textureCache->addImage("menuItem/home_set_butt_1.png");
        textureCache->addImage("menuItem/home_set_butt_2.png");
        textureCache->addImage("menuItem/home_start_butt_1.png");
        textureCache->addImage("menuItem/home_start_butt_2.png");
        textureCache->addImage("hero/player1.png");
        textureCache->addImage("hero/player1_anim.png");

        //��������
        SimpleAudioEngine::getInstance()->preloadBackgroundMusic("sound/game_bgm.mp3");
        SimpleAudioEngine::getInstance()->preloadBackgroundMusic("sound/home_bgm.mp3");
        SimpleAudioEngine::getInstance()->preloadBackgroundMusic("sound/win.mp3");
        SimpleAudioEngine::getInstance()->preloadEffect("sound/click.wav");
    }

    //����ʱ��̫�̣�ǿ��1.5������loading����������ʾ������
    scheduleOnce(SEL_SCHEDULE(&Loading::gotoHelloScene), 1.5);

    return true;
}

void Loading::gotoHelloScene(float t)
{
    auto scene = HelloWorld::createScene();
    Director::getInstance()->replaceScene(scene);
}
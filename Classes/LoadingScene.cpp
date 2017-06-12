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

    //创建loading动画的帧缓存
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("loading/loading_anim.plist");

    auto loading = Sprite::create("loading/loading.png");
    loading->setPosition(Vec2::ZERO);
    loading->setAnchorPoint(Vec2::ZERO);
    addChild(loading);


    ///////////////动画开始/////////////////
    Animation*animation = Animation::create();
    for (int i = 1; i <= 3; i++)
    {
        __String*frameName = __String::createWithFormat("loading_%d.png", i);
        log("frameName=%s", frameName->getCString());
        SpriteFrame*spriteFrame = SpriteFrameCache::getInstance()->
            getSpriteFrameByName(frameName->getCString());
        animation->addSpriteFrame(spriteFrame);
    }
    
    //设置两个帧播放时间
    animation->setDelayPerUnit(0.5f);
    //动画执行后还原初始状态
    animation->setRestoreOriginalFrame(true);

    Animate*action = Animate::create(animation);
    loading->runAction(RepeatForever::create(action));
    ///////////////动画结束//////////////////


    //loading resources
    {
        //帧缓存
        auto spriteFrameCache = SpriteFrameCache::getInstance();
        
        spriteFrameCache->addSpriteFramesWithFile("hero/player1_anim.plist");

        //纹理缓存
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

        //加载声音
        SimpleAudioEngine::getInstance()->preloadBackgroundMusic("sound/game_bgm.mp3");
        SimpleAudioEngine::getInstance()->preloadBackgroundMusic("sound/home_bgm.mp3");
        SimpleAudioEngine::getInstance()->preloadBackgroundMusic("sound/win.mp3");
        SimpleAudioEngine::getInstance()->preloadEffect("sound/click.wav");
    }

    //加载时间太短，强制1.5秒后结束loading。。便于显示。。。
    scheduleOnce(SEL_SCHEDULE(&Loading::gotoHelloScene), 1.5);

    return true;
}

void Loading::gotoHelloScene(float t)
{
    auto scene = HelloWorld::createScene();
    Director::getInstance()->replaceScene(scene);
}
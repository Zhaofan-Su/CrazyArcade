#include"GameScene.h"
#include"HomeScene.h"
#include"MapLayer.h"
#include"SimpleAudioEngine.h"
#include"cocos2d.h" 
#include"cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d;

Scene*GameScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}                                       
bool GameScene::init()
{
    if (!Layer::init())
        return false;

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto bg = Sprite::create("frame.png");
    bg->setPosition(Vec2::ZERO);
    bg->setAnchorPoint(Vec2::ZERO);
    this->addChild(bg);                                  //将游戏场景的主界面作为背景

    auto exitItem = MenuItemImage::create(
        "game_exit.png",
        "game_exit.png",
        CC_CALLBACK_1(GameScene::menuExitcallback, this));
    exitItem->setPosition(Vec2(640, 7));
    exitItem->setAnchorPoint(Vec2::ZERO);               //设置游戏时的“退出”按钮

    auto menu = Menu::create(exitItem, NULL);            //创建菜单项
    menu->setPosition(Vec2::ZERO);
    menu->setAnchorPoint(Vec2::ZERO);
    addChild(menu, 1);                                   //将退出按钮加入到菜单项中
    
    map = TMXTiledMap::create("map/FirstMap.tmx");         //将地图引入GameScene中
    map->setPosition(Vec2(20, 40));                              //设置地图位置
    map->setAnchorPoint(Vec2::ZERO);                            //将地图锚点设置为左下角原点处
    
    TMXObjectGroup*group = map->getObjectGroup("objects");        //通过对象层名获得对象层中对象集合
    ValueMap spawnPoint = group->getObject("hero");               //通过对象名获得对象信息，返回类型ValueMap

    //float x = spawnPoint["x"].asFloat() + 20;
    //float y = spawnPoint["y"].asFloat() + 40;

    collidable = map->getLayer("collidable");                //通过层名字“collidable”创建层
    collidable->setVisible(false);
    addChild(map, 1);
   
    player1 = Hero::create();                               //创建人物
    player1->addPlayerAnimation();
    player1->addPlayer();
    //player1->setAnchorPoint(Vec2(0, 0));
    //player1->setPosition(Vec2(20, 200));
    this->addChild(player1, 2);

    //注册键盘监听器
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    setKeypadEnabled(true);
    return true;
}

//点击退出按钮之后的回调函数
void GameScene::menuExitcallback(Ref*pSender)
{
    Director::getInstance()->popScene();         //点击退出按钮后返回到home界面
}                                     

//创建地图层的函数定义
/*void GameScene::initMapLayer()
{
    MapLayer*map = MapLayer::create();            //创建地图
    this->addChild(map);                          //将地图层加入到该场景中
}*/

void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event*event)
{
	player1->Moveto(player1->getDirection(keyCode));
	player1->stopAllActions();
}

/*void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event*event)
{
    Vec2 player_pos = player1->getPosition();
    Vec2 Pos;
    if (player1->getDirection(keyCode) == UP)
    {
        Pos.x = player_pos.x;
        Pos.y = player_pos.y + 40;
        if (setPlayerPosition(player_pos) && Pos.y <= 560)
        {
            player1->Moveto(player1->getDirection(keyCode));
            player1->stopAllActions();
        }
    }
    else if (player1->getDirection(keyCode) == DOWN)
    {
        Pos.x = player_pos.x;
        Pos.y = player_pos.y - 40;
        if (setPlayerPosition(player_pos) && Pos.y >= 40)
        {
            player1->Moveto(player1->getDirection(keyCode));
            player1->stopAllActions();
        }
    }
    else if (player1->getDirection(keyCode) == LEFT)
    {
        Pos.x = player_pos.x - 40;
        Pos.y = player_pos.y;
        if (setPlayerPosition(player_pos) && Pos.x >= 20)
        {
            player1->Moveto(player1->getDirection(keyCode));
            player1->stopAllActions();
        }
    }
    else if (player1->getDirection(keyCode) == RIGHT)
    {
        Pos.x = player_pos.x + 40;
        Pos.y = player_pos.y;
        if (setPlayerPosition(player_pos) && Pos.x <= 620)
        {
            player1->Moveto(player1->getDirection(keyCode));
            player1->stopAllActions();
        }
    }
}

bool GameScene::setPlayerPosition(Vec2 position)          //若欲移动处为障碍物，则返回false
{
    //从像素坐标点转化为瓦片坐标点
    Vec2 Pos;
    Pos.x = position.x - 20;
    Pos.y = position.y - 40;
    Vec2 tileCoord;
    int x = Pos.x / 40;              //获得x轴瓦片坐标数
    int y = 12 - Pos.y / 40;                        //获得y轴瓦片坐标数
    tileCoord.x = x;
    tileCoord.y = y;

    //获得瓦片的GID
    int tileGid = collidable->getTileGIDAt(tileCoord);

    if (tileGid > 0)
    {
        Value prop = map->getPropertiesForGID(tileGid);
        ValueMap propValueMap = prop.asValueMap();

        std::string collision = propValueMap["Collidable"].asString();

        if (collision == "true")
            return false;
    }

    //player1->setPosition(position);
    return true;
}*/



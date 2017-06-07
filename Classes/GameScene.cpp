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
    this->addChild(bg);                                  //����Ϸ��������������Ϊ����

    auto exitItem = MenuItemImage::create(
        "game_exit.png",
        "game_exit.png",
        CC_CALLBACK_1(GameScene::menuExitcallback, this));
    exitItem->setPosition(Vec2(640, 7));
    exitItem->setAnchorPoint(Vec2::ZERO);               //������Ϸʱ�ġ��˳�����ť

    auto menu = Menu::create(exitItem, NULL);            //�����˵���
    menu->setPosition(Vec2::ZERO);
    menu->setAnchorPoint(Vec2::ZERO);
    addChild(menu, 1);                                   //���˳���ť���뵽�˵�����
    
    map = TMXTiledMap::create("map/FirstMap.tmx");         //����ͼ����GameScene��
    map->setPosition(Vec2(20, 40));                              //���õ�ͼλ��
    map->setAnchorPoint(Vec2::ZERO);                            //����ͼê������Ϊ���½�ԭ�㴦
    
    TMXObjectGroup*group = map->getObjectGroup("objects");        //ͨ�����������ö�����ж��󼯺�
    ValueMap spawnPoint = group->getObject("hero");               //ͨ����������ö�����Ϣ����������ValueMap

    //float x = spawnPoint["x"].asFloat() + 20;
    //float y = spawnPoint["y"].asFloat() + 40;

    collidable = map->getLayer("collidable");                //ͨ�������֡�collidable��������
    collidable->setVisible(false);
    addChild(map, 1);
   
    player1 = Hero::create();                               //��������
    player1->addPlayerAnimation();
    player1->addPlayer();
    //player1->setAnchorPoint(Vec2(0, 0));
    //player1->setPosition(Vec2(20, 200));
    this->addChild(player1, 2);

    //ע����̼�����
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    setKeypadEnabled(true);
    return true;
}

//����˳���ť֮��Ļص�����
void GameScene::menuExitcallback(Ref*pSender)
{
    Director::getInstance()->popScene();         //����˳���ť�󷵻ص�home����
}                                     

//������ͼ��ĺ�������
/*void GameScene::initMapLayer()
{
    MapLayer*map = MapLayer::create();            //������ͼ
    this->addChild(map);                          //����ͼ����뵽�ó�����
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

bool GameScene::setPlayerPosition(Vec2 position)          //�����ƶ���Ϊ�ϰ���򷵻�false
{
    //�����������ת��Ϊ��Ƭ�����
    Vec2 Pos;
    Pos.x = position.x - 20;
    Pos.y = position.y - 40;
    Vec2 tileCoord;
    int x = Pos.x / 40;              //���x����Ƭ������
    int y = 12 - Pos.y / 40;                        //���y����Ƭ������
    tileCoord.x = x;
    tileCoord.y = y;

    //�����Ƭ��GID
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



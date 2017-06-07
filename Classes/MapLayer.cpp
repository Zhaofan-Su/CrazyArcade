#include"MapLayer.h"
#include"SimpleAudioEngine.h"

USING_NS_CC;


/*bool MapLayer::init()
{
    
    map = TMXTiledMap::create("map/FirstMap.tmx");         //将地图引入GameScene中
    map->setPosition(Vec2(20,40));                              //设置地图位置
    map->setAnchorPoint(Vec2::ZERO);                            //将地图锚点设置为左下角原点处
    this->addChild(map);

    TMXObjectGroup*group = map->getObjectGroup("objects");        //通过对象层名获得对象层中对象集合
    ValueMap spawnPoint = group->getObject("hero");               //通过对象名获得对象信息，返回类型ValueMap

    player1 = Hero::create();                               //创建人物
    player1->addPlayerAnimation();
    player1->addPlayer();
    this->addChild(player1, 1);

    collidable = map->getLayer("collidable");                //通过层名字“collidable”创建层

    //注册键盘监听器
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(MapLayer::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(MapLayer::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


    return true;
}
void MapLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event*event)
{
    Vec2 player_pos = player1->getPosition();
    Vec2 Pos;
    if (player1->getDirection(keyCode) == UP)
    {
        Pos.x = player_pos.x;
        Pos.y = player_pos.y + 40;
        if (setPlayerPosition(Pos) && Pos.y <= 560)
        {
            player1->Moveto(player1->getDirection(keyCode));
            player1->stopAllActions();
        }
    }
    else if (player1->getDirection(keyCode) == DOWN)
    {
        Pos.x = player_pos.x;
        Pos.y = player_pos.y - 40;
        if (setPlayerPosition(Pos) && Pos.y >= 40)
        {
            player1->Moveto(player1->getDirection(keyCode));
            player1->stopAllActions();
        }
    }
    else if (player1->getDirection(keyCode) == LEFT)
    {
        Pos.x = player_pos.x - 40;
        Pos.y = player_pos.y;
        if (setPlayerPosition(Pos) && Pos.x >= 20)
        {
            player1->Moveto(player1->getDirection(keyCode));
            player1->stopAllActions();
        }
    }
    else if (player1->getDirection(keyCode) == RIGHT)
    {
        Pos.x = player_pos.x + 40;
        Pos.y = player_pos.y;
        if (setPlayerPosition(Pos) && Pos.x <= 620)
        {
            player1->Moveto(player1->getDirection(keyCode));
            player1->stopAllActions();
        }
    }
}

bool MapLayer::setPlayerPosition(Vec2 position)          //若欲移动处为障碍物，则返回false
{
    //从像素坐标点转化为瓦片坐标点
    Vec2 Pos;
    Pos.x = position.x - 20;
    Pos.y = position.y - 40;
    Vec2 tileCoord = this->tileCoordFromPosition(Pos);

    //获得瓦片的GID
    int tileGid = collidable->getTileGIDAt(tileCoord);

    if (tileGid > 0)
    {
        Value prop = map->getPropertiesForGID(tileGid);
        ValueMap propValueMap = prop.asValueMap();

        std::string collision = propValueMap["collidable"].asString();

        if (collision == "true")
            return false;
    }
    
    //player1->setPosition(position);
    return true;
}

Vec2 MapLayer::tileCoordFromPosition(Vec2 pos)
{
    int x = pos.x / map->getTileSize().width;               //获得x轴瓦片坐标数
    int y = ((520 * map->getTileSize().height) - pos.y) /
        map->getTileSize().height;                          //获得y轴瓦片坐标数

    return Vec2(x, y);
}*/